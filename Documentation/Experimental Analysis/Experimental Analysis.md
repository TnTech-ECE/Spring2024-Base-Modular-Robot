# Experimental Analysis

## Introduction 
The purpose of this report is to verify the requirements for the project and explain the procedures used to validate results. The results will be compared against the measures of success outlind in the project proposal to determine if the project was successful. This will also detail what the next steps are moving forward.

### Requirements

| Item | Constraint/Specification | Subsystem | 
|-|-|-|
| 1 | Shall design a robot with a single start button. Once activated, the robot will begin navigating its environment. | Power |
| 2 | Shall design a robot that possesses an allocated data input point for an alternative start method. | GUI |
| 3 | Shall design an autonomous robot that has customizable dimensions with the stock design only occupying up to one-half of the allowed cubic foot (1 ft x 1 ft x 6 in). | Chassis |
| 4 | Shall design a robot platform whose modules are plug-and-play adaptable for different IEEE competition requirements.  | Chassis, Attachments, Navigation|
| 5 | Shall design a robot that possesses a robust, centralized charging system that does not require the removal of the battery and that allows the robot to be used while being charged. | Battery Management |
| 6 | Shall evaluate wireless charging as an option for charging the robot. | Wireless Charging|
| 7 | Shall design a robot to possess a single emergency stop button that is accessible and stops all robot movement without removing power to essential processors. | Power |
| 8 | Shall design the power bus in such a way that the DC motors do not inhibit robot operation. | Power |
| 9 | Shall design a robot that can travel inclines and declines up to 25 degrees.  | Motors |
| 10 | Shall design a robot that can turn 360 degrees left and right and move forwards and backwards based on sensor inputs. | Motors, GUI |
| 11 | Shall design a robot whose navigation system controls movement; knows its location within a two-inch tolerance; and possesses a maximum speed of 2 feet per second. | GUI, Navigation, Location, Motors|
| 12 | The attachment components will be 3D printed to reduce cost of project. 	| Attachments, Layout and Organization |
| 13 | The line sensor attachment must be designed to place the sensor between 0.125 and 0.375 inches off the ground. | Attachments | 
| 14 | The frame will need to be able to withstand 20 pounds. | Chassis |

## Results

### Constraint 1 - Start Button

The first requirement is for the robot to have a functioning start button, which after activation will begin robot operation. This was tested 10 times by turning the switch off and then on again to see if the robot succesfully starts back up. The robot successfully turned on in 10 out of 10 trials.

| Trial Number | Robot Successfully Turned On |
|---|---|
| 1 | yes |
| 2 | yes |
| 3 | yes |
| 4 | yes |
| 5 | yes |
| 6 | yes |
| 7 | yes |
| 8 | yes |
| 9 | yes |
| 10 | yes |

As can be seen in the above table, the robot successfully turns on in 10 out of 10 trials, and so this constraint has been met.

Video demonstration of start switch demonstration can be found at ./Videos/Start_Switch.mp4

### Constraint 2 - Alternate Start Method 

### Constraint 3 - Dimensions
The dimensions of the robot are customizable when ordering the extruded alumnium for future teams. The extruded alumnium can be cut to change the dimensions. Additionally, the stock design only takes up the specified 1 ft x 1 ft x 6 in area shown below. This constraint could not be experimentally tested because it is inherently true.

##### Figure 1. Length (12 in)
![Alt Text](../Images/Experimental%20Analysis%20Photos/Robot%20Length.jpg)

##### Figure 2. Width (12 in)
![Alt Text](../Images/Experimental%20Analysis%20Photos/Robot%20Width.jpg)

##### Figure 3. Height (6 in)
![Alt Text](../Images/Experimental%20Analysis%20Photos/Robot%20Height.jpg)

Overall, the constraint was met.

