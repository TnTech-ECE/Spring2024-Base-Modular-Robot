
## Bluetooth Reveiver
This code is for an ESP32. The reciever microcontroller needs to be connected to a laptop. The GUI can be ran to read sensor data when the Nav_Full code is ran. The code recieves the signal sent by the transmitter.

## Bluetooth Transmitter
This code is for an ESP32. The transmitter micrconcontroller needs to be connected to the on-robot Arduino Mega 2560. The code creates ESP Now packets to be sent to the reciever.

## 2023_Board
This code is ran on the on-robot Arduino Mega 2560 for object detection and position sensing without a line present. (Not used with ROS)

## Line Following
This code is ran on the on-robot Arduino Mega 2560 for line following. The code uses PID control method to control navigation. (Not used with ROS)

## Nav_Full 
This code is ran on the on-robot Arduino Mega 2560. This code encapsulates all sensor readings and is used alongside the jetson nano. The code has no navigation capability as ROS completes those tasks.

*All Arduino Mega and ESP32 code is compiled with the Arduino IDE*
