#include "IsaacH_Nav.h"
String start = "<";
String end = ">";
String c = ",";

uint32_t currTime = 0;
uint32_t prevTime = 0;
void setup() {
  Serial.begin(9600);
  while (!Serial) yield();

  //setup_OLED();
  setup_ObjectDetection();
  setup_LineFollowing();
  setup_Orientation();
}

void loop(){
  run_LineFollowing();
  run_Orientation();
  run_Location();
  run_ObjectDetection();
  currTime = millis();
  if((currTime-prevTime) > 40){
    prevTime = currTime;
    Serial.println(start + packet.lineFollowing + c + packet.heading + c + packet.roll + c + packet.pitch + c + packet.qw + c + packet.qx + c + packet.qy + c + packet.qz + c + packet.locationFront + c + packet.locationRight + c + packet.locationBack + c + packet.locationLeft + c + packet.objectDetectionSensors[0] + c + packet.objectDetectionSensors[1] + c + packet.objectDetectionSensors[2] + c + packet.objectDetectionSensors[3] + c + packet.objectDetectionSensors[4] + c + packet.objectDetectionSensors[5] + c + packet.objectDetectionSensors[6] + c + packet.objectDetectionSensors[7]  + end);
  }
}
