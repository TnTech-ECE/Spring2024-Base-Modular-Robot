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
| 9 | Shall design a robot that can travel inclines and declines up to 22.5 degrees.  | Motors |
| 10 | Shall design a robot that can turn 360 degrees left and right and move forwards and backwards based on sensor inputs. | Motors |
| 11 | Shall design a robot whose navigation system controls movement; knows its location within a two-inch tolerance; and possesses a maximum speed of 2 feet per second. | Navigation, Location, Motors|
| 12 | The attachment components will be 3D printed to reduce cost of project. 	| Attachments, Layout and Organization |
| 13 | The line sensor attachment must be designed to place the sensor between 0.125 and 0.375 inches off the ground. | Attachments | 
| 14 | The frame will need to be able to withstand 20 pounds. | Chassis |

## Results

### Constraint 1 - Start Button

The first requirement is for the robot to have a functioning start button, which after activation will begin robot operation. This was tested 10 times by turning the switch off and then on again to see if the robot succesfully starts back up. The robot successfully turned on in 10 out of 10 trials.

| Trial Number | Power Successfully Turned On |
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

### Constraint 2 - Alternate Start Method 

### Constraint 3 - Dimensions
The dimensions of the robot are customizable when ordering the extruded alumnium for future teams. The extruded alumnium can be cut to change the dimensions. Additionally, the stock design only takes up the specified 1 ft x 1 ft x 6 in area shown below. This constraint could not be experimentally tested because it is inherently true.

#### Length (12 in)
![Alt Text](../Images/Experimental%20Analysis%20Photos/Robot%20Length.jpg)

#### Width (12 in)
![Alt Text](../Images/Experimental%20Analysis%20Photos/Robot%20Width.jpg)

#### Height (6 in)
![Alt Text](../Images/Experimental%20Analysis%20Photos/Robot%20Height.jpg)

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

![Alt Text](../Images/Experimental%20Analysis%20Photos/Grouping%20and%20Labeling.jpg)

Overall, the constraint was met.

### Constraint 5 - Robust Charging System



| Measured Input Voltage (V) | Top 5 V Rail (V) | Top 3.3 V Rail (V) | Bottom 5 V Rail (V) | Bottom 3.3 V Rail (V) |
| --- | --- | --- | --- | --- |
| 10.0013 | 5.0461 | 3.2792 | 5.0466 | 3.2792 |
| 11.0010 | 5.0491 | 3.2798 | 5.0490 | 3.2798 |
| 12.0014 | 5.0508 | 3.2802 | 5.0507 | 3.2802 |
| 13.0011 | 5.0524 | 3.2807 | 5.0524 | 3.2808 |
| 14.0008 | 5.0536 | 3.2811 | 5.0536 | 3.2811 |
| 15.0006 | 5.0547 | 3.2813 | 5.0546 | 3.2814 | 


### Constraint 6 - Wireless Charging

### Constraint 7 - Emergency Stop

The emergency stop requirement requires that the robot have a button that when pressed, power will be removed from the motors, but not the microcontrollers or sensors. In order for this to be considered successful, in 10 out of 10 trials, pressing the emergency stop button had to result in a complete shutdown of the motors while keeping all other components powered.

| Trial Number | Power Removed from Motors | Power Removed from Microcontrollers
|---|---|---|
| 1 | yes | no |
| 2 | yes | no |
| 3 | yes | no |
| 4 | yes | no |
| 5 | yes | no |
| 6 | yes | no |
| 7 | yes | no |
| 8 | yes | no |
| 9 | yes | no |
| 10 | yes | no |



### Constraint 8 - Back EMF

Voltage on buses with and without motor operation.

### Constraint 9 - Inclines/Declines

### Constraint 10 - Motor Control

### Constraint 11 - Navigation

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
This specifcation was derived when designing the attachment of the line sensor and the data sheet recommended a minimum height of 0.125 inches and a maximum height of 0.375 inches. Following experimentation with the sensor and a higher importance constraint, this specification was deemed unnecessary. The data from the sensor was deemed accurate at greater heights. Also, the height of the sensor had to be increase to be able to clear inclines and declines of 22.5 degrees. Therefore, this constraint was not achieved.

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
| 7 | | |
| 8 | | |
| 9 | | |
| 10 | | |
| 11 | | |
| 12 | | yes |
| 13 | | no |
| 14 | | yes |