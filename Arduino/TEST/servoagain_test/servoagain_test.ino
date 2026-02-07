#include <Servo.h>

Servo testServo;

void setup() {
  Serial.begin(9600);
  Serial.println("SETUP STARTED");

  testServo.attach(6);
  Serial.println("Servo attached to pin 9");

  testServo.write(90);
  Serial.println("Servo moved to 90 degrees (SETUP)");

  delay(2000);
  Serial.println("SETUP COMPLETED");
}

void loop() {
  Serial.println("LOOP START");

  Serial.println("Moving servo to 0 deg");
  testServo.write(0);
  delay(2000);

  Serial.println("Moving servo to 90 deg");
  testServo.write(90);
  delay(2000);

  Serial.println("Moving servo to 150 deg");
  testServo.write(150);
  delay(2000);

  Serial.println("LOOP END");
}
