#!/usr/bin/env python3

#Motor_control.py takes in a twist message and sends a serial stream to the motors
#Format: Signed binary with the sign bit being 0 for positive and 1 for negative.
#           Two Bytes will be sent as {Linear_Vel Angular_Vel} with the latter 7 bits signifiying magnitude.
#Author: Isaac Jennings ijennings42@robotictechtn.com FIXME

import serial
import time



linear_vel = 100
angular_vel = 0

ser = serial.Serial(
    '/dev/ttyACM0',
    115200,
    timeout=1.0, 
)
time.sleep(3.0) #Setup Time Wait
ser.reset_input_buffer()
print("Serial OK")

try:
    while True:
        time.sleep(1)
        print("Sent MSG")
        ser.write(bin(linear_vel) + bin(angular_vel))
        
except KeyboardInterrupt:
    print("Close Serial Comm")
    ser.close()



