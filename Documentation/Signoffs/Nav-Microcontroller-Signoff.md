# Arduino Signoff

## Functionality
The microcontroller susbystem will provide the computing power needed to read in sensor data, filter the data as needed, and send the resulting values to the master control subsystem via serial communication.

----

## Constraints

----

## Schematic

---

## Analysis

### Arduino Analysis
The Arduino Mega 2560 Rev3 has 54 digital pins and 16 analog pins. It also has 15 PWM output pins. The PWM pins will give future teams the option to attach servo or stepper motors to complete their tasks without having to implement another microcontroller. The Mega has 4 sets of Tx/Rx pins for UART communication. In addition to the UART pins, there are SDA and SCL pins for I2C communication.

The input/supply voltage to the Arduino Mega can span from 7 to 12 V from the DC jack and the VIN pin. Powering through the USB has a range of 4.8 to 5.5 V, but since the communication from Mega to Jetson Nano will use the USB for data transmission, this is not an option for powering the microcontroller.

The Arduino serial monitor and serial plotter will aid in validating the voltages received from the sensors. The plotter will also aid in creating software filters. 
### Arduino Libraries

### Communication with Jetson Nano
---
## BOM
|Item        |Quantity   |Price   |Total   |
|------------|-----------|--------|--------|
|Arduino Mega|1          |$\$43.56^{1}$ |$\$43.5$


1. This is a sale price listed on Amazon. Normal retail is $55.00

---
## References
Arduino Mega Datasheet: https://docs.arduino.cc/resources/datasheets/A000067-datasheet.pdf

