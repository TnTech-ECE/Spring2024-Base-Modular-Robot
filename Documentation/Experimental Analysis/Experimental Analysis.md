# Experimental Analysis

## Introduction 
The purpose of this report is to verify the requirements for the project and explain the procedures used to validate results. The results will be compared against the measures of success outlined in the project proposal to determine if the project was successful. This will also detail what the next steps are moving forward.

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
This constraint was created since SECON has opportunities for teams to receive extra points for having an alternative start method, which is met in the [signoff for the master control](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Signoffs/IsaacJennings-Signoff-MasterControl.md). Since the alternate start method has a spot to be placed on the Jetson Nano, the constraint has been met.


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

#### I2C Bus
The I2C bus constrait required that all I2C sensors be plug and play adaptable. To test this constraint the connections on the I2C bus will be scrambled, and data readings will be taken to show the readings are consistent throughout. The spots are differentiated by A (right side of robot) and B (left side of robot) for the two I2C busses. Each bus is split into 5 spots, for example A1 is the first slot of bus A.

See [Youtube Link](https://youtu.be/BVPlBgpR0Bg) for test

##### Trial 1 (No Movement)
|Sensor|Original Spot|Value|
|-|-|-
| 1 | A1 | 965
| 2 | A2 | 514
| 3 | A3 | 1020
| 4 | A4 | 969
| 5 | B1 | 774
| 6 | B2 | 165
| 7 | B3 | 161
| 8 | B4 | 983
##### Trial 2
|Sensor|Moved To|Value|
|-|-|-
| 1 | A2 | 965
| 2 | A1 | 533
| 3 | A4 | 962
| 4 | A3 | 1019 
| 5 | B2 | 160
| 6 | B1 | 769
| 7 | B4 | 979
| 8 | B3 | 160
##### Trial 3
|Sensor|Moved To|Value|
|-|-|-
| 1 | A4 | 971
| 2 | A3 | 1018
| 3 | A2 | 528
| 4 | A1 | 966
| 5 | B4 | 980
| 6 | B3 | 160
| 7 | B2 | 162
| 8 | B1 | 769

<br />
<br />

![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/I2CGraph.png)


The data shows no change between trials. Three trials were ran because it is trivial in nature (electrically, nothing changes). The constraint of plug and play adaptability has been met.


#### Wire Grouping/ Labeling
This is not able to be experimentally measured because is it inherently true and can be seen in the picture below.

![Alt Text](../Images/Experimental%20Analysis%20Photos/Grouping%20and%20Labeling.jpg)

Overall, the constraint was met.

#### ROS2 Adaptable Code base
ROS2 is naturally inclined to easy adaptation, but a few extra common practice steps were taken to make adaptation even simpler. For one, all configuration files (.yaml, .urdf, .xacro
include their varying parameters at the top of the files for easy access without having to locate variables throughout the code. The unified robot description (URDF) was also broken into 
multiple XML macro (xacro) files for easy troubleshooting and modularity. If, for instance, the ultrasonic sensors weren't used, simply removing the ultrasonic xacro would remove all of the associated code
for any robot transforms. The serial communication packages also present modularity by containing function instances for each sensor type that can be easily removed or added to. Finally, all of the launch files are set
with the filepaths at the top of the file to allow quick changes for the robot. Essentially, the file systems in ROS2 have been set up as templates with parameters at the top of the entities. 

### Constraint 5 - Robust Charging System

This constraint required that the robot possess a robust, centralized, power system and had several requirements. The first requirement is that the power system be able to supply power to a 3.3 V and 5 V power rail successfully. To test this, the voltages at each voltage rail on the power board were measured for the total range of possible input battery voltages, which is between 11 and 14.6 V. This was done to show that the power board would operate as needed for any possible battery voltage. The data recorded is shown below. 

| Measured Input Voltage (V) | Top 5 V Rail (V) | Top 3.3 V Rail (V) | Bottom 5 V Rail (V) | Bottom 3.3 V Rail (V) |
| --- | --- | --- | --- | --- |
| 10.0013 | 5.0461 | 3.2792 | 5.0466 | 3.2792 |
| 11.0010 | 5.0491 | 3.2798 | 5.0490 | 3.2798 |
| 12.0014 | 5.0508 | 3.2802 | 5.0507 | 3.2802 |
| 13.0011 | 5.0524 | 3.2807 | 5.0524 | 3.2808 |
| 14.0008 | 5.0536 | 3.2811 | 5.0536 | 3.2811 |
| 15.0006 | 5.0547 | 3.2813 | 5.0546 | 3.2814 | 


| Trial | Successfully Charging While Running |  
| --- | --- |
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

Video of robot charging while running demonstration can be found at ./Videos/Charging_While_Running.mp4

The other specification required by this constraint has to do with the battery life. In the project proposal document, a requirement of a 2 hour battery life was set. After researching battery capacities, this requirement was then amended to 30 minutes of continuous battery life to make the requirement more realistic.

To test this, the robot was run with all of the motors running at maximum speed. A program was used that continuously rotated the robot in a circle without changing the robot position. This was done so that the robot's continuous battery life could be tested without having to readjust the robot's position and so that the robot did not change directions constantly, causing uneccessary stress on the motors and motor drivers. 

This program was run continuously in 10 minute intervals, between which the robot was turned off for a few minutes to allow for the motors and motor drivers to cool down to prevent overheating. The total elapsed time of the robot being on is what was recorded as the robot's continuous runtime battery life below. The voltage across the battery terminals was monitored to ensure that the battery did not drop below the minimum recommended voltage.

In testing, the battery voltage dropped similar to an exponential decay from around 14 V to about 13.13 V. At 13.13 V, it remained for 20 minutes before beginning to drop again. After turning the robot off, the battery voltage would increase slightly, to about 13.27 V, and began to decrease to about 13.13 V where it stayed.

The only component that was not present for the battery life testing that could make any different in battery life at all was the Jetson Nano. The arduinos, motors, and sensors, were all connected, powered up and running. Even with this consideration, the Jetson Nano is only running the Master control code and is not using some of its more power-hungry components like the GPU, and so should not change the battery life drastically.

Moreover, the battery life measured vastly exceeded expectations (as can be seen below), and so the Jetson Nano's presence should not make such a large difference that the battery life would fall below the constraint requirement.

There is a video demonstration of the battery life test that can be found in ./Videos/Battery_Life_Test.mp4

In the table below, the measured battery life is compared to the calculated worst-case battery life with all components continuously pulling the maximum current. The maximum current required was calculated at just over 10 A (there was a slight increase from what is listed in the Battery Management signoff due to forgetting to include Arduinos in the calculation). Using this current and the rated Amp-Hours of the battery, the estimate was calculated.

| Calculated Worst-Case Battery Life (hour:min:sec) | Measured Battery Life (hour:min:sec) |
| --- | ---|
| 0:43:11 | 3:05:31 |

At the time given, the battery still showed no signs of being close to depletion. The battery voltage stayed at the flat portion of the battery discharge curve for nearly 3 hours. Using the battery datasheet (can be found in the battery management signoff) and the time the battery took to discharge to the flat portion of the discharge curve, the experimental discharge curve was matched to the datasheet discharge curve and the battery life was estimated to be around 3 hours and 40 minutes.

### Constraint 6 - Wireless Charging

For this requirement, the prospect of wireless charging used to power and/or charge the robot over the full area of the arena had to be researched and the feasibility of which had to be evaluated. For wirelessly powering the robot over the full area of the arena, capacitive power transfer was deemed to be more suited, but is much more experimental as inductive wireless power transfer is the primary method used commercially.

In capacitive wireless power transfer, a transmitting sheet is placed underneath the device, which has a receiving sheet, making an effective capacitor between. The transmitting sheet is excited with high frequencies with the positive lead of a function generator and the negative lead is allowed to sit somewhere unconnected to anything. The receiving sheet is the connected to a quarter-wave transformer, which allows for a stray return capacitance beween the receiver and the negative lead of the driving function generator. More information on this can be found in the wireless charging signoff in Documentation/Signoffs.

With research and experimentation, it was found that a load on the robot could be wirelessly powered. A video of wirelessly powering an LED on top of the robot can be found in ./Videos/Wireless_Power.mp4.

With the demonstration of capacitive wireless power it was determined that wireless charging for the robot is plausible but will require more research, development, and precautions. 

The first reason for a need for more research is the power output. At best, with the "blue box" amplifier and small transmitting sheet in Dr. Van Neste's lab and no load attached, a current out of the receiving sheet of 1-2 A could be measured. In order for this to be used to power or charge a robot, the high-frequency signal (MHz range) will need to be shifted down to 60 Hz and/or rectified to DC in order to power electronics on the robot. With this in mind, it is unknown if the system will be able to output enough power that after component inefficiencies will be able to charge a battery or power the robot at all.

An additional factor that makes higher power more difficult is the potential for interfering with or damaging electronics onboard the robot. As the transmitter power increases, the potential for interferance and/or damage to electronics will require more robust shielding of electronics on board.

Another potential cause for concern is the significant safety precautions that will be required if this system is scaled up. With the small transmitting sheet and small load of an LED, the input voltage could be kept to a moderate 10 V peak-to-peak. However, as the transmitting sheet increases in size, the voltage required to power it increases very fast. Because of this, there will need to be significant insulation surrounding all energized metal sheets (primarily the transmitting sheet) to prevent injury. Additionally, there may be university rules and regulations that must be followed when using high voltages in a university laboratory.

With the above research and verification, this constraint has been met.

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

Adding 0.1 uF capacitors directly to the motor driver outputs was also experimented with. It is recommended by the Pololu to add 0.1 uF ceramic capacitors between the motor terminals as close to the motors as possible to reduce noise and back-EMF. With no capacitors, the 12 V rail voltage dropped between 0.1-0.5 V when the motors changed direction from full speed in one direction to full speed in the opposite direction. The addition of capacitors to the motor driver outputs did not seem to have a noticeable impact on the voltage drop with a change in motor direction.

### Constraint 9 - Inclines/Declines
This constraint was created since the 2024 SECON board has a 25 degree incline and decline. This was tested 10 times by having the robot travel up and down a hill in forward and reverse motion. 

| Trial Number | Robot Successfully Ascended and Descended the Hill |
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

As can be seen in the above table, the robot successfully traverses the hill in 10 out of 10 trials, and so this constraint has been met.

Video demonstration of start switch demonstration can be found on [this video](https://youtube.com/shorts/sC5Fqg60_ig?feature=share)

### Constraint 10 - Motor Control

The robot was tasked with moving 360 degrees as well as forwards and backward to show it can fully navigate and roam in any environment, and it must be able to do so based on sensor inputs. This was tested by having the robot sweep the 2023 SECON board which was similar to how it was navigated for competition, and we also had the robot follow a line and return to the starting point.

[This video](https://youtu.be/3MeIy1WahUA) shows the robot navigating the 2023 board using the ultrasonic sensors. 
[This video](https://youtu.be/stM9KGa8I_E) shows the robot following a line, turning around, and following it back to the start.

The robot was successful in navigating both courses, so the constraint was met.

### Constraint 11 - Navigation

#### Navigation
This constraint was created because the robot needs to be able to autonomously navigate the board for a SECON competition. This was tested by having the robot sweep the 2023 SECON board and follow a line similar to the 2022 and 2024 boards.

[This video](https://youtu.be/3MeIy1WahUA) shows the robot navigating the 2023 board using the ultrasonic sensors. 
[This video](https://youtu.be/stM9KGa8I_E) shows the robot following a line, turning around, and following it back to the start using the line-following sensors.

The robot was successful in navigating both courses, so the constraint was met.

##### **Object Detection**

See [Youtube Link](https://youtu.be/_iFhnvbLboQ) for Object Detection

| Trial Number | Object Successfully Detected |
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


Object was sucessfully detected 10 out of 10 trials. Constraint is met.

#### Speed

This constraint originated from the time limit for the SECON competition. The constraint is tested by having the robot drive in a straight line for 10 seconds, and then the distance is measured. 

Expected: The robot should reach a speed of 2 ft/s for ten out of ten trials.

See [Speed.md](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Experimental%20Analysis/Testing%20Data/SpeedTest.md) for the table with the trial data.

Outcome: The speed is slower than expected, but it is consistent. It is believed that the speed is lower since the calculations for the robot's speed for the signoff were considering the robot carrying the maximum amount of weight and being driven on a surface with more friction. Since the robot was not carrying any additional load and was driven on tile flooring for the testing, it is reasonable that the speed is lower. However, the speed is still sufficient to complete an entire SECON course in three minutes since it can go almost the length of the board in ten seconds.

#### Location

This constraint originated from the lineless board for 2023 SECON competition. The constraint is tested by selecting 10 different points on the 2023 SECON arena. The Front, Back, Right, and Left ultrasonic sensors measure to distance from the point to the walls of the arena. The robot was placed on the 10 different points from a relative corner of robot. The relative corner will be indicated in the table for testing data. The sensors for the Right and Left are offset from the edge by 5/8 in. (or 15.875 mm). The equations use to get the location from the desired point to the sensor will be indicate by a table with the asterisks. <br />
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

See [Youtube Link](https://youtube.com/shorts/rvX_kzKgJGA) for the video testing the Location Tolerance of Position #6


The constraint is met because the large error distance was 19.025 mm (0.749 in), which is less than the 2-in tolerance constraint. The overall average error distance was around 10 mm. This average does correlate with the expected results because the resolution of the ultrasonic sensor is 1 cm.


#### ROS2 navigation
Due to the chosen sensor configuration, navigation with ROS2 was not possible. The main issue arose with ROS's need for lidar or GPS data to establish a base scan transform. As a workaround and proof of concept, 
an RPLidar A2M8 was used to test the robot's capabilites. Shown below are the maps created by the LIDAR. Due to the height requirements of the LIDAR, accurate representations of the SECON boards was not possible in the experimental period,
but the capabilites are shown possible with proper mapping operation in the classroom. The transformations tree shown below is also an indication that all of the major transforms have been achieved for mapping and autonomous navigation. 

<div align="center">
<img src = https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/Capstone_Room_map.jpg
</div>

<div align="center">
<img src = 
</div>

####ROS2 Object Detection
Using the RPLidar, object detection was made very simple and could easily be shown by the rviz2 GUI. The following video demonstrates the robot detecting movement as members of our group walked around. 
It is very obvious to see where our legs are as we move in its field of view. 

See [Youtube Link](https://youtu.be/41BcTIW4LsA) for ROS2 object Detection.


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

##### Figure 1. Frame with Weight
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/Frame%20with%20Weight.jpg)
##### Figure 2. No Deformation View 1
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/Showing%20no%20deformation%20view%201.jpg)
##### Figure 3. No Deformation View 2
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/Showing%20no%20deformation%20view%202.jpg)
##### Figure 4. No Deformation View 3
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/Showing%20no%20deformation%20view%203.jpg)
##### Figure 45 Wheel Mount Slight Bowing
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Experimental%20Analysis%20Photos/Showing%20wheel%20mount%20deformation.jpg)

Overall, the constraint was met.

## Improvements

## Conclusion

| Item | Description | Was constraint met? | 
|-|-|-|
| 1 | | yes |
| 2 | | yes |
| 3 | | yes |
| 4 | | yes |
| 5 | | yes |
| 6 | | yes |
| 7 | | yes |
| 8 | | yes |
| 9 | | yes |
| 10 | | yes|
| 11 | | no |
| 12 | | yes |
| 13 | | no |
| 14 | | yes |
