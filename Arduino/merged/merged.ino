#include <Servo.h>

// ===== PIN CONFIG =====
const int fanPWM   = 9;
const int servoM1  = 6;
const int servoM2  = 7;

// ===== FAN =====
const int FAN_SPEED = 220;   // strong airflow

// ===== SERVOS =====
Servo m1;   // fan tilt
Servo m2;   // rod

// ===== COUNTER =====
unsigned long cycleCount = 0;

void setup() {
  pinMode(fanPWM, OUTPUT);

  m1.attach(servoM1);
  m2.attach(servoM2);

  // Initial positions
  m1.write(0);    // fan up
 // m1.write(180);
  m2.write(180);    // rod start

  Serial.begin(9600);
  Serial.println("Simple sequence started");
}

void loop() {

  // S1: Fan start (acceleration)
  analogWrite(fanPWM, FAN_SPEED);
  delay(1000);

  // S2: Fan down
  m1.write(90);
 // m1.write(270);
  delay(800);

  // S3: Fan max airflow
  delay(1000);

  // S4: Fan partial up
  m1.write(80);
  delay(500);

  // S5: Rod engage
 // m2.write(90);
  m2.write(270);
  delay(800);

  // S6: Fan stop
  analogWrite(fanPWM, 0);
  delay(300);

  // S7: Fan reset (up)
  m1.write(0);
  //m1.write(360);
  delay(800);

  // S8: Rod extend
 // m2.write(180);
  m2.write(360);
  delay(1000);

  // S9: Scanner placeholder
  delay(2000);   // scanner later

  // S10: Rod retract
 // m2.write(0);
 m2.write(180);

  delay(1000);

  // S11: Cycle complete
  cycleCount++;
  Serial.print("Cycle complete: ");
  Serial.println(cycleCount);

  delay(1000);   // pause before next cycle
}

