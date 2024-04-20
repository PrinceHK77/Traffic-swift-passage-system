import cv2
import numpy as np
import urllib.request
from keras.models import load_model
import serial
import time

# Load the trained model
model = load_model('keras_model.h5')

# Open serial port
ser = serial.Serial('COM9', 9600)  # Adjust 'COMx' according to your ESP32-CAM's serial port

# URL of the ESP32-CAM web server
url = 'http://192.168.168.25/capture'

# Initialize detection status and timestamp
detection_flag = False
last_detection_time = time.time()
last_emergency_time = last_detection_time  # Initialize last emergency signal time with the current time

while True:
    try:
        # Read the image from the URL
        img_resp = urllib.request.urlopen(url)
        img_np = np.array(bytearray(img_resp.read()), dtype=np.uint8)
        frame = cv2.imdecode(img_np, -1)

        # Preprocess the frame
        resized_frame = cv2.resize(frame, (224, 224))  # Adjust the input size as per your model's requirements
        resized_frame = resized_frame.astype('float32') / 255.0  # Normalize pixel values
        input_data = np.expand_dims(resized_frame, axis=0)  # Add batch dimension

        # Predict using the model
        prediction = model.predict(input_data)

        # Assuming your model outputs a binary classification result
        if prediction[0][0] > 0.5:  
            cv2.rectangle(frame, (0, 0), (frame.shape[1], frame.shape[0]), (0, 255, 0), 2)
            cv2.putText(frame, 'Ambulance Detected', (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            # Ambulance detected, check if it's been 20 seconds since the last emergency signal
            current_time = time.time()
            if current_time - last_emergency_time >= 20:
                # It's been 20 seconds, send emergency signal to Arduino
                ser.write(b'E')
                last_emergency_time = current_time
                # Update detection flag only after sending the emergency signal
                detection_flag = True
                last_detection_time = current_time  # Update the last detection time
        else:
            # If previously detected, send normal signal to Arduino
            if detection_flag:
                ser.write(b'N')
                # Reset the detection flag if it was previously set
                detection_flag = False

        # Display the frame
        cv2.imshow('Ambulance Detection', frame)

        # Check for the 'q' key to quit
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    except Exception as e:
        print("Error:", e)
        # Handle the error gracefully, you can add logging or other error handling mechanisms here
        # Optionally, you can add a delay before retrying to fetch the image
        time.sleep(1)

# Release the video capture object and close all windows
cv2.destroyAllWindows()
