#include <Servo.h>

Servo testServo;

void setup() {
  testServo.attach(7);   // Signal wire on D7
}

void loop() {
  // Move to 0°
  testServo.write(0);
  delay(1000);

  // Move to 90°
  testServo.write(90);
  delay(1000);

  // Move to 180°
  testServo.write(180);
  delay(1000);
}
