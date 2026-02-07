#include <Servo.h>

Servo myServo;

void setup() {
  myServo.attach(9);   // Signal wire connected to D9
}

void loop() {

  // 0 → 180 degree
  for (int angle = 0; angle <= 90; angle++) {
    myServo.write(angle);
    delay(3);
  }

  delay(1000); // hold at 90



  for (int angle = 90; angle <= 1800; angle++) {
    myServo.write(angle);
    delay(1);
  }

  delay(1000); // hold at 90




  // 180 → 0 degree
  for (int angle = 180; angle >= 0; angle--) {
    myServo.write(angle);
    delay(1);
  }

  delay(1000); // hold at 0°
}