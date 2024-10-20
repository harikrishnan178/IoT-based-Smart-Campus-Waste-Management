# IoT-Based Smart Campus Waste Management System
This project implements an IoT-based Smart Waste Management System for a campus using an ESP32 microcontroller. It monitors the waste levels in bins and environmental conditions like moisture and temperature using sensors and communicates with a Blynk IoT dashboard for real-time tracking.
# Features
Waste Level Monitoring: Ultrasonic sensor measures the fill level of the waste bins.
Environmental Monitoring: Moisture sensor checks the humidity in the bins, and the temperature sensor tracks the ambient temperature.
IoT Integration: Uses the Blynk IoT platform to display real-time data and notifications on a user-friendly dashboard.
ESP32: Acts as the core controller, collecting sensor data and transmitting it to the Blynk cloud.
# Components Used
ESP32: Microcontroller to control the sensors and connect to the Blynk IoT platform.
Ultrasonic Sensor (HC-SR04): For detecting the waste fill level in bins.
Moisture Sensor: To measure humidity in the waste bins.
Temperature Sensor (DHT11/DHT22): For measuring ambient temperature.
Blynk IoT Dashboard: Provides real-time monitoring of bin status and environmental conditions.
# How It Works
The Ultrasonic Sensor measures the distance from the sensor to the waste in the bin, determining the fill level.
The Moisture Sensor monitors the moisture level inside the waste bin.
The Temperature Sensor records the ambient temperature near the waste bin.
The data from these sensors is transmitted to the ESP32, which then sends it to the Blynk cloud.
Users can monitor the fill level, moisture, and temperature on the Blynk IoT dashboard, receive alerts, and track the status of each bin.
# Software Requirements
Arduino IDE: For programming the ESP32.
Blynk Library: For connecting the ESP32 to the Blynk IoT platform.
ESP32 Board Package: For setting up the ESP32 in the Arduino IDE.
# Setup Instructions
Circuit Assembly:

![msedge_DSJQKprqkr](https://github.com/user-attachments/assets/bd1a7b7e-6e39-418e-adf2-1b9a12c8a937)


Connect the Ultrasonic Sensor's VCC and GND to the ESP32's 3.3V and GND pins, and the trigger and echo pins to digital pins.
Connect the Moisture Sensor and Temperature Sensor to the ESP32.
Blynk Setup:

Create a new project in the Blynk app, selecting ESP32 as the device.
Add widgets (e.g., value displays, notifications) for the ultrasonic sensor, moisture sensor, and temperature sensor data.
Copy the Auth Token from Blynk to use in your code.
Programming:

Install the required libraries in the Arduino IDE (Blynk, DHT, etc.).
Upload the code to the ESP32 after setting the correct Wi-Fi credentials and Blynk Auth Token.
Monitoring:

View the real-time data on the Blynk dashboard.
Set up alerts for when bins are full or environmental conditions exceed a set threshold.

![msedge_MJUWZ9R388](https://github.com/user-attachments/assets/a4c42026-5921-4dcb-8cb7-58f5bfc41be1)


# Applications
Smart waste management in campuses, public spaces, and corporate buildings.
Efficient waste collection by monitoring bin levels and notifying staff when bins are full.
