# Object Detection Signoff

## Functionality

The object detection subsystem sends data to the master control  to control and move the robot. The subsystem will use time of flight distance sensors to detect object inside of the arena. The time of flight sensors will use the detected object to determine the robot's movement to avoid the object. The emitter will use a laser shot infrared light, and the collector will recieve the reflected light that bounces off objects. This data will be sent to the master control to move and control the robot to avoid the object(s).

## Constraints
### Shall Statements

* C4: The robot shall contain modules that are plug-and-play adaptable for different IEEE competition requirements. 

    * This constraint allows future teams to replace or reallocate the chosen object detection sensor(s).

* C10: The robot shall turn 360 degrees left and right and move forwards and backwards based on sensor inputs.
    
    * This constraint is applicable because the robot needs to move around the arena autonomously.

* C11: The robot shall have a navigation system that controls movement.

    * This constraint is applicable because the sensor needs to transmit data to the master control.

### Broader Implications

* C14: The robot shall have a user manual that explains all functions and capabilities of the robot. 
	
    * This constraint was constructed to document the design process and motives of the object detection subsystem for future SECON teams.
    
## Buildable schematic 

### Object Detection Subsystem Schematic

![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/reidcrews-signoff-ObjectDetection/Documentation/Electrical/Schematics/Sources/Object%20Detection/ObjDetectionSensorSchematic.png)

The schematic above is shown. Eight time of flight are used for the object detection with two sensors per each side. Each sensor is I2C communications. Each sensor has a serial clock (SCL) connected to digtial pin 21 of the Arduino Mega. Each sensor also has a serial data (SDA) connected to digtial pin 20 of the Arduino Mega. Each sensor and Arduino Mega are powerd by the 5 V power distribution bus.

### Object Detection Placement

<p align = "center">
<img src = https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/reidcrews-signoff-ObjectDetection/Documentation/Images/Object%20Detection/ObjDetectionSensorHorizonView.png/>
</p>

The CAD drawing above is the horizontal view of the time of flight. The field of view (FOV) is 25 $^\circ$. The maxmium recommended distance is 1 m (39.37 in). 

<p align = "center">
<img src = https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/reidcrews-signoff-ObjectDetection/Documentation/Images/Object%20Detection/ObjDetectionSensorVerticalView.png/>
</p>

The CAD drawing above is the vertical view of the time of flight.


## Analysis

The time of flight sensor has an operating current at 19 mA and operating voltage at 5 V. The Grove Time of Flight Disyance Sensor requires only two pin for SCL and SDA. The picture below shows the plug-and-play ability because the sensor can be connected the GROVE connectors.


![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/reidcrews-signoff-ObjectDetection/Documentation/Images/Object%20Detection/TimeOfFlightSensorImage.jpg)

From the CAD drawing of the horizontal view of the timing of flight, the equation for the blind spot (the area in the middle of the two sensor's FOV).

$$ Max \space Distance = {x \over 2} * tan(77.5^\circ)$$

The *Max Distance* is max distance in the blind spot and *x* is the distance between the two sensors. For the CAD drawing case, the *Max Distance* is 13.53 in, and the area is 40.59 in $^2$. For the maxmium apart case (12 in apart), *Max Distance* is 54.12 in, and the area is 324.77 in $^2$. The chosen distance between the sensors is 6 in becuase the max distance from edges and blind spot is the lowest average distance. The blue and green lines are 13.53 in.

<p align = "center">
<img src = https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/reidcrews-signoff-ObjectDetection/Documentation/Images/Object%20Detection/ObjDetectionSensorLengthMeasurements.png/>
</p>

The sampling rate for the time of flight sensor 33 ms at default. The minimum is 8 ms, and the maximum is 200 ms. The default frequency is 30.3 Hz. The time of flight sensor has four modes in the table below [1-2].

<p align = "center">
Table 1: Four Modes

<div align="center">
	
| Range profile | Range timing budget |    Typical performance    | Typical application |
|---------------|---------------------|---------------------------|---------------------|
| Default mode  | 30 ms               | 1.2 m, accuracy 4 % - 7 % | Standard            |
| High accuracy | 200 ms              | 1.2 m, accuracy < +/- 3 % | Precise measurement | 
| Long range    | 33 ms               |   2 m, accuracy 4 % - 7 % | Long ranging        |
| High speed    | 20 ms               | 1.2 m, accuracy +/- 5 %   | High speed          |
	
</div>
 
These modes allow the team to prioritize either accuracy, range, or speed. Range timing budget is the sampling rate. 

$$ Max \space robot \space speed: \space 2 \space {ft \over s}$$

$$ Sampling \space Rate \space for \space Default \space Mode \space 30\space ms\space (33.3\space Hz)$$

$$ Accuracy \space Range \space for \space Default \space Mode $$

$$ 4 \space Percent \space (0.6912 - 0.7488 \space in) \space , \space 7 \space Percent \space (0.6696 - 0.7704 \space in) $$

## BOM

<div align="center">

| Item | Part Number | Quantity | Price | Total Price | 
|-|-|-|-|-| 
|Grove - Time of Flight Distance Sensor(VL53L0X) | SKU 101020532 | 8 | $36.99 | $295.92| 

</div>

## Reference

[1] [User Manual Time of Flight][def1]: User Manual for VL53L0X

[2] [Datasheet Time of Flight][def2]: Datasheet for VL53L0X

[3] [Seeed Studio Website][def3]: Time of Flight Sensor Website

[4] [Purchase Site for Sensor][def4]: Amazon Site of Time of Flight Sensor



[def1]: https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/reidcrews-signoff-ObjectDetection/Documentation/Background%20Documents/Object%20Detection/Time-of-Flight%20User%20Manual.pdf

[def2]: https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/reidcrews-signoff-ObjectDetection/Documentation/Background%20Documents/Object%20Detection/Time-of-Flight%20Datasheet.pdf

[def3]: https://www.seeedstudio.com/Grove-Time-of-Flight-Distance-Sensor-VL53L0X.html?utm_source=blog&utm_medium=blog

[def4]: https://www.amazon.com/SeeedStudio-Grove-Flight-Distance-VL53L0X/dp/B07Q1YBH99?ref_=ast_sto_dp
