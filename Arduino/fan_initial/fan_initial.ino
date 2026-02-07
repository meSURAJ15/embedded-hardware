// ===== PIN CONFIG =====
const int fanPWM = 9;   // Blue wire

// ===== TIMING (milliseconds) =====
// const unsigned long ON_TIME  = 5000; // fan ON for 5 sec
// const unsigned long OFF_TIME = 3000; // fan OFF for 3 sec

const unsigned long ON_TIME  = 1000; // fan ON for 5 sec
const unsigned long OFF_TIME = 5000; // fan OFF for 3 sec

// ===== SPEED =====
// const int FAN_SPEED = 180; // 0–255 (180 ≈ 70%)
const int FAN_SPEED = 200; // 0–255 (180 ≈ 70%)


// ===== COUNTER =====
unsigned long runCount = 0;

void setup() {
  pinMode(fanPWM, OUTPUT);

  Serial.begin(9600);
  Serial.println("Fan cycle counter started");
}

void loop() {
  // Fan ON
  analogWrite(fanPWM, FAN_SPEED);
  delay(ON_TIME);

  // Fan OFF
  analogWrite(fanPWM, 0);
  delay(OFF_TIME);

  // Increment counter after one full cycle
  runCount++;
  Serial.print("Completed runs: ");
  Serial.println(runCount);
}
