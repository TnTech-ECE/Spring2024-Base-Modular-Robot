# Navigation Microcontroller Signoff

## Functionality
The microcontroller susbystem will provide the computing power needed to read in sensor data, filter the data as needed, and send the resulting values to the master control subsystem via serial communication. The data in the master control will help navigate the robot across the arena.

## Reach Goals

There are two reach goals in the project. The first is the implementation of the ESP 32 wifi module. The implementation will require 2 sets of the ESP 32 boards. One will act as a receiver and one will act as a transmitter. The transmitter will be embedded in the robot. The module will be connected to the Arduino navigation microcontroller and will send sensor data to the receiver in various intervals (update). The receiver will be conencted to a pc to display the data via a serial monitor.
	Because the ESP uses wifi, the transmission speed should not be an issue. A determined updating rate will be used based on the updating needs. A possible update speed is 100 Hz. This should provide the data to be updated close to real time.
The second reach goal is an on-robot OLED display. The display will aid teams in troubleshooting, as well as the option of showing the robot's battery life.


***The implementation of reach goals will only occur if it is evident that the requirements provided by the customer are met, or will be met.***

## Constraints

### Derived from Shall Statements
- C4: The robot shall contain modules that are plug-and-play adaptable for different IEEE competition requirements.
	- This applies to the microcontroller subsystem because the bus connections must be easily replaceable or removable. The microcontroller code must also be easily adaptable.

* C11: The robot shall have a navigation system that controls movement.
	* The microcontroller subsystem will transmit the data from all navigation sensors to the master control. The master control will make decisions based off of the provided data.

### Derived from Broader Implications
	
- C14: The robot shall have a user manual that explains all functions and capabilities of the robot. 
	- The microcontroller connections and coding techniques will be documented to make it easily adoptable for future Capstone teams.

## Schematics
### Arduino Pinouts
<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Sign%20off%20Photos/Navigation%20Microcontroller/Arduino_Mega_Pinout.png?raw=true"alt="Grove Bus">
</p>

The pinout diagram of the Arduino Mega 2560 Rev3 board is shown above. The electrical connections for sensors and other modules will be discussed in the following schematic sections. A pinout table will be provided at the end of the schematics section to provide connection documentation.

### Grove Connections
<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Sign%20off%20Photos/Navigation%20Microcontroller/Grove_Connections.png?raw=true"alt="Grove Bus">
</p>

The I2C bus will be implemented using 4 Grove I2C Hub 6 Port modules. The first connection to each of the modules will be the SCL an SDA pins of the Arduino. The power and ground pins will be connected directly to the regulated bus to prevent the Arduino from sourcing too much current. Two of the four modules will be connected to the 5V power bus while the other two will be connected to the 3.3 V bus. The 5 V and 3 V connections will power all electronic sensors. The bus will allow all I2C compatible sensors to be read in with just 2 Arduino pins. By using the grove bus, every I2C sensor will be 100% plug and play adaptable. 

<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Sign off Photos/Navigation Microcontroller/Grove_Arduino_Connections.png?raw=true"alt="Grove-Arduino">
</p>

### Sensor Connections

<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Sign off Photos/Navigation Microcontroller/Sensor_Connections.png?raw=true">
</p>

## Analysis

### Arduino Analysis
The Arduino Mega 2560 Rev3 has 54 digital pins and 16 analog pins. It also has 15 PWM output pins. The PWM pins will give future teams the option to attach servo or stepper motors to complete their tasks without having to implement another microcontroller. The Mega has 4 sets of Tx/Rx pins for UART communication. In addition to the UART pins, there are SDA and SCL pins for I2C communication. The microcontroller has an additional 4 kb of EEPROM that does not get erased from powering down. 

The input/supply voltage to the Arduino Mega can span from 7 to 12 V from the DC jack and the VIN pin. Powering through the USB has a range of 4.8 to 5.5 V, but since the communication from Mega to Jetson Nano will use the USB for data transmission, this is not an option for powering the microcontroller.

