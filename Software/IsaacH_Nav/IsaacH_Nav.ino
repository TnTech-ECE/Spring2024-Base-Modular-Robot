#include "IsaacH_Nav.h"
String start = "<";
String end = ">";
String c = ",";


void setup() {
  Serial.begin(9600);
  while (!Serial) yield();

  //setup_OLED();
  setup_LineFollowing();
  setup_Orientation();
}

void loop(){
  run_LineFollowing();
  run_Orientation();
  //Serial.println(start + packet.lineFollowing + c + packet.heading + c + packet.pitch + c + packet.roll + c +packet.qw + c + packet.qx + c + packet.qy + c + packet.qz + end);
  Serial.println(start + packet.lineFollowing + c + packet.heading + c + packet.pitch + end);
  delay(10);
}
/*
*Function Name: setup_OLED
*Parameters: None
*Returns: Void
*Description: Initializes the OLED display
*/
void setup_OLED(){
  oled.init();             
  oled.clear();
}
