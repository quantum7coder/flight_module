Drone Imaging and Disaster Management Drone

A camera-integrated autonomous drone system leveraging computer vision, geospatial analytics, and embedded control for real-time disaster monitoring and assessment.
This project combines OpenCV-based object detection, image mapping, and autonomous flight control via ESP32/Arduino flight controllers, aiming to assist in search-and-rescue, damage estimation, and terrain mapping during disaster scenarios.

System Overview

The Drone Imaging and Disaster Management System fuses real-time visual analytics with embedded flight control for intelligent aerial operations.

The onboard camera module captures and streams live imagery for object recognition, fire/smoke detection, or flood boundary identification.

The ground control module (Python + OpenCV) processes image data, detects key regions, and transmits control signals to the ESP32/Flight Controller.

Integrated GPS and IMU sensors provide spatial awareness, enabling geo-tagged mapping and autonomous path planning.

Manual override via the Dabble app or RC controller ensures safety and hybrid operation.

Hardware and Software Components
Component	Description
ESP32 / Arduino Flight Controller	Handles PWM motor control, telemetry, and sensor integration.
Brushless Motors + ESCs	Core propulsion units for lift and maneuvering.
Drone Frame + Propellers	Lightweight carbon-fiber or nylon structure for flight stability.
GPS Module (NEO-6M)	Enables geolocation tracking and waypoint navigation.
IMU (MPU6050)	Provides orientation and motion sensing.
Camera Module (ESP32-CAM / Pi Camera)	Captures aerial imagery for visual analytics.
Python (OpenCV + TensorFlow Lite / YOLO)	Performs object detection, fire/flood segmentation, and scene understanding.
Bluetooth / Wi-Fi Communication	Enables data streaming between drone and ground station.
Dabble App / RC Controller	Provides manual override and control interface.
Setup and Installation
1. Flight Controller Setup

Board Manager Version: ESP32 by Espressif Systems v2.0.17 (recommended for stability)

Arduino Libraries Used:

ESP32Servo v3.0.7

DabbleESP32 v1.5.1

TinyGPS++ v1.0.3

MPU6050 v0.6

Upload the firmware (Drone_Imaging_Controller.ino) to your ESP32/Arduino.
Ensure the motors are calibrated before the first flight.

2. Vision Module Setup (Python)

Recommended Python Version: 3.11
Install the following dependencies:

pip install -r requirements.txt


requirements.txt

opencv-python==4.11.0.86
cvzone==1.6.1
pyserial==3.5
tensorflow-lite==2.11.0
geopy==2.3.0


Note:

cvzone automatically installs MediaPipe dependencies.

TensorFlow Lite is used for lightweight edge inference.

Use a compatible USB or Bluetooth COM port for ESP32 connection.

3. Communication Setup

Pair your ESP32/Drone module with the ground PC over Bluetooth or Wi-Fi serial.

Verify the connection port (Windows: COMx / Linux: /dev/ttyUSB0).

Launch the Python imaging script (drone_imaging.py) to start camera feed and control linkage.

The drone responds to detection-based triggers — e.g., hover over region of interest, capture image, or mark coordinates.

System Workflow

The onboard camera streams live video frames to the Python ground module.

Computer vision algorithms (OpenCV/TensorFlow Lite) detect critical features — e.g., fire, debris, humans, or flood zones.

Detected regions are geo-tagged using GPS coordinates.

The ESP32 controller adjusts flight behavior (hover, move, capture) accordingly.

The ground dashboard visualizes detections, logs data, and allows manual intervention.

Demonstration

Below are sample operational visuals from the drone module.

		

	
	
Autonomous hover with real-time feed	Fire zone detection and coordinate tagging	

	
	
Flood-affected area segmentation	Victim detection and position lock-on	
Directory Structure
Drone-Imaging-Disaster-Management/
│
├── drone_imaging.py                 # Vision + AI-based detection module
├── gps_mapping.py                   # Geo-tagging and mapping utility
├── Drone_Imaging_Controller/
│   └── Drone_Imaging_Controller.ino # Main flight control firmware
├── models/
│   ├── fire_detection.tflite        # TensorFlow Lite model for fire/smoke detection
│   ├── human_detection.tflite       # Human/object detection model
├── images/                          # Demo output images
└── README.md

Known Version Issues

ESP32 board version > 2.0.17 may break Dabble compatibility.

Python ≥ 3.12 can cause dependency errors with cvzone and mediapipe.

GPS serial conflicts may occur when using Bluetooth simultaneously — reassign serial ports manually.

Ensure motor ESC calibration before first power-on to avoid startup surges.

Future Enhancements

🧠 AI-based Disaster Classification: Integrate CNNs for fire, flood, and debris-type classification.

🌍 Real-time Mapping Dashboard: Develop a web dashboard (Flask + LeafletJS) for live GPS plotting.

📡 Edge AI Deployment: Shift detection to onboard processing (ESP32-CAM / Jetson Nano).

🛰️ Drone Swarm Coordination: Multi-drone cooperation for large-scale disaster mapping.

⚙️ Autonomous Path Planning: Implement obstacle avoidance using LIDAR or depth sensors.

🧾 Data Archiving: Automatic upload of geotagged images to a cloud database (Firebase/AWS S3).

🔋 Battery and Telemetry Monitoring: Real-time drone health diagnostics with alerts.
