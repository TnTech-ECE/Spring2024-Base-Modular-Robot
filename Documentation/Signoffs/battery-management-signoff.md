# Battery Management Signoff

## Functionality

The primary function of the battery management system is to provide a system that can supply adequate current to the robot's systems. This battery must be able to be recharged without the removal of the battery and be able to be used while being charged.

## Constraints

- C7: The robot shall possess a single emergency stop button that is accessible and stops all robot movement without removing power to essential processors that is compliant with standard NFPA 79-10.
- C8: The robot shall contain a power bus that is not inhibited by DC motor operation.

### Derived from Shall Statements

- C5: The robot shall possess a robust, centralized charging system that does not require the removal of the battery and that allows the robot to be used while being charged.
	+ This constraint is the most important for this subsystem. This constraint requires that the battery management can provide enough power to the system and allow for the robot to be used while the battery is being charged.

### Derived from Broader Implications

- C17: The robot shall abide by NEC 310.15(B)(16) when sizing any conductors for the project.

## Schematic

![Battery Management Schematic](./Images/Battery_Management_Schem.png)

## Analysis



## BOM 

| Item | Part Number | Quantity | Price/Unit | Item Price |
| --- | --- | --- | --- | --- |
| Lithium Iron Phosphate Battery | LITHIUM 12.8V20AH | 1 | $121.00 | $121.00 |
| Lithium Iron Phosphate Battery Charger | PCCG-LFP14.4V10A | 1 | $129.27  | $129.27 |
| Panel Mount 3-Prong Receptacle | 6100.33 | 5 | $1.15 | $5.75 |
| 12 Foot 3-Prong AC Power Cable | P010-012 | 2 | $10.62 | $21.24 |
| Total |  |  |  | $277.26 |


## References