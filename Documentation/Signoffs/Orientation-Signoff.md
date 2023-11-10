# Orientation Signoff

## Functionality
The orientation signoff will provide the master control with the angle with respect to a certain position.
	This will aid with robot navigation when traversing an arena that does not have a line present.
	For future capstone teams, it will allow them to know what direction the robot is facing in order 
	to complete unique tasks. The change of angle in the z-direction will aid the master control and motor control in traversing inclines and declines.

---

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

---

## Schematic
The Adafruit LSM6DSOX + LIS3MDL breakout board will be used to sense acceleration and direction.

<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Orientation/Accelerometer_Compass.png?raw=true"alt="Axis"/>
</p>

Grove connections will be used (more details in the Navigation Microcontroller signoff). This wire grouping technique will allow the sensor to be 100% plug and play adaptable. The grove wires will be connected to a Grove I2C bus module. The electrical connections are shown below:


<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Orientation/Sensor_Connections.png?raw=true"/>
</p>

As shown above, the STEMMA QT/Qwicc conenctor from the board is attatched to the Grove I2C bus. The first connection is connected to the Arduino Mega SDA and SCL pins to tie it to the data bus. The ground and VCC of the bus are connected to the power busses to prevent the microcontroller from sourcing too much current.

<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Orientation/Qwiic_to_Grove.png?raw=true">
</p>

The smaller connector (bottom right of photo) will be attached to the sensor and the larger connector (top left of photo) will be attached to the data bus.

---

## Analysis
The Adafruit LSM6DSOX + LIS3MDL breakout board has the ST LSM6DSOX and ST LIS3MDL packaged on the
	same I2C device. Rhe LSM6DSOX + LIS3MDL module provides 9 degrees of freedom for measurement, allowing the robot to detect changes in unique circumstances. The angular velocity is calculated separately from the robot's instantaneous position, giving the sensor module extrene versatility and precison.
	Having the two modules packaged together on one breakout board allows the orientation subsystem to obtain all needed data from one I2C device. This attribute of the sensor set contributes to the plug-and-play adaptability constraint. If future teams choose not to use it, only one I2C device must be removed from the serial data bus.
	
Adafruit provides a generalized technical description on their webpage; therefore, the respective datasheets
	from ST will be used for analysis. 
### LSM6DSOX Accelerometer & Gyroscope
The LSM6DSOX 3D accelerometer and gyroscope will draw a maximum of
0.55 mA in the high-performance mode. The supply voltage has a range of 1.71 V to 3.6 V. The sensor module has 3 operating modes to help conserve power. This will not be of interest for this project since the orientation module needs to run at all times when it is enabled; however, future teams can program the module to be in low power modes to maximize efficiency. The power supply bus voltage of 3.3 V will suit the sensor. There is an on-chip regulator that will control supply voltage.

The module has 4 modes. The first mode is for connecting the sensor set to a single host using I2C. This is the mode that the base robot will be utilizing. The other three modes are for connecting the sensor set to both
the host and additional modules for dual communication. These modes will be documented in the robot's user manual so that future teams know the functionality possibilities of the senor module. The accelerometer 
and gyroscope provide the chip with 6 degrees of freedom to measure the orientation of the robot. ST gives a model of the measurement capabilities:

<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Orientation/Sensing_Axis.png?raw=true"alt="Axis"/>
</p>

The module is capable of capturing the acceleration in the x,y, and z planes (top image). In addition to measuring the acceleration, it can also produce angle values shown in the bottom image. ST claims that the accelerometer is capable of measuring $\pm2\pm4\pm8\pm16$ g from 1.6 Hz to 6.7 kHz update rate. The gyroscope is capable of measuring $\pm125\pm250\pm500\pm1000\pm2000$ degrees per second from 12.5 Hz to 6.7 kHz update rate. The 2000 degrees is the angle capable per second. For instance, in one second, the gyroscope will be able to detect the robot rotating 360 degrees over 5 times (1800 degrees). For the scope of this project, the robot should not be making violent turns at 2000 degrees per second. The robot should only need to turn up to 360 degrees. Upwards of 360 degrees, the robot can turn in the other direction to achieve the same orientation. The output of the gyroscope is angular speed, so the 2000 degrees per second is the maximum speed that the sensor can read. The update rate of 2 kHz will provide the master control with ample readings. At maximum speed, the sensor will read new data every 0.012 inches: 


$2 \frac{ft}{s}\cdot \frac{1}{2000s} = 0.001 ft \text{ or }0.012in$

The sensor set also allows for tilt detection, so when the robot is climbing up an incline and needs to increase power to the motors, the tilt detection can interrupt the routine to send the master control the angular data. 

### LIS3MDL Magnetometer (Compass) 
The LIS3MDL Magnetometer will draw a maximum of 270 $\mu A$ in high resolution mode. In low power mode, the sensor only draws 40 $\mu A$. The supply voltage is rated from 1.9 V to 3.6 V. The 3.3 V power supply will be able to supply a voltage within the acceptable range. The magnetometer is capable of measuring full scales of $\pm 4/ \pm 8/ \pm 12/ \pm 16$ gauss. The datasheet suggests that currents higher than 10 $mA$ cannot be near the sensor. The magnetic field generated by the current will contribute to the measured Earth field which will cause false readings. The suggested distance is a "few millimeters". The tray that holds the device will also help isolate the sensor set from the current-generated field. 

The device can be tested using the "self test". The self test tests the sensor without having to have any external force applied to the module. 

<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Orientation/Compass_Directions.png?raw=true"alt="Compass Direction"/>
</p>

The sensor is capable of measuring the magnetic fields in the x, y, and z directions. The reference to Earth will help calculate which direction the robot is facing. 

---

## BOM
|Item              |Quantity   |Price   |Total   |
|------------------|-----------|--------|--------|
|LSM6DSOX + LIS3MDL|1          |$19.95  |$19.95  |
|STEMMA QT to Grove Wires|1    |$1.95   |$1.95   |
|Subsystem Total| | |$21.90 |

---

## Robot Attachment
Ideally, the sensor needs to be mounted on a plane parallel to the robot. That is, the sensor orientation needs to mimic the robot's orientation. The sensor can be mounted on the interior of the robot. The sensor will be held by a 3D printed tray. Details on the tray configuration can be found in the chassis design signoffs.

---

## References
Adafruit Technical Details:  https://www.adafruit.com/product/4517#technical-details

Accelerometer/Gryoscope Datasheet: https://www.st.com/en/mems-and-sensors/lsm6dsox.html

Magnetometer (compass) Datasheet: https://www.st.com/en/mems-and-sensors/lis3mdl.html
