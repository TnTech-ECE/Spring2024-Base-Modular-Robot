### Orientation Signoff

## Functionality
The orientation signoff will provide the master control with the angle with respect to a certain position.
	This will aid with robot navigation when traversing an arena that does not have a line present.
	For future capstone teams, it will allow them to know what direction the robot is facing in order 
	to complete unique tasks.

## Constraints
### Derived from Shall Statements
- C4: The robot shall contain modules that are plug-and-play adaptable for different IEEE competition
	requirements.
	- This applies to the orientation subsystem because the sensors used may not be needed for
	future capstone teams' projects. The modules must be easily removable and replaceable.

- C9: The robot shall travel inclines and declines up to 25 degrees.
	- This constraint is applicable to the orientation subsystem because the system will be responsible for providing
		the master control with angle measurements. These angle measurements will aid the master control in sending
		the correct PWM signals to the motor drivers to traverse the incline at the optimal speed.
* C10: The robot shall turn 360 degrees left and right and move forwards and backwards based on sensor inputs.
* C11: The robot shall have a navigation system that controls movement.
	* The orientation subsystem will transmit data to the master control telling it where the robot is with respect to the
		starting position or zeroed position (explained in analysis).

### Derived from Broader Implications
	
- C14: The robot shall have a user manual that explains all functions and capabilities of the robot. 
	- This constraint will require all detailed design decisions to be documented and explained. Not only will the design have to be explained, but the motives behind the design and the other options explored so that future SECON teams have an understanding of why the design was created in a certain manner.
## Schematic



## Analysis
The Adafruit LSM6DSOX + LIS3MDL breakout board has the ST LSM6DSOX and ST LIS3MDL packaged on the
	same I2C device. This allows the orientation subsystem to obtain all needed data from one I2C 
	device. This attribute of the sensor set contributes to the plug-and-play adaptability constraint.
	If future teams choose not to use it, only one I2C device must be removed from the data bus.
	
Adafruit provides a generalized technical description on their webpage; therefore, the respective datasheets
	from ST will be used for analysis. 
### LSM6DSOX Accelerometer & Gyroscope
The LSM6DSOX 3D accelerometer and gyroscope will draw a maximum of
	0.55 mA in the high-performance mode. The supply voltage has a range of 1.71 V to 3.6 V. The power supply
	bus voltage of 3.3 V will suit the sensor. There is an on-chip regulator that will control supply voltage.

The module has 4 modes. The first mode is for connecting the sensor set to a single host using I2C. This is the 
	mode that the base robot will be utilizing. The other three modes are for connecting the sensor set to both
	the host and additional modules for dual communication. These modes will be documented in the robot's user
	manual so that future teams know the functionality possibilities of the sensor module. The accelerometer 
	and gyroscope provide the chip with 6 degrees of freedom to measure the orientation of the robot. ST gives
	a model of the measurement capabilities:
	
	
## BOM

## Robot Attachment

## References

