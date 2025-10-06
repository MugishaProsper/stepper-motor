# Stepper Motor Control with Arduino

This project demonstrates how to control a 28BYJ-48 stepper motor using an Arduino board. The motor can be controlled through the Serial Monitor by sending rotation commands.

## Hardware Requirements

- Arduino board (Uno, Nano, or similar)
- 28BYJ-48 Stepper Motor with ULN2003 Driver Board
- Jumper wires
- 5V power supply (or USB power from computer)

## Wiring Guide

Connect the stepper motor to the Arduino as follows:

| ULN2003 Driver | Arduino |
|----------------|---------|
| IN1            | D8      |
| IN2            | D10     |
| IN3            | D9      |
| IN4            | D11     |
| + (5V)         | 5V      |
| - (GND)        | GND     |

**Note:** For better performance with larger loads, power the motor driver board using an external 5V power supply instead of the Arduino's 5V pin.

## Installation

1. Connect your Arduino to your computer via USB
2. Open the Arduino IDE
3. Install the Arduino Stepper library (usually included with the Arduino IDE)
4. Open the `StepperMotor.ino` file
5. Select the correct board and port from the Tools menu
6. Upload the sketch to your Arduino

## Usage

1. Open the Serial Monitor (Ctrl+Shift+M or Tools > Serial Monitor)
2. Set the baud rate to 9600
3. Send commands in the following format:
   - `rotate [angle]` - Rotate the motor by the specified angle in degrees
     - Positive values rotate clockwise
     - Negative values rotate counterclockwise

### Examples
- `rotate 90` - Rotate 90 degrees clockwise
- `rotate -180` - Rotate 180 degrees counterclockwise
- `rotate 360` - Make one full rotation clockwise

## Troubleshooting

- **Motor not moving?**
  - Check all connections
  - Ensure the motor is properly powered
  - Verify the correct baud rate (9600) is selected in the Serial Monitor

- **Jumpy or inconsistent movement?**
  - Try reducing the motor speed (modify `myStepper.setSpeed(10);` in `setup()`)
  - Ensure the motor is not overloaded

## Customization

You can modify these parameters in the code:
- `stepsPerRevolution`: Change if using a different stepper motor (2048 for 28BYJ-48)
- `myStepper.setSpeed(10)`: Adjust the speed (RPM) of the motor
- Pins can be changed in the Stepper initialization

## License

This project is open source and available under the MIT License.