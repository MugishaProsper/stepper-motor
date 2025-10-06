#include <Stepper.h>
const int stepsPerRevolution = 2048;  // 28BYJ-48 full rotation steps
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
String inputString = "";
boolean stringComplete = false;
void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(10);
  Serial.println("Enter command (example: rotate 180 or rotate -270):");
}
void loop() {
  if (stringComplete) {
    inputString.trim();  // Remove whitespaces
    if (inputString.startsWith("rotate")) {
      int spaceIndex = inputString.indexOf(' ');
      if (spaceIndex > 0) {
        int angle = inputString.substring(spaceIndex + 1).toInt();
        Serial.print("Rotating ");
        Serial.print(angle);
        Serial.println(" degrees...");
        long steps = (long)(angle * (stepsPerRevolution / 360.0)); // Convert degrees to steps
        myStepper.step(steps); // Rotate motor
        Serial.println("Rotation complete.");
      }
    } else {
      Serial.println("Invalid command. Use: rotate <angle>");
    }
    inputString = "";
    stringComplete = false;
  }
}
void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}