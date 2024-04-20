import cv2
import numpy as np
import urllib.request
from keras.models import load_model
import serial

# Load the trained model
model = load_model('keras_model.h5')

# Open serial port
ser = serial.Serial('COM9', 9600)  # Adjust 'COMx' according to your ESP32-CAM's serial port

# URL of the ESP32-CAM web server
url = 'http://192.168.168.25/capture'

while True:
    try:
        # Read the image from the URL
        img_resp = urllib.request.urlopen(url)
        img_np = np.array(bytearray(img_resp.read()), dtype=np.uint8)
        frame = cv2.imdecode(img_np, -1)
        
        # Display the frame
        cv2.imshow('Ambulance Detection', frame)

        # Preprocess the frame
        resized_frame = cv2.resize(frame, (224, 224))  # Adjust the input size as per your model's requirements
        resized_frame = resized_frame.astype('float32') / 255.0  # Normalize pixel values
        input_data = np.expand_dims(resized_frame, axis=0)  # Add batch dimension

        # Predict using the model
        prediction = model.predict(input_data)
        

        # Assuming your model outputs a binary classification result
        if prediction[0][0] > 0.5:  # Adjust threshold as per your model's output
            # Ambulance detected, send emergency signal to Arduino
            cv2.rectangle(frame, (0, 0), (frame.shape[1], frame.shape[0]), (0, 255, 0), 2)
            cv2.putText(frame, 'Ambulance Detected', (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
            
            ser.write(b'E')
            print("Ambulance Detected, Emergency Signal Activated!")
            
        
        else:
            # Send non-emergency signal to Arduino
            ser.write(b'N')
            # Check for the 'q' key to quit
        

    except Exception as e:
        print("Error:", e)
        pass
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
# Close all windows
cv2.destroyAllWindows()
