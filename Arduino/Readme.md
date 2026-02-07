# Embedded Hardware Labs (Arduino & ESP32)

This repository contains a structured collection of Arduino and ESP32 embedded system projects, including learning experiments, hardware tests, and small system-level implementations.

The goal of this repository is to maintain a clean separation between:
-  Experiments / tests 
-  Reusable project modules 
-  Archived development files 

---

## 📁 Repository Structure

### 🔹 TEST/
Contains  learning-oriented and experimental sketches  used to understand individual components and peripherals.

Examples:
- LED blink and button tests  
- Servo motor tests and variations  
- ESP32 and WiFi experiments  
- Camera and SD card tests  
- Load sensor tests  

These projects are not production-ready but document the learning and validation process.

---

### 🔹 Core Project Folders
These folders represent  standalone functional modules or small systems :

-  BMPsensor/  – Sensor interfacing and data acquisition  
-  fan_initial/  – Basic fan control experiments  
-  fan_motor/  – Motor and fan control logic  
-  fan_page/  – Fan control with UI / web-based interface  
-  led3push/  – Multi-input LED control logic  
-  send_27/  – Transmitter-side embedded communication logic  
-  receive_27/  – Receiver-side embedded communication logic  

Each folder contains a self-contained Arduino sketch with related logic.

---

### 🔹 project_files/
This folder contains  archived or intermediate development work , such as:
- Auto-generated Arduino sketches  
- Merged or transitional code versions  

These are kept for reference and traceability but are  not meant for direct reuse .


##  Hardware & Platforms Used
- Arduino Uno / compatible boards  
- ESP32  
- Servo motors (e.g., MG996R)  
- DC motors and fans  
- Sensors (load cell, BMP, etc.)  
- Camera modules  
- External power supplies  


##  Development Environment
- Arduino IDE  
- ESP32 Arduino Core  
- Serial debugging and PWM-based control  
- Modular folder-based sketch organization  


##  Notes
- Auto-generated build files and IDE metadata are excluded using `.gitignore`.
- Large or sensitive standalone projects (e.g., institutional or confidential work) are maintained separately.
- This repository focuses on  embedded fundamentals, hardware–software integration, and iterative development .

##  Future Improvements
- FSM-based motor control implementations  
- Improved documentation and diagrams  
- Refactoring selected projects into standalone repositories  
- ESP32-based IoT extensions  


## SURAJ
Embedded systems enthusiast working with  Arduino and ESP32 , focusing on motor control, wireless communication, sensors, and hardware-level experimentation.
