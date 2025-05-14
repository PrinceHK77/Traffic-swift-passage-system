# 🚦 Traffic Signal Swift Passage System

![image](https://github.com/user-attachments/assets/e07b349d-761b-4ca4-a3ef-1652ab38701b)


An AI-driven system designed to give emergency vehicles priority access at intersections by dynamically adjusting traffic signals using Computer Vision and IoT. This system ensures seamless and swift passage of ambulances, fire trucks, and police vehicles — reducing delays and saving lives.

---

## 🌐 Project Overview

Traditional traffic lights follow fixed cycles, which can delay emergency response during peak hours. This system solves that by:

- 🧠 Detecting emergency vehicles in real-time via a live video feed
- ⚙️ Automatically adjusting the traffic signal to green
- 🌍 Leveraging IoT controllers for live signal manipulation
- 🖥️ Providing a web dashboard interface for visualization and monitoring

---

## 💡 Key Features

✅ Real-time Emergency Vehicle Detection using CV & ML  
🔄 Dynamic Traffic Light Control using IoT  
📶 Sensor Communication for Smart Signal Coordination  
🧠 Custom ML Model for Emergency Vehicle Classification  
🕹️ Flask-based Web Interface for Monitoring & Logs  
⏱️ Reduced Congestion & Improved Emergency Response Time  

---

## 🧰 Technologies Used

| Domain             | Tech Stack                         |
|--------------------|-------------------------------------|
| Computer Vision     | OpenCV                             |
| Machine Learning    | TensorFlow / Keras / Scikit-learn  |
| IoT Communication   | MQTT / Wi-Fi Sensors / Arduino     |
| Web Interface       | Flask, HTML, CSS, JS               |
| Programming Language| Python                             |

---

## 🧭 System Architecture

```plaintext
📹 Live Camera Feed
     ↓
🔍 Emergency Vehicle Detection (CV + ML)
     ↓
✅ Detected → 🟢 Green Light on Lane
❌ Not Detected → 🔴 Maintain Default Cycle
     ↓
🌐 IoT Controller Adjusts Signal
     ↓
📊 Web Dashboard via Flask

