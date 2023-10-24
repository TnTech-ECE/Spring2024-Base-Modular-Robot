# Master Control Signoff
## Functionality
	[Insert Picture]
	The Master Control subsytem will facilitate navigation and control of the other
	subsystems to direct the robot around the board. The system will receive 
	inputs from the start button, sensing microcontroller, and other peripherals
	designed by future teams, and it will output instructions to the motor Control
	subsystem and peripherals designed by future teams. The subsystem will use a 
	Jetson Nano microcontroller to do all calculations and to send instructions. 
	The system will ultimately perform pathfinding, navigation, and user-defined peripherals,
	but for the scope of the current system, pathfinding and navigation will be addressed 
	and user-defined peripherals will be considered and allotted for. 
## Constraints
	how they apply
	
-C2:The robot shall possess an allocated data input point for
	an alternative start method.
	* The master control system will reserve these pins for future users to attach an alternative start method.
	
-C3:The robot shall be autonomous with customizable dimensions and the stock design only occupying up to one-half
	of the allowed cubic foot (1 ft x 1 ft x 6 in) [1]–[3].
	* Autonomy will be achieved by the master controller. All navigation decision will be made in the master controller. 

-C9:The robot shall travel inclines and declines up to 25 degrees
	* The master controller will send the signal to the motor controller, so it must know when and to what degree any inclines and declines may be. 

	-C10:The robot shall turn 360 degrees left and right and move
		forwards and backwards based on sensor inputs.
			* The master controller will send commands to enable movement.

	
	-C11: The robot shall have a navigation system that controls
		movement.
		* The master controller will use the data from the sensor inputs to make decisions on the movement outputs. 
	
	-C12:The robot shall know its location within a two-inch
		tolerance.
			* The sensor information must be accurately decoded in the master controller to ensure the two-inch tolerance is met. 
	
	-C13:The robot shall possess a maximum speed of 2 feet per
		second.
			* The master controller will send speed commands, so it is necessary that the proper speed that is sent should show at the output. 
	
	

## Analysis

current draw, etc
The following is a table of the Jetson Nano's pins and adapters:

|Name|Quantity|
|-|-|
|Micros SD slot| 1|
|GPIO pins| 40|
|Micro-USB|1|
|Gigabit ethernet port| 1|
|USB 3.0 Port| 4|
|HDMI output port| 1|
|DC barrel jack| 1|
|MIPI CSI-2 camera connectors| 1|




The Jetson Nano only has a 40-pin expansion header to interface with sensors, peripherals, and 
motors, which does not leave an abundanc of extra space. As a result, two of the USB 3.0 ports will be utilized to communicate with
the system microcontrollers. Serial communication will be sent from the sensors to the 
master controller, and then the master controller will make decisions based off of its task and the data. 
Most of the pins will be left for future users to implement tasks. 
	In terms of current, if the DC barrel jack is used, battery and charging 
Subsystem will need to supply the Jetson Nano with 5V and 4A to properly power the controller. 
However, if the micro-USB is used, the current only needs to reach 2A to properly power the controller. 
Therefore, it is recommended that the micro-USB is used to reduce the current draw on the power system. 

## ROS Implementation and Testing

ROS will be used; explain how; create a simulation; Using Arduino?

### Bill of Materials (BOM)

|Item Name|Quantity|Price/Item|Total Price|
|-|-|-|-|
|Jetson Nano| 1 | $152.00| $152.00|

