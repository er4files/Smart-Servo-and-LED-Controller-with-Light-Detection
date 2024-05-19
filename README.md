# Smart Servo and LED Controller with Light Detection

## Description

The "Smart Servo and LED Controller with Light Detection" project is an innovative system that uses an ESP32 microcontroller to control a servo motor and an LED based on ambient light levels and user commands. This project demonstrates how to integrate various components and sensors to create a responsive and interactive setup.

## Features

- **Light Detection**:
  - Measures ambient light levels using a Light Dependent Resistor (LDR).
  - Automatically controls an LED based on light intensity (bright or dark).

- **Servo Motor Control**:
  - Allows user control of a servo motor via serial commands (`servo: on` and `servo: off`).
  - Opens the servo for 3 seconds upon receiving the `servo: on` command, then automatically closes.

- **User Feedback**:
  - Real-time feedback displayed in the serial monitor:
    - LDR value
    - Light condition (bright or dark)
    - LED state (on or off)
    - Servo state (on or off)

## Components Used

- **ESP32 Microcontroller**
- **Light Dependent Resistor (LDR)**
- **Servo Motor**
- **LED**

## Applications

- **Home Automation**
- **Security Systems**
- **Educational Projects**

## Setup

1. Connect the LDR to pin `2`, the LED to pin `5`, and the servo motor to pin `18`.
2. Upload the provided Arduino sketch to the ESP32 board.
3. Open the serial monitor to view real-time feedback.

## Usage

1. Observe the LED turning on in dark conditions and off in bright conditions.
2. Send serial commands (`servo: on` and `servo: off`) to control the servo motor.
