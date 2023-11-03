# Arduino Signoff

## Functionality
The microcontroller susbystem will provide the computing power needed to read in sensor data, filter the data as needed, and send the resulting values to the master control subsystem via serial communication.

----

## Constraints

----

## Schematic

The I2C bus will be implemented using 4 Grove I2C Hub 6 Port modules. The first connection to each of the modules will be the SCL an SDA pins of the Arduino. The power and ground pins will be connected directly to the regulated bus to prevent the Arduino from sourcing too much current. Two of the four modules will be connected to the 5V power bus while the other two will be connected to the 3.3 V bus. The 5 V and 3 V connections will power all electronic sensors. The bus will allow all I2C compatible sensors to be read in with just 2 Arduino pins.

---

## Analysis

### Arduino Analysis
The Arduino Mega 2560 Rev3 has 54 digital pins and 16 analog pins. It also has 15 PWM output pins. The PWM pins will give future teams the option to attach servo or stepper motors to complete their tasks without having to implement another microcontroller. The Mega has 4 sets of Tx/Rx pins for UART communication. In addition to the UART pins, there are SDA and SCL pins for I2C communication. The microcontroller has an additional 4 kb of EEPROM that does not get erased from powering down. 

The input/supply voltage to the Arduino Mega can span from 7 to 12 V from the DC jack and the VIN pin. Powering through the USB has a range of 4.8 to 5.5 V, but since the communication from Mega to Jetson Nano will use the USB for data transmission, this is not an option for powering the microcontroller.

The Arduino serial monitor and serial plotter will aid in validating the voltages received from the sensors. The plotter will also aid in creating software filters. Each of the sensors will be tested with the plotter active so that votlage readings are known for a controlled reading. 
### Arduino Libraries

### Communication with Jetson Nano
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

