# Location Signoff

## Functionality

The location subsystem sends data to the master control  to control and move the robot. The subsystem will use ultrasonic sensors to detect the arena's boundaries. The ultrasonic sensors will use the detected boundaries to determine the robot's phyiscal location. The transmitter will generate an ultrasonic wave, and the receiver will receive the reflected ultrasonic wave. This data will be sent to the master control to know the robot's location relative to the arena.

## Constraints
### Shall Statements

* C4: The robot shall contain modules that are plug-and-play adaptable for different IEEE competition requirements. 

    * This constraint allows future teams to replace or reallocate the chosen location sensor(s).

* C10: The robot shall turn 360 degrees left and right and move forwards and backwards based on sensor inputs.
    
    * This constraint is applicable because the robot needs to move around the arena autonomously.

* C11: The robot shall have a navigation system that controls movement.

    * This constraint is applicable because the sensor needs to transmit data to the master control.
		
* C12: The robot shall know its location within a two-inch tolerance.
    
    *  This constraint holds the location subsystem to a maximum of 2-inch tolerance. The two-inch tolerance will be calculated from the desired arena coorinates.

### Broader Implications

* C14: The robot shall have a user manual that explains all functions and capabilities of the robot. 
	
    * This constraint was constructed to document the design process and motives of the location subsystem for future SECON teams.

## Buildable Schematic 

### Location Subsystem Schmatic

![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/reidcrews-signoff-Location/Documentation/Electrical/Schematics/Sources/Position/PositionSensorSchematic2.png)


The location schematic is shown above. The Grove Ultrasonic Distance Sensors are used from SeeedStudio. The sensor is powered by the Arduino Mega 5V pin. The SIG pin is for both the transmitter and receiver, and the NC pin is the non-connection pin. Each sensor SIG pin is connected to a digital pin of the Arduino Mega. Four sensors are used with one on each side because this allows each side of the robot to be known relative to the arena's boundaries.

### Ultrasonic Sensor Pinout

![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/reidcrews-signoff-Location/Documentation/Images/Position/Grove-Ultrasonic-Distance-Sensor-pinout.png)

The pinout of the ultrasonic sensor is shown above.


## Analysis

The ultrasonic sensor has an operating current at 8 mA and operating voltage at 3.3 to 5 V. The wide voltage level range is an advantage compared to the HC-SR04. The Grove Ultrasonic Sensor is easy direct connection with Arduino or Raspberry Pi with STEMMA connectors. The HC-SR04 ultrasonic sensor needs voltage conversion circuit. The Grove Ultrasonic Sensor requires only one pin for the transmitter and receiver. The HC-SR04 ultrasonic sensor needs two pins for the transmitter and receiver. The Grove Ultrasonic Sensor saves one GPIO pin on the microcontroller which is the most valuable resource [1]. 


![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/reidcrews-signoff-Location/Documentation/Images/Position/UltrasonicSensorComparsion.jpg)

The operating frequency is 40 kHz. When a pulse trigger signal with more than 10 &#956;s, the ultrasonic sensor will issue 8 cycles of 40 kHz cycle level and detect the echo signal (return signal). 

<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/reidcrews-signoff-Location/Documentation/Images/Position/PositionSensorTimingDiagram.PNG"/>
</p>

The recommended sampling rate is over 60 ms (16.7 Hz) [2]. 

$$ Max \space robot \space speed: \space 2 \space {ft \over s}$$

$$Sampling \space Rate \space for \space 60\space ms\space (16.7\space Hz)$$

$$ 2 \space {ft \over s} *0.06 \space s = 0.12 \space ft \space or \space 1.44 \space in $$

$$Sampling \space Rate \space for \space 80\space ms\space (12.5\space Hz)$$

$$ 2 \space {ft \over s} *0.08 \space s = 0.16 \space ft \space or \space 1.92 \space in $$


The pulse width of the echo signal is directly proportional to the measured distance.


$$Distance = {Echo\space Time * Speed\space of\space Sound \over 2}$$

The formula above is used to find the distance between the sensor and object. The measuring range is 2 to 350 cm. This specification is upheld by the constraint of the 4 x 8 ft arena because 350 cm (11.5 ft) is enough distance to measure anywhere in the arena. Worst case scenario distance is the adjacent diagonal to the 8 ft wall. That distance is around 9 ft which is still inside of the 11.5 ft maxmium distance. The tolerance for measured distance is $\pm$ 2 mm which is upheld by the $\pm$ 2 in. tolerance constraint [3]. The height of the ultrasonic sensor placement will be around 1.75 to 3.5 inches because a 1x4 wood board is used for the arena boundaries [4]. The width placment will be in the middle of robot on each side. The weight of the ultrasonic sensor is 13 g which should not be a factor in the robot overall weight. The measured angle of the ultrasonic sensor is 15 $^\circ$.

## BOM

| Item | Part Number | Quantity | Price | Total Price | 
|-|-|-|-|-| 
| Grove - Ultrasonic Distance Sensor | SKU 101020010 | 4 | $3.95 | $15.80| 

## Reference

[1] [Comparing Ultrasonic Sensors][def2]: Comparing the HC-SR04 and Grove – Ultrasonic Distance Sensor

[2] [Ultrasonic Sensor Datasheet][def4]: Sampling Rate & Timimg Digram

[3] [Grove - Ultrasonic Distance Sensor][def1]: The link for the ultrasonic sensor from Seeed Studio

[4] [SECON 2024 Hardware Competition][def3]: Rules for SECON Hardware Competition

[5] [Grove Ultrasonic Ranger Datasheet][def5]: Datasheet from Seeed Studio



[def1]: https://www.seeedstudio.com/Grove-Ultrasonic-Distance-Sensor.html?utm_source=blog&utm_medium=blog

[def2]: https://www.seeedstudio.com/blog/2019/11/04/hc-sr04-features-arduino-raspberrypi-guide/

[def3]: https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/reidcrews-signoff-Location/Documentation/Background%20Documents/SEC24-HW-Competition_V5.6-1.pdf

[def4]: https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf

[def5]: https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/reidcrews-signoff-Location/Documentation/Background%20Documents/Position/Grove-Ultrasonic_Ranger_WiKi.pdf