# Arduino Signoff

## Functionality
The microcontroller susbystem will provide the computing power needed to read in sensor data, filter the data as needed, and send the resulting values to the master control subsystem via serial communication.

----
## Reach Goals

There are two reach goals in the project. The first is the implementation of the ESP 32 wifi module. The implementation will require 2 sets of the ESP 32 boards. One will act as a receiver and one will act as a transmitter. The trasnitter will be embedded in the robot. The module will be connected to the Arduino navigation microcontroller and will send sensor data to the receiver in various intervals (update). The receiver will be conencted to a pc to display the data via a serial monitor.

The second reach goal is an on-robot OLED display. The display will aid teams in troubleshooting, as well as the option of showing the robot's battery life.

---

## Constraints

----

## Schematics
### Arduino Pinouts
<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Nav-Microcontroller/Arduino_Mega_Pinout.png?raw=true"alt="Grove Bus">
</p>

The pinout diagram of the Arduino Mega 2560 Rev3 board is shown above. The electrical connections for sensors and other modules will be discussed in the following schematic sections. A pinout table will be provided at the end of the schematics section to provide connection documentation.

### Grove Connections
<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Nav-Microcontroller/Grove_Connections.png?raw=true"alt="Grove Bus">
</p>

The I2C bus will be implemented using 4 Grove I2C Hub 6 Port modules. The first connection to each of the modules will be the SCL an SDA pins of the Arduino. The power and ground pins will be connected directly to the regulated bus to prevent the Arduino from sourcing too much current. Two of the four modules will be connected to the 5V power bus while the other two will be connected to the 3.3 V bus. The 5 V and 3 V connections will power all electronic sensors. The bus will allow all I2C compatible sensors to be read in with just 2 Arduino pins. By using the grove bus, every I2C sensor will be 100% plug and play adaptable. 

<p align = "center">
<img src = "https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Nav-Microcontroller/Grove_Arduino%20Connections.png"alt="Grove-Arduino">
</p>

---

## Analysis

### Arduino Analysis
The Arduino Mega 2560 Rev3 has 54 digital pins and 16 analog pins. It also has 15 PWM output pins. The PWM pins will give future teams the option to attach servo or stepper motors to complete their tasks without having to implement another microcontroller. The Mega has 4 sets of Tx/Rx pins for UART communication. In addition to the UART pins, there are SDA and SCL pins for I2C communication. The microcontroller has an additional 4 kb of EEPROM that does not get erased from powering down. 

The input/supply voltage to the Arduino Mega can span from 7 to 12 V from the DC jack and the VIN pin. Powering through the USB has a range of 4.8 to 5.5 V, but since the communication from Mega to Jetson Nano will use the USB for data transmission, this is not an option for powering the microcontroller.

The Arduino serial monitor and serial plotter will aid in validating the voltages received from the sensors. The plotter will also aid in creating software filters. Each of the sensors will be tested with the plotter active so that votlage readings are known for a controlled reading. 
### Arduino Libraries
The sensor sets used for the robust robot will utilize manufacturer provided Arduino Libraries to ease the coding process.

Line Following Library:

Orientation Library:

Position Library:

Object Detection Library:

### Communication with Jetson Nano
The Arduino will communicate with the Jetson Nano through the USB port. The USB port will provide serial data to the Jetson Nano using UART (Universal Asynchronous Receiver Transmitter) Communication Protocol. Another option is to use the Tx/Rx pins on the Arduino Mega to send the serial data, rather than the USB. This would allow code to be uploaded to the Arduino Mega while still being serially connected to the Jetson Nano.

By using UART, the serial data must have a beginning marker, such as '<', and an ending marker, such as '>'. This is an effect of the communication method being asynchronous. The start and end markers will allow the Jetson Nano to differentiate the data packages.

---

### Coding Conventions

To keep code looking uniform, the coding conventions brought forth by Dr. Bruce will be used. The coding convention documentation can be found here: http://jwbruce.info/teaching/ece4140/files/ccode.pdf. The convention covers variable, struct, and class naming, as well as commenting techniques.

---

## Robot Integration

The Arduino Mega and I2C bus will be attached to the robot via 3D printed trays. The trays will be in the interior of the robot.
---
## BOM
|Item        |Quantity   |Price   |Total   |
|------------|-----------|--------|--------|
|Arduino Mega|1          |$\$43.56^{1}$ |$\$43.5$


1. This is a sale price listed on Amazon. Normal retail is $55.00

---
## References
Arduino Mega Datasheet: https://docs.arduino.cc/resources/datasheets/A000067-datasheet.pdf

