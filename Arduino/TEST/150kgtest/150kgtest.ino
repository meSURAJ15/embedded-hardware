#include <Servo.h>

// ===== PIN CONFIG =====
const int fanPWM   = 3;   // PWM pin (safe with Servo library)
const int servoM1  = 6;   // fan tilt
const int servoM2  = 7;   // rod

// ===== FAN =====
const int FAN_SPEED = 220;   // strong airflow (0–255)

// ===== SERVO POSITIONS (SAFE RANGE) =====
// Fan tilt
// #define FAN_UP      0
// #define FAN_MID     80
// #define FAN_DOWN    90

#define FAN_UP      110
#define FAN_MID     30
#define FAN_DOWN    15

// Rod movement
#define ROD_RETRACT 0
#define ROD_MID     90
#define ROD_EXTEND  180

// ===== SERVOS =====
Servo m1;   // fan tilt
Servo m2;   // rod

// ===== COUNTER =====
unsigned long cycleCount = 0;

void setup() {
  pinMode(fanPWM, OUTPUT);

  m1.attach(servoM1);
  m2.attach(servoM2);

  Serial.begin(9600);
  Serial.println("Simple sequence started");

  delay(500);   // allow servo power to stabilize

  // Initial positions
  m1.write(FAN_UP);        // fan up
 // m2.write(ROD_EXTEND);    // rod start position
  m2.write(ROD_RETRACT); 
}

void loop() {

  // S1: Fan start (acceleration)
  analogWrite(fanPWM, FAN_SPEED);
  delay(1000);

  // S2: Fan down
  m1.write(FAN_DOWN);
  delay(800);

  // S3: Fan max airflow
  delay(2000);

  // S4: Fan partial up
  m1.write(FAN_MID);   // slight adjustment (still safe)
  delay(700);

  // S5: Rod engage
  m2.write(ROD_MID);
  delay(800);

  // S6: Fan stop
  analogWrite(fanPWM, 0);
  delay(300);

  // S7: Fan reset (up)
  m1.write(FAN_UP);
  delay(800);

  // S8: Rod extend
  m2.write(ROD_EXTEND);
  delay(1000);

  // S9: Scanner placeholder
  delay(2000);

  // S10: Rod retract
  m2.write(ROD_RETRACT);
  delay(1000);

  // S11: Cycle complete
  cycleCount++;
  Serial.print("Cycle complete: ");
  Serial.println(cycleCount);

  delay(1000);   // pause before next cycle
}