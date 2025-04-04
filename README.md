# ESP32_Team_Task_2: Theoretical Assignment and Tasks 1 & 2
Overview
This repository contains two projects: a theoretical assignment and two practical tasks that use the ESP32 development board. The theoretical assignment focuses on understanding key concepts in electronics and sensor applications, while Task 1 and Task 2 involve designing and implementing systems using the ESP32.

Folder Structure
ESP32_Team_Task_2/
├── Theoretical_Assignment/
│   ├── Theoretical_Assignment.docx
├── Task_1_Bar_Graph/
│   ├── Task_1_Bar_Graph
|   | Bar graph report.docx
|   |Bar_Graph.cpp
|   |Bar_Graph_Simulation.mp4
|   |Circuit_Diagram.png
|   |Demo_Video.mp4
├── Task_2_Smart_Lock/  
Circuit_Diagram.png
Demo_Video.mp4
Smart_Lock.cpp
Smart_Lock_Report.docx
Smart_Lock_Simulation.mp4
└── README.md
Theoretical Assignment
1. Comparison of Digital and Analog Signals
In this section, the differences between digital and analog signals are outlined.

3. Principle Behind IR Sensor Operation
An IR sensor works by emitting infrared light and detecting the reflection of this light when it encounters an object. The sensor detects changes in the intensity of the reflected light, which can be used to determine the presence or absence of an object.

4. PWM Generation on ESP32
Pulse Width Modulation (PWM) signals can be generated using the ESP32 by configuring the timer and output pins. Key factors to consider include the frequency and duty cycle of the PWM signal, as well as the resolution of the timer and pin capabilities.

Task 1: Bar Graph System
Overview
This task involves designing an ESP32-based system with the following components:

Bar Graph Display: A series of LEDs to visually represent a range of values.

Push Button-Controlled LED: A push button that controls an LED.

LDR Light Sensor: A sensor to detect ambient light levels.

Buzzer and LEDs : Indicate high or low light levels.

Key Features
Bar Graph Display: The LEDs light up sequentially based on ambient light levels detected by the LDR sensor. A function maps the sensor input to the LED bar graph.

User Interaction: The push button allows the user to control an LED as part of the system.

Bonus: Simulation and Schematic
TinkerCAD Simulation: The project is simulated in TinkerCAD to visualize how the system works avaialable as a video (Smart_Lock_Simulation.mp4)

Fritzing Circuit Schematic: A circuit schematic is provided to show how the components are connected.

Code
The Arduino code for the ESP32 is located in the Code folder (Bar_Graph.cpp).

Circuit Schematic
The circuit schematic for Task 1 is available as (Circuit_Diagram.png).

Task 2: Smart Lock System
Overview
This task involves creating an automatic Smart Lock system using the ESP32, an analog IR sensor, and a servo motor. The system detects a person using the IR sensor and controls the servo motor to open and close the door.

Key Features
Servo Motor Control: The servo motor rotates from 0° to 180° to open the door and back to 0° to close it.

IR Sensor: Detects the presence of a person and triggers the servo motor to open or close the door based on the sensor input.

Automatic Closing: The door closes automatically after a specified time if no person is detected.

Bonus: Simulation and Schematic
TinkerCAD Simulation: The project is simulated in TinkerCAD to ensure proper functionality available as a video (Bar_Graph_Simulation.mp4)

Fritzing Circuit Schematic: The schematic diagram of the Smart Lock system is available as (Circuit_Diagram).

Code
The Arduino code for the Smart Lock system is located in the Code folder (Smart_Lock.cpp).

Circuit Schematic
The circuit schematic for Task 2 is available in Fritzing format (Circuit_Diagram.png).
