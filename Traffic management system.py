import cv2
from keras.models import load_model
import numpy as np

# Load the trained model
model = load_model('keras_model.h5')

# Open a video file or captupipre device (0 for webcam)
cap = cv2.VideoCapture('video1.mp4')

while True:
    # Read a frame from the video
    ret, frame = cap.read()
    if not ret:
        break

    # Preprocess the frame
    resized_frame = cv2.resize(frame, (224, 224))  # Adjust the input size as per your model's requirements
    resized_frame = resized_frame.astype('float32') / 255.0  # Normalize pixel values
    input_data = np.expand_dims(resized_frame, axis=0)  # Add batch dimension

    # Predict using the model
    prediction = model.predict(input_data)

    # Assuming your model outputs a binary classification result
    if prediction[0][0] > 0.5:  # Adjust threshold as per your model's output
        # Ambulance detected, draw a bounding box
        cv2.rectangle(frame, (0, 0), (frame.shape[1], frame.shape[0]), (0, 255, 0), 2)
        cv2.putText(frame, 'Ambulance Detected', (50, 50), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

    # Display the frame
    cv2.imshow('Ambulance Detection', frame)

    # Check for the 'q' key to quit
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the video capture object and close all windows
cap.release()
cv2.destroyAllWindows()
