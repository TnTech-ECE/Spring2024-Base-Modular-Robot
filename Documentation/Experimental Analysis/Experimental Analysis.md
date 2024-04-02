# Experimental Analysis

## Introduction 
The purpose of this report is to verify the requirements for the project and explain the procedures used to validate results. The results will be compared against the measures of success outlind in the project proposal to determine if the project was successful. This will also detail what the next steps are moving forward.

### Requirements

| Item | Constraint/Specification | Subsystem | 
|-|-|-|
| 1 | Shall design a robot with a single start button. Once activated, the robot will begin navigating its environment. | Power |
| 2 | Shall design a robot that possesses an allocated data input point for an alternative start method. | |
| 3 | Shall design an autonomous robot that has customizable dimensions with the stock design only occupying up to one-half of the allowed cubic foot (1 ft x 1 ft x 6 in). | Chassis |
| 4 | Shall design a robot platform whose modules are plug-and-play adaptable for different IEEE competition requirements.  | Chassis, Attachments, Navigation|
| 5 | Shall design a robot that possesses a robust, centralized charging system that does not require the removal of the battery and that allows the robot to be used while being charged. | Battery Management |
| 6 | Shall evaluate wireless charging as an option for charging the robot. | Wireless Charging|
| 7 | Shall design a robot to possess a single emergency stop button that is accessible and stops all robot movement without removing power to essential processors. | Power |
| 8 | Shall design the power bus in such a way that the DC motors do not inhibit robot operation. | Power |
| 9 | Shall design a robot that can travel inclines and declines up to 25 degrees.  | Motors |
| 10 | Shall design a robot that can turn 360 degrees left and right and move forwards and backwards based on sensor inputs. | Navigation, Location, Motors |
| 11 | Shall design a robot whose navigation system controls movement; knows its location within a two-inch tolerance; and possesses a maximum speed of 2 feet per second. | Navigation, Location, Motors|
| 12 | The attachment components will be 3D printed to reduce cost of project. 	| Attachments, Layout and Organization |
| 13 | The line sensor attachment must be designed to place the sensor between 0.125 and 0.375 inches off the ground. | Attachments | 
| 14 | The frame will need to be able to withstand 20 pounds. | Chassis |

## Results

### Constraint 1 - Start Button

### Constraint 2 - Alternate Start Method 

### Constraint 3 - Dimensions
The dimensions of the robot are customizable when ordering the extruded alumnium for future teams. The extruded alumnium can also be cut to change the dimensions. As shown below, the stock design only takes up the specified 1 ft x 1 ft x 6 in area. This constraint could not be experimentally tested because it is inherently true.

#### Length (12 in)
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/Robot%20Length.jpg)

#### Width (12 in)
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/Robot%20Width.jpg)

#### Height (6 in)
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/Robot%20Height.jpg)

Overall, the constraint was met.

### Constraint 4 - Plug-and-Play Adaptability

#### Wheel Movement (4 in)
This constraint does not have a true experimental analysis section. The picture below shows the 4 in movement capabilities if the base robot was needed to be reconfigured.

|Wheel| Does it move 4 inches |
|-|-|
| FL | yes |
| FR | yes |
| BL | yes |
| BR | yes |

#### Component Movement (2 in)
This constraint does not have a true experimental analysis section. The picture below shows the 2 in movement capabilities of the applicable sensors. This specification was derived from needing to move sensors easily.

|Component| Does it move 2 inches |
|-|-|
| Ultrasonic | yes |
| Time of Flight | yes | 
| Line following | yes |

#### Wire Grouping/ Labeling
This is not able to be experimentally measured because is it inherently true and can be seen in the picture below.

![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/Grouping%20and%20Labeling.jpg)

Overall, the constraint was met.

### Constraint 5 - Robust Charging System

### Constraint 6 - Wireless Charging

### Constraint 7 - Emergency Stop
This constraint originated from standards and competition rules, which state that an emergency stop button must exist and remove power from the motors but not the processors. This is tested by running base code on the robot to run the motors, and the stop button is pressed. The voltage across the motors is tested with a multimeter, and the processors are tested by visual inspection from the onboard LED. 

Expected: Each motor should have 0±0.5 V across it and the processors should be on after the emergency stop button is pressed.

See [EmergencyStop.md](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Experimental%20Analysis/Testing%20Data/EmergencyStop.md) for the table with the trial data.

Outcome: The ten trials of testing met the expectations.

### Constraint 8 - Back EMF

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
</div> <br />
<br />
<br />

<div align="center">
<img src = https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/10%20Positions%20of%20Measuring%20Location.JPG >
</div>
<div align="center">
Ten Different Position for Measuring the Robot's Location
</div> <br />
<br />
<br />

Expected: The robot should know location within a two-inch tolerance for ten out of ten trials. <br />
<br />

The graph below shows the average distance error for the Front, Back, Right, and Left sensor. The most inaccurate measured distance is [INSERT ANSWER].

Insert graph with average error for F, B, R, and L

<div align="center">
Graph Showcasing the Average Distance Error for Each Sensor
</div>
<br />

See [Location Tolerance](Documentation/Experimental Analysis/Testing Data/Location Tolerance.md) for the table of testing data.

Outcome: Insert Outcome

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
This specifcation was derived when designing the attachment of the line sensor and the data sheet recommended a minimum height of 0.125 inches and a maximum height of 0.375 inches. Following experimentation with the sensor and a higher importance constraint, this specification was deemed unnecessary. The data from the sensor was deemed accurate at greater heights. Also, the height of the sensor had to be increased to be able to clear inclines and declines of 25 degrees. Therefore, this constraint was not achieved.

### Specification 14 - Frame Weight Requirements
This specifcation orginated from previous competitions having a weight limit. The typcial limit is 25 lbs, but this was reduced to have a faster speed to 20lbs. Therefore, the frame was specified to be able to hold atleast a 20 lb load. To measure this, a 20 lb weight will be placed on the robot for 5 mins and afterwards the robot frame was inspected for any deformations.

| Trial | Any Deformation of Frame? |
|-|-|
| 1 | No |
| 2 | No |
| 3 | No |
| 4 | No |
| 5 | No |

Overall, the constraint was met.

## Improvements

## Conclusion

| Item | Description | Was constraint met? | 
|-|-|-|
| 1 | | |
| 2 | | |
| 3 | | yes |
| 4 | | yes |
| 5 | | |
| 6 | | |
| 7 | | yes |
| 8 | | |
| 9 | | |
| 10 | | |
| 11 | | |
| 12 | | yes |
| 13 | | no |
| 14 | | yes |
