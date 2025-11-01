
# Drone Imaging and Disaster Management Drone

A **camera-integrated Arduino-based autonomous drone system** combining **computer vision**, **embedded motor control**, and **geospatial data processing** for **real-time disaster monitoring and damage assessment**.  
The project integrates **OpenCV-based image analytics** with **Arduino Uno flight control**, enabling low-cost aerial imaging and semi-autonomous navigation for emergency response and terrain analysis.

---

## 🧭 Abstract and Project Aim

In disaster-affected zones, rapid assessment is essential for effective relief operations.  
This project aims to develop a **vision-assisted drone system** that can detect, analyze, and map disaster-prone regions such as **fires**, **floods**, or **collapsed structures**.  
Using a **Python-based computer vision module** for real-time object detection and an **Arduino Uno–controlled quadcopter** for flight operations, the system offers **aerial imaging, data visualization**, and **autonomous control support** for rescue missions.

---

## ⚙️ System Overview

The **Drone Imaging and Disaster Management Drone** integrates a **ground-based image processing unit** with an **Arduino Uno–driven aerial platform**.
- The **onboard camera** captures live video streams that are analyzed using **OpenCV** and **TensorFlow Lite** for hazard detection (e.g., fire, smoke, human figures).
- The **Arduino Uno**, interfaced through **serial communication**, controls the drone’s motors via a **motor driver or ESCs**.
- **GPS** and **IMU (MPU6050)** sensors provide location, orientation, and stability feedback.
- The system allows both **autonomous and manual override** via a **remote controller or serial commands**.

---

## 🧩 Hardware and Software Components

| Component | Description |
|------------|-------------|
| **Arduino Uno** | Core flight controller managing motor control and sensor interfacing. |
| **Brushless Motors + ESCs / Motor Driver** | Provides propulsion and directional thrust. |
| **Drone Frame + Propellers** | Aerodynamic frame supporting motors and sensors. |
| **GPS Module (NEO-6M)** | Enables location tracking and coordinate mapping. |
| **IMU (MPU6050)** | Provides accelerometer and gyroscope readings for stabilization. |
| **Camera (USB / Pi Camera)** | Captures live video feed for vision-based detection. |
| **Python (OpenCV + TensorFlow Lite)** | Handles object detection, mapping, and serial communication. |
| **Serial USB Connection** | Data link between PC (vision module) and Arduino Uno. |
| **RC Transmitter / Joystick** | Optional manual override for pilot control. |

---

## 🧰 Setup and Installation

### 1. Arduino Environment Setup
- **Board:** Arduino Uno  
- **Port:** Select your Arduino COM port in the IDE.  
- **Required Libraries:**
  - `Servo.h`
  - `TinyGPS++`
  - `MPU6050`
  - `SoftwareSerial`

Upload the firmware `Drone_Uno_Controller.ino` to your Arduino Uno.  
Ensure all motor connections and ESC calibrations are properly configured.

---

### 2. Python Vision Module Setup
**Recommended Python Version:** `3.11`  
=======
>>>>>>> 00a04439bc28c7acffd395989091fd31dac0cff7

Install required dependencies:
```bash
pip install -r requirements.txt
