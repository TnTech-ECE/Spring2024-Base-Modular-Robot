#include <esp_now.h>
#include <WiFi.h>

//Structure example to receive data
//Must match the sender structure
typedef struct test_struct {
  uint16_t lineFollowing;
  float heading;
  float roll;
  float pitch;
  float Qw;
  float Qx;
  float Qy;
  float Qz;
  uint32_t US1;
  uint32_t US2;
  uint32_t US3;
  uint32_t US4;
  uint16_t TOF1;
  uint16_t TOF2;
  uint16_t TOF3;
  uint16_t TOF4;
  uint16_t TOF5;
  uint16_t TOF6;
  uint16_t TOF7; 
  uint16_t TOF8;
} test_struct;

//Create a struct_message called myData
test_struct myData;
String c = ",";

//callback function that will be executed when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&myData, incomingData, sizeof(myData));
  //Serial.print("Bytes received: ");
  //Serial.println(len);
  //Serial.print("x: ");
  Serial.println(myData.lineFollowing + c + myData.heading + c + myData.roll + c + myData.pitch + c + myData.Qw + c +myData.Qx + c +myData.Qy + c +myData.Qz + c + myData.US1 + c + myData.US2 + c + myData.US3 + c + myData.US4 + c + myData.TOF1+ c + myData.TOF2+ c + myData.TOF3+ c + myData.TOF4+ c + myData.TOF5+ c + myData.TOF6+ c + myData.TOF7+ c + myData.TOF8);
}

void setup() {
  //Initialize Serial Monitor
  Serial.begin(115200);
  
  //Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);

  //Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
}