### Constraint 4 - Plug-and-Play Adaptability
This constraint was derived from the goal of the project being to create a base platform for future teams. Therefore, the robot needed to be adapatable. For components, this is possibe due to drop-in t nuts utilized for any component directly attached to the frame. Also, a slotted sheet system was developed for any componets connected to the top of the frame. These allowed for versatility with movement of componets. Additionally, being able to reuse code and having functions avaliable for different sensors was created. Testing some measurable features of both are seen below. 
#### Wheel Movement (4 in)
This constraint does not have a true experimental analysis section. The picture below shows the 4 in movement capabilities if the base robot was needed to be reconfigured.
The front wheel can move 20 mm forward and 95 mm backward. The back wheel can move forward 95 mm and backwards 20 mm. Both wheels can move a total of 115 mm (4.528 in) and this will be the same on both sides.
##### Figure 1. Front Wheel Forward Movement Measurement
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/FWFM.jpg)
##### Figure 2 & 3. Front Wheel Backward Movement/Back Wheel Forward Movement Measurement
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/FWBM.jpg)
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/BWFM.jpg)
##### Figure 4. Back Wheel Backward Movement Measurement
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/BWBM.jpg)

|Wheel| Does it move 4 inches? |
|-|-|
| FL | yes |
| FR | yes |
| BL | yes |
| BR | yes |

#### Component Movement (2 in)
This constraint does not have a true experimental analysis section. The picture below shows the 2 in movement capabilities of the time of flight sensor. This specification was derived from needing to move sensors easily. Specifically, the time of flight sensor will be used to detect objects on the playing field. Therefore, this sensor will more than likely need to be moved relativly frequently with objects typcially being in set positions. Photos of how this was measured can be seen below and a table for each time of slight sensor on the robot.
|Sensor|2 in manuverability?|
|-|-|
|1|-|
|2|-|
|3|-|
|4|-|
|5|-|
|6|-|
|7|-|
|8|-|

#### Wire Grouping/ Labeling
This is not able to be experimentally measured because is it inherently true and can be seen in the picture below.

![Alt Text](../Images/Experimental%20Analysis%20Photos/Grouping%20and%20Labeling.jpg)

Overall, the constraint was met.

### Constraint 5 - Robust Charging System



### Constraint 6 - Wireless Charging

### Constraint 7 - Emergency Stop

The emergency stop requirement requires that the robot have a button that when pressed, power will be removed from the motors, but not the microcontrollers or sensors. In order for this to be considered successful, in 10 out of 10 trials, pressing the emergency stop button had to result in a complete shutdown of the motors while keeping all other components powered. To be considered successful, the voltage delivered to the motors must be withing 0.5 V of 0.0 V.

To test this, the robot was turned on with the motors powered. The emergency stop button was then activated to cut power to the motors. The voltage to each motors was then measured and the LED indicators on the microprocessors were visually verified to ensure that the motors would remain unoperational and the essential processors would remain operational. 

The voltages measured over 10 trials at each of the motors is shown below.

| Trial | Motor 1 Voltage (mV) | Motor 2 Voltage (mV) | Motor 3 Voltage (mV) | Motor 4 Voltage (mV) | Processors on?|
| --- | --- | --- | --- | --- | --- |
| 1 | 0.029 | 0.019 | 0.018 | 0.014 | yes |
| 2 | -0.002 | 0.003 | 0.009 | 0.008 | yes |
| 3 | -0.016 | -0.007 | 0.033 | 0.004 | yes |
| 4 | 0.005 | -0.002 | 0.002 | -0.006 | yes |
| 5 | -0.005 | 0.006 | 0.015 | 0.002 | yes |
| 6 | 0.004 | 0.001 | 0.006 | -0.002 | yes |
| 7 | 0.004 | -0.001 | -0.030 | 0.011 | yes |
| 8 | -0.013 | 0.009 | -0.009 | -0.008 | yes |
| 9 | 0.0015 | 0.017 | 0.033 | 0.020 | yes |
| 10 | 0.0028 | 0.030 | 0.027 | 0.034 | yes |

As can be seen above, all of the motor voltages when the emergency stop button was activated are well within 0.5 V of 0.0 V (especially after noting the units of mV, not V). Because of this, this constraint is considered to have been met.

