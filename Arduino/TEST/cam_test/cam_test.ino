#define FLASH_LED_PIN 4

void setup() {
  pinMode(FLASH_LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(FLASH_LED_PIN, HIGH);
  delay(1000);
  digitalWrite(FLASH_LED_PIN, LOW);
  delay(400);
}