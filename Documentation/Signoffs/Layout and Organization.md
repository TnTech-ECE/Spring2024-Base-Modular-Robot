# Layout and Organization Signoff 

## Functionality

The function of this subsystem is to develop a layout that allows for modularity for future teams, as well as, establishing a wire organization system.

## Constraints

### Derived from Shall Statements

- C3: The robot shall be autonomous with customizable dimensions and the stock design only occupying up to one-half of the allowed cubic foot (1 ft x 1 ft x 6 in).
	 -This constraint is applicable to the Layout and Organization subsystem because with all components on the robot, the length and width cannot exceed 12 inches and the height cannot exceed 6 inches.


- C4: The robot shall contain modules that are plug and play adaptable for different IEEE competition requirements.
	- This constraint is applicable to the attachment subsystem because components need to have the ability to be added, removed, and or moved easily. The slotted peices created in this subsytem allow for this to occur. Additionally, the wire organization is important for quickly tracing and finding wires. 

### Derived from Socioeconomic Impacts

- The components will be 3D printed to reduce cost of project. 	
	- It is important that costs are reduced because the project is aimed at being recreated each year. Therefore, the lowest possible cost without reducing robot performance is a goal for the team. 
	
## Buildable Schematics

![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Sign%20off%20Photos/Layout%20Organization/Frame%20with%20Slotted%20Pieces%20Corner%20View.jpg)

### Slotted Peices (Front/Back Rows)
The following buildable schematic is of the slotted peices for components to attach to. These slots allow for components to be moved around as needed and are provided in such frequency to allow for rearranging as necessary. A total of 12 peices are needed to complete the full area. The front/back components are the front 3 and back 3 peices and possess holes to be attached to the extruded aluminum. These also have notches to allow the peices to be connected together with a connector peice. 
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Sign%20off%20Photos/Layout%20Organization/Slotted%20Peices%20Front-Back%20Rows%20Schematic.jpg)

### Slotted Peices (Middle Rows) 
The following buildable schematic is of the slotted peices for components to attach to. These slots allow for components to be moved around as needed and are provided in such frequency to allow for rearranging as necessary. A total of 12 peices are needed to complete the full area. The middle components are the middle 6 peices and do not possess holes to be attached to the extruded aluminum. These also have notches to allow the peices to be connected together with a connector peice.
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Layout%20Organization/Slotted%20Peice%20Middle%20Schematic.jpg)

### Connector
The following buildable schematic is of the peice that connects the above components together.
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Sign%20off%20Photos/Layout%20Organization/Connector%20Schematic.jpg)

### Wire Organization
In order to keep wires organized, a wiring convention will be implemented. 
The following Table explains the meaning of each wire color. Extra colors may be added
as needed to the signaling wires, but the listed colors will serve as an adequate starting point. 

|Usage|Colors|
|-|-|
|3.3V Power|White|
|5V Power|Black|
|12V Power|Red|
|Signal/Sensors|Blue, Yellow, Orange, Purple, Brown|
|Ground|Green, Copper|

Wire labels will also be used to provide more clarification for wire organization. 
The labels should be used to specify the destination of power wires, function of signal wires,
and pin numbers for microcontroller GPIO headers. 

## Analysis
The main concern for this subsystem is being able to fit all components on the robot while adhearing to constraint 4. Therefore the following figures shows that the frame with components will stay with a 12 in x 12 in x 6 in volume. It is important to note that this is just to prove that these components will fit within the alloted area. The exact layout will be decided during the building phase.
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Sign%20off%20Photos/Layout%20Organization/Chassis%20Frame%20Layout%20Size%20Confirmation.jpg)
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Sign%20off%20Photos/Layout%20Organization/Robot%20Layout%20Corner%20View.jpg)
![Alt Text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/Sign%20off%20Photos/Layout%20Organization/Robot%20Layout%20Top%20VIew.jpg)
The following table is the legend for the components in the above image.

| Item | Quantity | Color |
|-|-|-|
|Battery|1|Red|
|Charger|1|Blue|
|Motor Driver|2|Green|
|PCB|1|Pink|
|Grove I2C Bus|3|White|
|Accelerrometer/Gyroscope|1|Black|

## BOM
| Item | Quantity | Price/Item | Total Price | 
|-|-|-|-|
|T Slot Nuts (100 pk)|1|$9.78|$9.78| 
|M4-8mm Screws (50 pk)|1|$7.99|$7.99| 
|M3-8mm Flat Screws (50 pk)|1|$6.49|$6.49|
|M3 Nut (50 pk)|1|$4.34|$4.34|
|Spacer Stand off Screws|1|$13.99|$13.99|
|Wire Labels|1|$9.00|$9.00|
| | | |$51.59|

## References
Battery Link:https://www.digikey.com/en/products/detail/power-sonic-corporation/PSL-SC-1270-F2/13577482?s=N4IgjCBcoMw1oDGUBmBDANgZwKYBoQB7KAbRACYA2ATnOoBYQBdAgBwBcoQBldgJwCWAOwDmIAL4F6YcghDJI6bPiKkQMSgFYYABkYsQHLr0GiJBMNQAc1OQqW4CxSGR3NJIALSzo8qPwBXFWcyTXdxcSA    
Charger Link:https://www.digikey.com/en/products/detail/zeus-battery-products/PCCG-LFP14-4V10A/9828828    
Motor Driver Link:https://www.amazon.com/BOJACK-H-Bridge-Controller-Intelligent-Mega2560/dp/B0C5JCF5RS/ref=sr_1_2_sspa?crid=20LPNPFW4Z3U6&keywords=L298N&qid=1700797990&sprefix=extra+large+hole+punch%2Caps%2C283&sr=8-2-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1    
Grove I2C Bus:https://wiki.seeedstudio.com/Grove-I2C-Hub-6Port/#Application%20Ideas%E2%80%8B    
Accelerrometer/Gyroscope:https://www.adafruit.com/product/4517    
Wire Labels: https://www.amazon.com/Management-Wmiwulien-Waterproof-Electronics-Handwriting/dp/B0B2N1J2SF/ref=asc_df_B09R29CL8P/?tag=hyprod-20&linkCode=df0&hvadid=652502670956&hvpos=&hvnetw=g&hvrand=4296422276430482524&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9013670&hvtargid=pla-2060990641110&mcid=2e52fe3b89243ac99c5968c8cf339fd6&th=1  

