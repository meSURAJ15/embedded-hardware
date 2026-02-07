// #include "esp_camera.h"
// #include <WiFi.h>

// // Replace with your Wi-Fi credentials
// const char* ssid = "enigma";
// const char* password = "87654321";

// // Select camera model
// #define CAMERA_MODEL_AI_THINKER

// #include "camera_pins.h"

// void startCameraServer();

// void setup() {
//   Serial.begin(115200);
//   Serial.println("ESP32-CAM Initializing...");

//   // Camera config
//   camera_config_t config;
//   config.ledc_channel = LEDC_CHANNEL_0;
//   config.ledc_timer = LEDC_TIMER_0;
//   config.pin_d0 = Y2_GPIO_NUM;
//   config.pin_d1 = Y3_GPIO_NUM;
//   config.pin_d2 = Y4_GPIO_NUM;
//   config.pin_d3 = Y5_GPIO_NUM;
//   config.pin_d4 = Y6_GPIO_NUM;
//   config.pin_d5 = Y7_GPIO_NUM;
//   config.pin_d6 = Y8_GPIO_NUM;
//   config.pin_d7 = Y9_GPIO_NUM;
//   config.pin_xclk = XCLK_GPIO_NUM;
//   config.pin_pclk = PCLK_GPIO_NUM;
//   config.pin_vsync = VSYNC_GPIO_NUM;
//   config.pin_href = HREF_GPIO_NUM;
//   config.pin_sscb_sda = SIOD_GPIO_NUM;
//   config.pin_sscb_scl = SIOC_GPIO_NUM;
//   config.pin_pwdn = PWDN_GPIO_NUM;
//   config.pin_reset = RESET_GPIO_NUM;
//   config.xclk_freq_hz = 20000000;
//   config.pixel_format = PIXFORMAT_JPEG;
//   config.frame_size = FRAMESIZE_VGA; // 640x480
//   config.jpeg_quality = 10;           // 0-63, lower is higher quality
//   config.fb_count = 2;

//   // Init camera
//   esp_err_t err = esp_camera_init(&config);
//   if (err != ESP_OK) {
//     Serial.printf("Camera init failed: 0x%x", err);
//     return;
//   }

//   // Connect Wi-Fi
//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to Wi-Fi");
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println();
//   Serial.print("Wi-Fi connected! IP: ");
//   Serial.println(WiFi.localIP());

//   // Start web server
//   startCameraServer();
//   Serial.println("Camera ready! Use 'http://<IP>' to view.");
// }

// void loop() {
//   // Nothing here; server handles streaming
// }

// #include <WebServer.h>
// #include <esp_timer.h>
// #include <img_converters.h>
// #include <fb_gfx.h>
// #include <sensor.h>
// #include <Arduino.h>

// WebServer server(80);

// void handle_jpg_stream(void) {
//   WiFiClient client = server.client();
//   String response = "HTTP/1.1 200 OK\r\n";
//   response += "Content-Type: multipart/x-mixed-replace; boundary=frame\r\n\r\n";
//   server.sendContent(response);

//   while (1) {
//     camera_fb_t * fb = esp_camera_fb_get();
//     if (!fb) {
//       Serial.println("Camera capture failed");
//       return;
//     }
//     client.print("--frame\r\n");
//     client.print("Content-Type: image/jpeg\r\n");
//     client.print("Content-Length: " + String(fb->len) + "\r\n\r\n");
//     client.write(fb->buf, fb->len);
//     client.print("\r\n");
//     esp_camera_fb_return(fb);

//     if (!client.connected()) break;
//   }
// }

// // void handle_index() 
//   String html = "<html><body><h2>ESP32-CAM Stream</h2>";
//   html += "<img src='/stream' width='640' height='480'></body></html>";
//   server.send(200, "text/html", html);
// }

// void startCameraServer() {
//   server.on("/", HTTP_GET, handle_index);
//   server.on("/stream", HTTP_GET, handle_jpg_stream);
//   server.begin();
// }


#define FLASH_LED_PIN 4

void setup() {
  pinMode(FLASH_LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(FLASH_LED_PIN, HIGH);
  delay(400);
  digitalWrite(FLASH_LED_PIN, LOW);
  delay(400);
}

