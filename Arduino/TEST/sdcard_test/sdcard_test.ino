#include "FS.h"
#include "SD_MMC.h"

void listDir(fs::FS &fs, const char * dirname, uint8_t levels) {
  Serial.printf("Listing directory: %s\n", dirname);

  File root = fs.open(dirname);
  if (!root) {
    Serial.println("❌ Failed to open directory");
    return;
  }
  if (!root.isDirectory()) {
    Serial.println("❌ Not a directory");
    return;
  }

  File file = root.openNextFile();
  while (file) {
    if (file.isDirectory()) {
      Serial.print("  DIR : ");
      Serial.println(file.name());
      if (levels) {
        listDir(fs, file.name(), levels - 1);
      }
    } else {
      Serial.print("  FILE: ");
      Serial.print(file.name());
      Serial.print("  SIZE: ");
      Serial.println(file.size());
    }
    file = root.openNextFile();
  }
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("\n===== ESP32-CAM SD Card Test =====");

  if (!SD_MMC.begin()) {
    Serial.println("❌ SD Card Mount Failed");
    return;
  }

  uint8_t cardType = SD_MMC.cardType();

  if (cardType == CARD_NONE) {
    Serial.println("❌ No SD Card attached");
    return;
  }

  Serial.print("✅ SD Card Type: ");
  if (cardType == CARD_MMC) Serial.println("MMC");
  else if (cardType == CARD_SD) Serial.println("SDSC");
  else if (cardType == CARD_SDHC) Serial.println("SDHC");
  else Serial.println("UNKNOWN");

  uint64_t cardSize = SD_MMC.cardSize() / (1024 * 1024);
  Serial.printf("✅ SD Card Size: %llu MB\n", cardSize);

  listDir(SD_MMC, "/", 0);

  // Optional: Read a test file
  if (SD_MMC.exists("/test.txt")) {
    File file = SD_MMC.open("/test.txt");
    Serial.println("\n📄 Reading /test.txt:");
    while (file.available()) {
      Serial.write(file.read());
    }
    file.close();
  } else {
    Serial.println("\nℹ️ /test.txt not found (this is OK)");
  }
}

void loop() {
}
