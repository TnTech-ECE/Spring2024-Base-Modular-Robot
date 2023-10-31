# Motor Control Subsystem
## Function of the Subsystem
- Transport the robot with a maximum speed of 2 ft/s
- Turn the robot 360 degrees and move forward and backward
- The motor drivers will control the motors’ speeds and then move the wheels according to the control signals from the motor control microcontroller (outlined in a different detail design)

## Constraints
- The robot must be able to move up to 2 ft/s to complete the course within the time limit from the competition rules. 
- The robot's speed will be calculated assuming the robot weighs 20 pounds. This is done due to the maximum weight limit for competition.

### Socioeconomic Consideration
- The motors chosen should operate at about 70% of the maximum efficiency to ensure power can be conserved and to reduce charging costs. Additionally, this will give the robot enough extra power when traversing inclines. 
- The work done on this design and the implementation will be documented thoroughly to ensure the user manual is as helpful as possible for future groups using the robot.

## Buildable Schematics

### Motor
![image](https://user-images.githubusercontent.com/112428353/203175771-01a94bf9-d55d-4ecd-9e12-75bcc7caf23c.png)

The two motor encoders will tell the low-level microcontroller how fast the motor is driving, as well as the direction. These will be used in the path planning process.

### Electrical Schematic
![image]()

The electrical schematic can be found [here]():

### Locomotion Assembly
![image]()

Each motor will have a motor mount. The mount will attach to the motor by six screws. The motor and mount assembly will attach to the chassis by four screws. Please note that the chassis has not been designed yet, so the model does not show the final product, rather how the motor assebmly will be mounted.

The CAD model for the motor and wheel assembly can be found here.
https://github.com/nathan-gardner/CapstoneRepo/tree/main/Documentation/3D%20Models/LocomotionSystem


## Analysis
### Acceleration

The robot must go 2 ft/s (0.6096 m/s) at its fastest speed. The worst-case scenario for this would be if it is at the maximum weight capacity and going up a 25-degree incline. 

$v = 0.6096\ m/s$ 

$a = \frac{v - v_{o}}{t}$

$a = \frac{0.6096 - 0}{1}$

$a = 0.6096\ m/s^2$

### Force
#### Subsystem Mass
$M_{Motors} = 0.840\ kg

$M_{Microcontroller} \approx 0.037\ kg

$M_{Motor Mount} \approx 0.044\ kg

$M_{Wheels and Couplings} \approx 0.392\ kg

$M_{Total Subsystem Weight} \approx 1.313\ kg
$\ $

#### Maximum Robot Weight and Mass

$W_{Maximum} \20.00\ lb

$M_{Maximum} \9.07\ kg

$\ $

### Torque
$r = 0.030\ m$

$N = 4\ number of drive wheels

$Theta = 25\ degrees

$e = 50\ efficiency

$g = 9.80\ m/s^2

$T=\frac{100(a+gsin(theta)*M*r}{e*N}$

$0.64698\ Nm = 6.5951\ kgcm$

$\ $

The chosen motor is the Pololu #2828. It is a 12V medium-power motor. The required torque for each motor is 6.5951 kg-cm. This motor has a max efficiency of 6.5 kg-cm of torque. At 6.5951 kg-cm of torque, the motor will operate at $\approx$ 99% of it's maximum efficiency. This motor choice will allow the torque requirements to be met while simultaneously achieving high efficiency. The motor draws 0.72 A. The L298N motor driver supplies 2A, which is more than enough for this motor.


$6.5951\ kgcm / 10\ kgcm = 65.95$\%

$100$\% $- 65.95$\% $= 34.05$\%

At the current torque requirement of 6.5951 kg-mm of torque, only 65.95\% of the motor's torque capacity is being used. This allows for 34.05\% of each motor's torque capacity as the margin of safety.


## BOM
| Name of Item   | Description                                                                                 | Part Number | Manufacturer     | Quantity | Price      | Total  |
|----------------|---------------------------------------------------------------------------------------------|----------------------------|-------------|------------------|----------|------------|--------|
| Mecanum Wheels | The mecanum wheels allow the robot to move in any direction.                                | 14209       | Nexus Robot       | 1  (set of 4)      | 68.00      | 68.00  |
| Wheel Hubs     | The wheel hub attaches a wheel to a motor.                                                  | 18077       | Nexus Robot       | 4        | 6.90       | 6.90   |
| Motor          | The motors will turn the wheels, allowing the robot to move.                                | 2828        | Pololu           | 4        | 51.95      | 207.80  |
| Motor Mount    | The motor mount attaches the motor to the chassis.                                          | 2676        | Pololu           | 2 (2 pack)       | 9.95       | 19.90   |
| Motor Driver   | The motor driver supplies the voltage and current to the motor.                             | L298N       | STMelectronics               | 4        | 11.63       | 46.52  |
| Microcontroller|The microcontroller gets communication from the master control and tells the motor drivers how to move the wheels. | Mega 2560 Rev 3 | Arduino | 1 | $48.40 | $48.40

| Total          |                                                                                             |                            |             |       | Total Cost | $418.22 |

##References
https://community.robotshop.com/blog/show/drive-motor-sizing-tool
