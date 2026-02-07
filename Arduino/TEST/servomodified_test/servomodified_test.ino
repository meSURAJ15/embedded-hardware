#include <ESP32Servo.h>

Servo myServo;

const int servoPin = 18;   // Any PWM-capable GPIO (18 is safe)

void setup() {
  myServo.setPeriodHertz(50);      // Standard servo frequency (50 Hz)
  myServo.attach(servoPin, 500, 2400); 
  // 500–2400 µs works for most servos (MG996R, SG90, etc.)
}

void loop() {
  myServo.write(0);
  delay(1000);

  myServo.write(90);
  delay(1000);

  myServo.write(180);
  delay(1000);
}