Video of emergency stop button demonstration can be found at ./Videos/Emergency_Stop_Demo.mp4

### Constraint 8 - Back EMF

In order for this constraint to be considered successful, during motor operation the 3.3 V and 5 V rails must not suffer from counter-EMF from the motors. In order to be considered successful, the voltage buses must not drop to more than 80% of the nominal value. 80% was chosen so that the back-EMF would not be able to push a digital high value down below the threshold, turning high values into low values. This gives lower limits of 2.64 V and 4.0 V for the 3.3 V and 5.0 V buses, respectively.

To test this, the motors were turned on and off, and the voltages at each voltage rail were measured each time. This was done at different locations on the voltage buses for even greater rigorousness. 

The table below shows the measured voltages with and without motor operation.

| Trial | 5 V Rail Voltage with Motors Off (V) | 5 V Rail Voltage with Motors On (V) | 3.3 V Rail Voltage with Motors Off (V) | 3.3 V Rail Voltage with Motors On (V) |
| --- | --- | --- | --- | ---|
| 1 | 3.2580 | 5.0250 | 3.2575 | 5.0264 |
| 2 | 3.2575 | 5.0263 | 3.2575 | 5.0264 |
| 3 | 3.2575 | 5.0261 | 3.2576 | 5.0265 |
| 4 | 3.2576 | 5.0261 | 3.2575 | 5.0264 |
| 5 | 3.2576 | 5.0261 | 3.2575 | 5.0264 |
| 6 | 3.2576 | 5.0269 | 3.2575 | 5.0251 |
| 7 | 3.2574 | 5.0263 | 3.2566 | 5.0250 |
| 8 | 3.2576 | 5.0259 | 3.2566 | 5.0549 |
| 9 | 3.2575 | 5.0264 | 3.2567 | 5.0264 |
| 10 | 3.2577 | 5.0258 | 3.2575 | 5.0246 |

As can be seen above, the voltages both with and without motor operation are well above the lower limit and will function with no issue for digital high values. Therefore, this constraint has been met.

### Constraint 9 - Inclines/Declines

### Constraint 10 - Motor Control

### Constraint 11 - Navigation

#### Speed

This constraint originated from the time limit for the SECON competition. The constraint is tested by having the robot drive in a straight line for 10 seconds, and then the distance is measured. 

Expected: The robot should reach a speed of 2 ft/s for ten out of ten trials.

See [Speed.md](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Experimental%20Analysis/Testing%20Data/SpeedTest.md) for the table with the trial data.

Outcome: The speed is slower than expected, but it is consistent. It is believed that the speed is lower since the calculations for the robot's speed for the signoff were considering the robot carrying the maximum amount of weight and being driven on a surface with more friction. Since the robot was not carrying any additional load and was driven on tile flooring for the testing, it is reasonable that the speed is lower. However, the speed is still sufficient to complete an entire SECON course in three minutes since it can go almost the length of the board in ten seconds.

#### Location

This constraint originated from the lineless board for 2023 SECON competition. The constraint is tested by selecting 10 different points on the 2023 SECON arena. The Front, Back, Right, and Left ultrasonic sensors measure to distance from the point to the walls of the arena. The robot was placed on the 10 different points from a relative corner of robot. The relative corner will be indicated in the table for testing data. The sensors for the Right and Left are offset from the edge by 11/16 in. (or 17.4625 mm). The equations use to get the location from the desired point to the sensor will be indicate by a table with the asterisks. <br />
<br />
<br />

<div align="center">
<img src = https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/2023%20SECON%20Borad%20with%20Robot.png >
</div>

<div align="center">
Standard Robot Position to Test the Location
</div>
<br />
<br />
<br />

<div align="center">
<img src = https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/10%20Positions%20of%20Measuring%20Location.JPG >
</div>

<div align="center">
Ten Different Position for Measuring the Robot's Location
</div> 
<br />
<br />
<br />

The graph below shows the average distance error for the Front, Back, Right, and Left sensor. The most inaccurate measured distance is 19.025 mm (or 0.7490 in). <br />

