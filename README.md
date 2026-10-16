# Arduino Robotic Arm

A joystick-controlled robotic arm built using an Arduino UNO R4 Minima, two servo motors, a stepper motor and an OLED display.

This project was built to explore motor control, joystick interfacing and integrating electronic components into a single working system.

## Components Used

- Arduino UNO R4 Minima
- 2 Servo Motors
- Stepper Motor (2048 steps per revolution configured in code)
- Stepper Motor Driver
- Joystick Module
- SSD1306 OLED Display (128×64 I2C)
- Buzzer
- Breadboard and Jumper Wires

## Features

- **Stepper Motor Control:** Moving the joystick along the X-axis rotates the stepper motor in either direction.
- **Servo Motor Control:** Moving the joystick along the Y-axis adjusts the angle of the selected servo motor.
- **Motor Selection:** Pressing the joystick button switches between the two servo motors.
- **OLED Display:** The OLED displays a face with an eye that changes position depending on which servo motor is selected. Direction indicators are also displayed during stepper movement.
- **Buzzer Feedback:** A short beep is produced whenever the joystick button is pressed.

## Pin Connections

| Component | Arduino Pin |
|---|---|
| Stepper Motor Driver IN1 | D8 |
| Stepper Motor Driver IN2 | D10 |
| Stepper Motor Driver IN3 | D9 |
| Stepper Motor Driver IN4 | D11 |
| Servo Motor 1 | D3 |
| Servo Motor 2 | D5 |
| Joystick X-axis | A2 |
| Joystick Y-axis | A3 |
| Joystick Button | D7 |
| Buzzer | D13 |
| OLED SDA | SDA |
| OLED SCL | SCL |

The OLED uses I2C address `0x3C`.

## Working Principle

1. The Arduino continuously reads the joystick's X-axis and Y-axis values.
2. When the X-axis reading crosses a threshold, the stepper motor rotates in the corresponding direction.
3. The Y-axis controls the angle of one servo motor at a time.
4. Pressing the joystick button switches between the two servo motors.
5. The OLED display indicates the selected motor through the position of an eye.
