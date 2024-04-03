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