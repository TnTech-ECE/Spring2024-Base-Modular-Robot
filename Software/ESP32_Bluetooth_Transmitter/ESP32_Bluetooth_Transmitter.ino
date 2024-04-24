/*Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*********/

#include <esp_now.h>
#include <WiFi.h>

#define RXp2 16
#define TXp2 17

// REPLACE WITH YOUR ESP RECEIVER'S MAC ADDRESS
uint8_t broadcastAddress1[] = {0x40,0x91,0x51,0x2D,0x4D,0x4C};

char* tempParse;
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

test_struct test;
bool b_goRead = false;
char c_readTemp;
uint8_t u8_readIndex = 0;
const uint8_t u8_startMark = '<';
const uint8_t u8_endMark = '>';
bool b_isEnd = false;
const uint8_t u8_receivedSize = 100;
char au8_receivedData[u8_receivedSize];

esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  char macStr[18];
  Serial.print("Packet to: ");
  // Copies the sender mac address to a string
  snprintf(macStr, sizeof(macStr), "%02x:%02x:%02x:%02x:%02x:%02x",
           mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
  Serial.print(macStr);
  Serial.print(" send status:\t");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Delivery Success" : "Delivery Fail");
}

void read_Serial(){
  Serial.print("Received from serial: ");
  while (Serial2.available() && b_isEnd == false) {
    c_readTemp = Serial2.read();
    Serial.print(c_readTemp);
    if (c_readTemp == u8_startMark) {  //Check for starting point
      b_goRead = true;
    } else if (b_goRead) {
      if (c_readTemp == u8_endMark) {  //Check for ending point and terminate the array with null
        au8_receivedData[u8_readIndex] = '\0';
        b_goRead = false;
        b_isEnd = true;
        u8_readIndex = 0;
      } else {
        au8_receivedData[u8_readIndex] = c_readTemp;
        u8_readIndex++;
      }// end if-else
    }// end if-else
  }// end while
  Serial.println("");
}

void parse(){
  char* tempParse;

  tempParse = strtok(au8_receivedData, ",");
  test.lineFollowing = atoi(tempParse);
  tempParse = strtok(NULL, ",");
  test.heading = atof(tempParse);
  tempParse = strtok(NULL, ",");
  test.roll = atof(tempParse);
  tempParse = strtok(NULL, ",");
  test.pitch = atof(tempParse);
  tempParse = strtok(NULL, ",");
  test.Qw = atof(tempParse);
  tempParse = strtok(NULL, ",");
  test.Qx = atof(tempParse);
  tempParse = strtok(NULL, ",");
  test.Qy = atof(tempParse);
  tempParse = strtok(NULL, ",");
  test.Qz = atof(tempParse);
  tempParse = strtok(NULL, ",");
  test.US1 = atoi(tempParse);
  tempParse = strtok(NULL, ",");
  test.US2 = atoi(tempParse);
  tempParse = strtok(NULL, ",");
  test.US3 = atoi(tempParse);
  tempParse = strtok(NULL, ",");
  test.US4 = atoi(tempParse);
  tempParse = strtok(NULL, ",");
  test.TOF1 = atoi(tempParse);
  tempParse = strtok(NULL, ",");
  test.TOF2 = atoi(tempParse);
  tempParse = strtok(NULL, ",");
  test.TOF3 = atoi(tempParse);
  tempParse = strtok(NULL, ",");
  test.TOF4 = atoi(tempParse);
  tempParse = strtok(NULL, ",");
  test.TOF5 = atoi(tempParse);
  tempParse = strtok(NULL, ",");
  test.TOF6 = atoi(tempParse);
  tempParse = strtok(NULL, ",");
  test.TOF7 = atoi(tempParse);
  tempParse = strtok(NULL, ",");
  test.TOF8 = atoi(tempParse);
}

void setup() {
  Serial.begin(9600);
  Serial2.begin(115200, SERIAL_8N1, RXp2, TXp2);

  WiFi.mode(WIFI_STA);
 
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  esp_now_register_send_cb(OnDataSent);
   
  // register peer
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  // register first peer  
  memcpy(peerInfo.peer_addr, broadcastAddress1, 6);
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
}
void loop() {
  read_Serial();
  if(b_isEnd){
    parse();
    b_isEnd = false;
  }

  esp_err_t result = esp_now_send(0, (uint8_t *) &test, sizeof(test_struct));
  delay(10);
}