<div align="center">
<img src = https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/Error%20Distance%20for%20Location%20Tolerance.png >
</div>

<p align="center">
Graph Showcasing the Average Distance Error for Each Sensor
</p>
<br />


See [Location Tolerance](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Experimental%20Analysis/Testing%20Data/Location%20Tolerance.md) for the table of testing data.


The constraint is met because the large error distance was 19.025 mm (0.749 in), which is less than the 2-in tolerance constraint. The overall average error distance was around 10 mm. This average does correlative with the expected results because the resolution of the ultrasonic sensor is 1 cm.

### Specfication 12 - 3D Printing to Reduce Cost 
This specifcation was derived as a socioeconomic impact of the project. In hopes to reduce cost, components were 3D printed instead of finding premade attachments. A list of components and if they were 3D printed is give below.

| Component | 3D Printed? |
|-|-|
| Ultrasonic Attachment | yes |
| Time of Flight Attachment | yes |
| Line Following Attachment | yes |
| Motor Attachment | no |
| Slotted Sheets Middle/Ends| yes |
| Sheet Connectors | yes |

Overall, the constraint was met. The only component that was not 3D printed was the motor attachments and this was due to strength. However, it was still fabricated by the university with scrap metal causing it to have no cost. Therefore, this constraint is still considered met.

### Specification 13 - Line Sensor Attachment Height 
This specifcation was derived when designing the attachment of the line sensor and the data sheet recommended a minimum height of 0.125 inches and a maximum height of 0.375 inches. Following experimentation with the sensor and a higher importance constraint, this specification was deemed unnecessary. The data from the sensor was deemed accurate at greater heights. Also, the height of the sensor had to be increase to be able to clear inclines and declines of 22.5 degrees. The current sensors sit at 0.625 inches. Therefore, this constraint was not achieved.

### Specification 14 - Frame Weight Requirements
This specifcation orginated from previous competitions having a weight limit. The typcial limit is 25 lbs, but this was reduced to have a faster speed to 20lbs. Therefore, the frame was specified to be able to hold atleast a 20 lb load. To measure this, a 20 lb weight will be placed on the robot for 5 mins and afterwards the robot frame was inspected for any deformations. We did not have an exactly 20 lb weight; therefore, we used a 10.5kg (23.1 lbs) power supply. The weight was found in the data sheet provided [here](https://beyondmeasure.rigoltech.com/acton/attachment/1579/f-01c1/1/-/-/-/-/DP800%20Datasheet.pdf) for the power supply. This process can be seen in the photos below. It is important to note that althought no deformation was seen in the frame, there was some seen in the manufacturer provided atttachment. This can also be seen in the photos together. Therefore, in the future is it recommended to either design a stringer one or reduce the amount of weight. Additionally, the weight used was greater than 20 lbs, but the robot as a whole weights 2 kg (4.4 lbs). Therefore, some of that is also on the frame. In conclusion, there is more than 20 lbs seen on the frame so the constraint is met. However, other things will cause problems first, such as the manufacturer motor attachments. 

| Trial | Any Deformation of Frame? |
|-|-|
| 1 | No |
| 2 | No |
| 3 | No |
| 4 | No |
| 5 | No |

##### Figure 1. No Deformation View 1
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/Showing%20no%20deformation%20view%201.jpg)
##### Figure 2. No Deformation View 2
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/Showing%20no%20deformation%20view%202.jpg)
##### Figure 3. No Deformation View 3
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/Showing%20no%20deformation%20view%203.jpg)
##### Figure 4. Wheel Mount Slight Bowing
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/Showing%20wheel%20mount%20deformation.jpg)



Overall, the constraint was met.

## Improvements

## Conclusion

| Item | Description | Was constraint met? | 
|-|-|-|
| 1 | | yes |
| 2 | | |
| 3 | | yes |
| 4 | | yes |
| 5 | | |
| 6 | | |
| 7 | | yes |
| 8 | | yes |
| 9 | | |
| 10 | | |
| 11 | | |
| 12 | | yes |
| 13 | | no |
| 14 | | yes |
