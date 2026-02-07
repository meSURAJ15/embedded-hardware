#include <Servo.h>
// ===== PIN CONFIG =====
const int fanPWM   = 9;   // Fan blue wire
const int servoPin = 6;   // MG996R signal

// ===== TIMING (milliseconds) =====
const unsigned long FAN_ON_TIME  = 1000;
const unsigned long FAN_OFF_TIME = 5000;

// ===== FAN SPEED =====
const int FAN_SPEED = 200;  // 0–255

// ===== SERVO =====
Servo pageServo;

// ===== COUNTER =====
unsigned long runCount = 0;

void setup() {
  pinMode(fanPWM, OUTPUT);

  pageServo.attach(servoPin);
  pageServo.write(0);   // start position

  Serial.begin(9600);
  Serial.println("Fan + Servo sequence started");
}

void loop() {

  // 1️⃣ Fan ON
  analogWrite(fanPWM, FAN_SPEED);

  // 2️⃣ Wait 0.5 s after fan start
  delay(500);

  // 3️⃣ Servo: 0° → 90°
  pageServo.write(90);
  delay(500);   // stop for 0.5 s

  // 4️⃣ Servo: 90° → 180°
  pageServo.write(180);
  delay(1000);  // stop for 1 s

  // 5️⃣ Servo: 180° → 0°
  pageServo.write(0);

  // 6️⃣ Ensure fan ON time completes
  delay(FAN_ON_TIME - 500);

  // 7️⃣ Fan OFF
  analogWrite(fanPWM, 0);
  delay(FAN_OFF_TIME);

  // 8️⃣ Count cycle
  runCount++;
  Serial.print("Completed runs: ");
  Serial.println(runCount);
}
