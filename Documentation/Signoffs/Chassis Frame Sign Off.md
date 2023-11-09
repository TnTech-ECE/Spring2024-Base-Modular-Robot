# Chassis Frame Signoff

## Functionality 

The function of this subsystem is to be the structure of the robot. This will allow ll components to be connected together through a strong frame.

## Constraints

- C3:The robot shall be autonomous with customizable dimensions and the stock design only occupying up to one-half of the allowed cubic foot (1 ft x 1 ft x 6 in).
	- This constraint is applicable to the chassis frame because the frame will be the standward way for custom dimensions. Therefore, the material needs to allow for easy movement of sides, come in multiple sizes, and be able to be cut if possible. It is important to note that the stock design will be occupying 1 foot by 1 foot area. The height will be mainly effected by the motors, components, and their trays.

- C4: The robot shall contain modules that are plug and play adaptable for different IEEE competition requirements.
	- This constraint is applicable to the chassis frame subsystem because components need to have the ability to be added, removed, and or moved easily. The chassis frame will be what every component is attached to; therefore, the a material selected needs to allow for easy attachment method.

### Derived from Broader Impacts

- The frame will need to be able to withstand 20 pounds.
	- This stems from a typical weight standard of 25 pounds that had to be reduced due by the customer due to not being able to reach an incline and speed specifcation with a 25 pound load with avaliable motors.

## Buildable Schematics
The following schematics outline the dimensions for the extrusion itself and the layout for the chassis. The chassis frame layout was decided through many decisions. Trying to take up as much of the 1 foot by 1 foot area was the largest concern. 1 foot is 304.8 mm. Therefore, the 300 mm frame peices were used for the front and rear bars. The 250 mm bars are used for the side bars and nested inside the 300 mm bars. This will make the width to be 300 mm and the length to be 290 mm because the width of the bars is 20 mm. The side bars are nested inside due to the motors and wheels. They add width to the frame and therefore if the bars are nested they can be moved in or out to adhere to dimension requirements. The placement in the schematics allow for maximum occupency of the space. The middle bar is there to add more support and for better tray movement, but can be removed if decided that it is not needed in the tray subsystem. The middle rod does not have to be centralized as it is in the schematic. It can be moved based on what is needed for the tray sizes.
![Alt text] (https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/mbolson-ChassisFrame-Signoff/Documentation/Images/Extrusion.jpg)
![Alt text](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/mbolson-ChassisFrame-Signoff/Documentation/Images/Chassis%20Frame.jpg)

## Analysis
The following analysis section will calculate if the extruded alumninum can withstand the maximum 20 pound load it aims to withstand.  
  
$\sigma_{b} = \frac{ My }{I}$  
$\sigma_{b} = \sigma_{Yield Strength} = 16$ ksi (kilopound per square inch)   
This value comes from the material itself: 6063 Aluminum - T5 Alloy.  
  
$\ M = \frac{P_{max}L}{4}$  
L = 250 mm = 9.842520 in  
$\ These two values are important because we are after P_{max}. P_{max} is the maximum allowable pressure that the component can withstand before any sort of deflection in the material occurs. L is the length of the shorted component used. $  
  
y = 10 mm = 0.393701 in  
$\ I = 0.6826 cm^4 = 0.0163995 in^4$  
y is the distance from center of the extrusion to the outside edge. I is the moment of interia. This is a constant based on the shape of the component. This specific manufacturer did not provide the moment of interia; however, a manufacturer with a nearly identical component was found and used for calculation. Once the value is calculated, it was discovered that any difference would be negliable due to the magnitude of the pressure compared to the weigtht we are aiming to hold as well as the fact that the weight will be distributed. This calculation is how much pressure it would take to deflect if that full weight was placed on a single point of the component. Additionally, this is just considering a single 250 mm long bar. In reality the weight will be distributed roughly evenly across all bars.
  
Therefore, with all this the following $\ P_{max}$ can be calculated.  
   
$\ => 16 ksi = \frac{ \frac{P_{max}L}{4}(0.393701 in}{0.0163995 in^4}$  
$\ => P_{max}L = 2.6659 kip-in $  
$\ => P_{max} = \frac{2.6659 kip-in}{9.842520 in} = 0.270855 kip = 270.855 lbf (pound force)$  
  
This means that it would take 270.855 pounds of force on a single point of the extuded aluminum for deflection to occur. This is more than 13 times the amount the team is aiming to hold. Therefore, the frame can easily withstand the weight requirement.  

## BOM
| Item | Quantity | Price/Item | Total Price | 
|-|-|-|-|
| 250 mm Extruded Alumnium (4 pk)| 1 | $16.99 | $16.99 |
| 300 mm Extruded Alumnium (4 pk)| 1 | $17.99 | $17.99 |
| 6 mm Alumnium Corner Connectors (20 pk)| 1 | $13.64 | $13.64 |
| | | | $48.62 |

## References
Extrusion : https://www.amazon.com/Aluminum-Extrusion-European-Standard-Anodized/dp/B08CN92SP1/ref=asc_df_B08PQPJYHX/?tag=hyprod-20&linkCode=df0&hvadid=476087064164&hvpos=&hvnetw=g&hvrand=14031235594181596355&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9013365&hvtargid=pla-1157023532048&th=1  
Moment of Inertia : https://8020.net/20-2020.html  
Extruded Aluminum Data : https://web.archive.org/web/20031006212043/http:/www.alcoa.com/adip/catalog/pdf/Extruded_Alloy_6063.pdf  
Strength Equations : R. C. Hibbeler, Mechanics of Materials, 10th Ed. Hoboken, NJ, USA: Pearson, 2015.
