# Motor Control Subsystem
## Function of the Subsystem
The motor control subsystem takes serial signals from the master control and determines the signals to send to the motor drivers to move the robot. To be successful, the robot must be able to move with a maximum speed of 2 ft/s, move up an incline of 25 degrees, turn 360 degrees, and move forward and backward. 

## Constraints
- C9: The robot shall travel inclines and declines up to 25 degrees. 
- C10: The robot shall turn 360 degrees left and right and move forwards and backward based on sensor inputs.
- C13: The robot shall possess a maximum speed of 2 feet per second.
- The robot's speed will be calculated assuming the robot weighs 20 pounds. This is done due to the maximum weight limit for competition.

### Socioeconomic Consideration
- The motors chosen should operate at about 70% of the maximum efficiency to ensure power can be conserved and to reduce charging costs. Additionally, this will give the robot enough extra power when traversing inclines. 
- C14: The robot shall have a user manual that explains all functions and capabilities of the robot. 
        - The work done on this design and the implementation will be documented thoroughly to ensure the user manual is as helpful as possible for future groups using the robot.

## Buildable Schematics

### Electrical Schematic
![image](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Motor-Control/MotorControl-Schematic.png)

This electrical schematic shows the connections between the microcontroller, motor drivers, and motors. This microcontroller - Arduino Mega - was chosen due to the number of analog ports available since those are needed to communicate with the motor drivers. This is the same microcontroller used by past SECON robot teams for motor control so it will have the capabilities needed for the communication from master control to the motor drivers. The motors chosen are similar to ones from past years, but these are larger and have more torque to meet the new obstacle of moving up an incline and the possibility of the robot being double the weight of past robots. The maximum torque needed was calculated to prepare for the worst-case scenario (found in the analysis subsection). When the motors are running, they should pull 0.72 A, which is well below the 2 A maximum rating output current for the driver. This driver was chosen since past teams were successful in using it, and it will be able to power the motors successfully. All the chosen components are connected to either 3.3 V, 5 V, or 12 V based on their specific power ratings found in the datasheets. 

### Motor and Wheel Assembly
![inamge](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Motor-Control/MotorControl-WheelConnections.png)

![image](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Motor-Control/MotorControl-PhysicalConnections.png)

Since each of the four wheels is a drive wheel, they are each connected to a motor. The top photo shows that the wheel will be connected to the motor through a hub with three screws. Each motor will have a motor mount to connect it to the chassis. The mount will attach to the motor by six screws, as shown in the second photo, and this is attached to the chassis by four screws. The connection to the chassis is shown in that subsystem's documentation.

## Analysis
### Acceleration

The robot must go 2 ft/s (0.6096 m/s) at its fastest speed. The worst-case scenario for this would be if it is at the maximum weight capacity and going up a 25-degree incline. 

$v = 0.6096\ m/s$ 

$a = \frac{v - v_{o}}{t}$

$a = \frac{0.6096 - 0}{1}$

$a = 0.6096\ m/s^2$

#### Subsystem Mass

$M_{Motors} \approx 0.840\ kg$

$M_{Microcontroller} \approx 0.037\ kg$

$M_{Motor Mount} \approx 0.044\ kg$

$M_{Wheels and Couplings} \approx 0.392\ kg$

$M_{Total Subsystem Weight} \approx 1.313\ kg$
$\ $

#### Maximum Robot Weight and Mass

$W_{Maximum} = 20.00\ lb$

$M_{Maximum} = 9.07\ kg$
$\ $
### Torque

$r = 0.030\ m$

$N = 4\ number of drive wheels$

$theta = 25\ degrees$

$e = 50\ efficiency$

$g = 9.80\ m/s^2$

$T = \frac{100(a+ gsin(theta)) * M * r}{50N}$

$T = 0.64698\ Nm = 6.5951\ kgcm$

$\ $

![image](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Motor-Control/MotorPerformanceChart.png)

The chosen motor is the Pololu #2828. It is a 12V medium-power motor. The required torque for each motor is 6.5951 kg-cm. This motor has a max efficiency of 6.5 kg-cm of torque. At 6.5951 kg-cm of torque, the motor will operate at $\approx$ 99% of its maximum efficiency. This motor choice will allow the torque requirements to be met while simultaneously achieving high efficiency. The motor draws 0.72 A. The L298N motor driver supplies 2A, which is more than enough for this motor.

$6.5951\ kgcm / 10\ kgcm = 65.95$\%

$100$\% $- 65.95$\% $= 34.05$\%

At the current torque requirement of 6.5951 kg-mm of torque, only 65.95\% of the motor's torque capacity is being used. This allows for 34.05\% of each motor's torque capacity as the margin of safety.


## BOM
| Name of Item   | Description                                                                  | Part Number     | Manufacturer     | Quantity     | Price      | Total   |
|----------------|------------------------------------------------------------------------------|-----------------|------------------|--------------|------------|---------|
| Mecanum Wheels | The mecanum wheels allow the robot to move in any direction.                 | 14209           | Nexus Robot      | 1  (set of 4)| 68.00      | 68.00   |
| Wheel Hubs     | The wheel hub attaches a wheel to a motor.                                   | 18077           | Nexus Robot      | 4            | 6.90       | 6.90    |
| Motor          | The motors will turn the wheels, allowing the robot to move.                 | 2828            | Pololu           | 4            | 51.95      | 207.80  |
| Motor Mount    | The motor mount attaches the motor to the chassis.                           | 2676            | Pololu           | 2 (2 pack)   | 9.95       | 19.90   |
| Motor Driver   | The motor driver supplies the voltage and current to the motor.              | L298N           | STM electronics  | 4            | 11.63      | 46.52   |
| Microcontroller| The microcontroller communicates with the master control and motor drivers.  | Mega 2560 Rev 3 | Arduino          | 1            | 48.40      | 48.40   |
| Total          |                                                                              |                 |                  |              | Total Cost | $418.22 |

## References
https://community.robotshop.com/blog/show/drive-motor-sizing-tool
