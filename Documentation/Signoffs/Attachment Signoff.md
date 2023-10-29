# Attachment Signoff

## Functionality

The function of the attachment subsystem is to hold components of other sybsystems in appropriate positions and orientations on the robot without hindering component operation. These attachments will also allow for easy customization of the robot for future teams through easy addition, removal, and adjustment capabilities. 

## Constraints

### Derived from Shall Statements

- C4: The robot shall contain modules that are plug and play adaptable for different IEEE competition requirements.
	- This constraint is applicable to the attachment subsystem because components need to have the ability to be added, removed, and or moved easily.

### Derived from Socioeconomic Impacts

- The components will be 3D printed to reduce cost of project. 	
	- It is important that costs are reduced because the project is aimed at being recreated each year. Therefore, the lowest possible cost without reducing robot performance is a goal for the team. 
		
### Derived from Specifications
- S1: The line sensor attachment must be designed to place the sensor between 0.125 and 0.375 inches off the ground.
	- This is derived from manufacturing specifications for proper operation of the line sensor. 
	
## Buildable Schematics

### Line Following Sensor
The line following sensor comes in an 8 sensor set that is broken along a preforated line that splits the sensor into a 6 sensor set and a 2 sensor set. Therefore, an attachment will created for each. The buildable schematic for each is seen below. The attachment for both is comprised of two peices that will be connected through a screw and washer to allow for height adjustment from the minimum to maximum recommended height of 0.125 - 0.375 inches.

#### 6 Sensor Set Attachment
![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/attachment-signoff/Documentation/Images/Line%20Sensor%206%20Bracket%20Drawing.jpg)
The above component is the what the physical sensor will attach to. It is designed in such a way that at the maximum height of the sensor will not rise up into the attachment. Becasue the sensor reads reflectance off the ground, if any portion of the attachment caused shadowing onto the sensor the readings could be inaccurate. Additionally, the slots cut into the side of this bracket are for wire connections to be placed and exit to the center of the robot. This component will sit into the adjustment mechanism below. 

![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/attachment-signoff/Documentation/Images/6%20Backet%20Adjustment%20Drawing.jpg)
The above component attaches to the chassis frame on the underside of the extruded alumnium. In the analysis section, the distance from the bottom of the extruded aluminum to the ground will be calculated to confirm that this component places the sensor at the appropriate height. The adjustment mechanism works through loosening and tightening a screw with a washer to catch the edge. The component attaches to the extruded alumnium through a T-channel bolt and a 1/4-20 screw. Similar to the height adjustment, the bolt can slide along the extuded alumnium when the screw is loosened.

![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/attachment-signoff/Documentation/Images/6%20Bracket%20Assembly.jpg)
The above figure is the attachment fully assembled with the sensor manufacturer's provided 3D model. 

#### 2 Sensor Set Attachment
The following attachment is an exact copy of the previous attachment, but with the length of the 2 sensor set. Therefore, all reasoning and justifications are the same. 
![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/attachment-signoff/Documentation/Images/Line%20Sensor%202%20Bracket.jpg)
![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/attachment-signoff/Documentation/Images/2%20Backet%20Adjustment.jpg)
![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/attachment-signoff/Documentation/Images/2%20Sensor%20Assembly.jpg)

### Ultrasonic Distance Sensor
The ultrasonic distance sensor will be used to detect the robot's distance from the borders of the arena. Therefore, this sensor need to be placed on the side(s) of the robot at the appropriate height. The borders are 2 by 4 peices of wood; therefore, the sensor needs to be placed somewhere in the middle. This height will not be determined until the testing phase. Therefore, the slots on the sides of the attachment will allow for height adjustment on the extruded aluminum. The sensor's operation is not inhibited because it will be attached to the front of the attachment with screws. The figures below outline the dimensions for the design and provides the specifactions for the sensor.
![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/attachment-signoff/Documentation/Images/Ultrasonic%20Sensor%20Drawing.jpg)
![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/attachment-signoff/Documentation/Images/Ultrasonic%20Sensor%20Specs.png)

### Time of Flight Sensor
The time of flight sensor detects small distances. Therefore, it will be used for object detection. This means that this sensor will also need to be placed on the side(s) of the robot. The height that is effective will be determined during the testing phase; therefore, the current design allows for height adjustment by the tabs on the top and bottom. The sensor's operation is not inhibited because of how the sensor will be attached. The component that actually detects objects is seen in the third figure below and that face of the sensor will attach to the back face of the attachment. This will allow the component that detects objects to fit into the cut out hole in the middle of the attachment and the wire attachment point on the back of the sensor seen in white to still be accessible. The figures below outline the dimensions for the design and provides the specifactions for the sensor.
![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/attachment-signoff/Documentation/Images/Time%20of%20Flight%20Attachment%20Drawing.jpg)
![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/attachment-signoff/Documentation/Images/Time%20of%20Flight%20Sensor%20Specs.png)
![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/attachment-signoff/Documentation/Images/Time%20of%20Flight%20Sensor%20Front.png)

### Motor
The motors possess attachments designed for them; however, they are not compatible with the extruded alumnium. Therefore, these adapators have been desgined for attachment onto the extruded aluminum. It is important to note that an attachment was not created to combine these attributes into one design because of the material. It was determined that the the metal mount provided would be the best for direct attachment to motors and this printed attachment will be best for attaching to the chassis framee figures below outline the dimensions for the design and overall connection with the motor system. 
![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/attachment-signoff/Documentation/Images/Motor%20Attachment%20Drawing.jpg)
![Alt text]()

## Analysis
The analysis performed is confirm that the sensor is placed between 0.125 and 0.375 inches. The first figure below measures the distance from the bottom of the extruded alumninum to the ground being () inches. The second figure measures from the top of both line sensor attachment, which is the same for both, to the face of the sensor on the pcb  to be () inches at the lowest setting. Therefore, the minimum height is () - () = 0.125 inches. Therefore, this confirms compliance with the sensors specfication for the minimum height. The third figure measures from the top of both line sensor attachments to the face of the sensor on the pcb to be () inches at the highest setting. Therefore, the maximum height is () - () = 0.375 inches. Therefore, this confirms compliance with the sensors specfication for the maximum height.
![Alt text]()
![Alt text]()
![Alt text]()

## BOM
| Item | Quantity | Price/Item | Total Price | 
|-|-|-|-| 
| | | | | 
| | | | |

## References
Pololu Line Following Sensor Information: https://www.pololu.com/product/961/ (Accessed 10/18/2023)

Grove Ultrasonic Distance Sensor Information: https://www.seeedstudio.com/Grove-Ultrasonic-Distance-Sensor.html (Accessed 10/20/2023)

Grove Time of Flight Sensor Information: https://www.seeedstudio.com/Grove-Time-of-Flight-Distance-Sensor-VL53L0X.html?queryID=45b3376622962a02df0cbf01da058ca4&objectID=112&indexName=bazaar_retailer_products (Accessed: 10/24/2023)

Pololu Motor Mount Information: https://www.pololu.com/product/1084 (Accessed: 10/21/2023)