The Arduino serial monitor and serial plotter will aid in validating the voltages received from the sensors. The plotter will also aid in creating software filters. Each of the sensors will be tested with the plotter active so that votlage readings are known for a controlled reading. 
### Arduino Libraries
The sensor sets used for the robust robot will utilize manufacturer provided Arduino Libraries to ease the coding process.

Line Following Library: [QTR Sensors][def3]

Orientation Library: [Accelerometer][def4] , [Compass][def5]

Position Library: [Grove - Ultrasonic Ranger][def2]

Object Detection Library: [Grove - Time of Flight Distance Sensor VL53L0X][def1] 

[def1]: https://github.com/Seeed-Studio/Grove-Ranging-sensor-VL53L0X

[def2]: https://github.com/SeeedDocument/Grove_Ultrasonic_Ranger

[def3]: https://www.pololu.com/docs/0J19/1

[def4]: https://github.com/adafruit/Adafruit_LSM6DS

[def5]: https://github.com/adafruit/Adafruit_LIS3MDL

### Communication with Jetson Nano
The Arduino will communicate with the Jetson Nano through the USB port. The USB port will provide serial data to the Jetson Nano using UART (Universal Asynchronous Receiver Transmitter) Communication Protocol. Another option is to use the Tx/Rx pins on the Arduino Mega to send the serial data, rather than the USB. This would allow code to be uploaded to the Arduino Mega while still being serially connected to the Jetson Nano.

By using UART, the serial data must have a beginning marker, such as '<', and an ending marker, such as '>'. This is an effect of the communication method being asynchronous. The start and end markers will allow the Jetson Nano to differentiate the data packages.

### Reach Goal Analysis

#### ESP 32
The ESP 32 module is an MCU created by Espressif. Adafruit's "Huzzah32" breakout board will provide the system with communication from robot to user. The IEEE competiton strictly prohibits the use of external control. Therefore, the module will be easily removable for the competition. The ESP 32 will be heavily used in testing so real-time data can be read while the robot works autonomously. The module is SPI, UART, and I2C compatible. The module has an on-board antenna and supports both wifi and bluetooth for wireless communication. The ESP 32 has an operating voltage range from 3.0 to 3.6 V, making it compatible with the 3.3 V distribution bus present in the robot. Because this is a reach goal, the 0.5 A draw is not accounted for on the power distribution anaylsis. Thus, a small battery just for the ESP 32 would be the best route if implemented.

**NOTE: Getting devices approved for TTU wifi usage may be an issue, so the bluetooth attribute will likely be used.**

#### OLED Display
The SSD 1306 0.96" display has a 128 x 64 dot matrix for display. The module runs off of 3.3 V and has a maximum operating current of 15 mA. The module is I2C compatible and can be easily implemented into the data bus by using a grove to male pin wire. Because it is an OLED, user-created images can be imported and used. This will aid in showing battery life pictures such as the one seen below: 

<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Sign off Photos/Navigation Microcontroller/OLED_Battery_Life.jpg?raw=true">
</p>


### Coding Conventions

To keep code looking uniform, the coding conventions brought forth by Dr. Bruce will be used. The coding convention documentation can be found here: http://jwbruce.info/teaching/ece4140/files/ccode.pdf. The convention covers variable, struct, and class naming, as well as commenting techniques.


## Robot Integration

The Arduino Mega and I2C bus will be attached to the robot via 3D printed trays. The trays will be in the interior of the robot. The ESP 32 will have it's own tray if adopted. The tray must be easily accessible so that wiring can be disconnected for the competition. The OLED display will be mounted on an external wall of the robot where it can be easily viewed.

## BOM
|Item        |Quantity   |Price   |Total   |
|------------|-----------|--------|--------|
|Arduino Mega|1          |\$ 43.56 $^{1}$ |$43.56|
|Grove I2C Bus|4         |$1.70|$6.80|
|ESP 32 $^{2}$ |1| $19.95| $19.95|
|OLED Display $^{2}$|1 |$8.99|$8.99
Subsystem Total |||$50.36|


1. This is a sale price listed on Amazon. Normal retail is $55.00
2. Reach goals
   
## References
Arduino Mega Datasheet: https://docs.arduino.cc/resources/datasheets/A000067-datasheet.pdf

