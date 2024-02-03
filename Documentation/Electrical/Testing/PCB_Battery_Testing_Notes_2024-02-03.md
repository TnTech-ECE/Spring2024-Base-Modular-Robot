## Notes from Testing PCB and Battery Testing - 2024-02-03

These are my notes from testing the power PCB, battery, and battery charger. They may also be useful to future teams using this system.

-- Luke 

------------

So far the PCB, battery, and battery charger have performed very well to testing.

Testing if board will output correct voltages (3.3 V and 5 V) over the entire possible input voltage range.

From the battery datasheet, recommended voltage range is between 11 V and 14.6 V.

Output voltages were measured at both the top and bottom voltage rails. Note that "top" and "bottom" refer to the rails shown as top and bottom in the orientation of every image of the board. Also, the "Battery to 3.3/5 V" text will be upright in this orientation. (Not that this matters that much because both worked).

| Measured Input Voltage (V) | Top 5 V Rail (V) | Top 3.3 V Rail (V) | Bottom 5 V Rail (V) | Bottom 3.3 V Rail (V) |
| --- | --- | --- | --- | --- |
| 10.0013 | 5.0461 | 3.2792 | 5.0466 | 3.2792 |
| 11.0010 | 5.0491 | 3.2798 | 5.0490 | 3.2798 |
| 12.0014 | 5.0508 | 3.2802 | 5.0507 | 3.2802 |
| 13.0011 | 5.0524 | 3.2807 | 5.0524 | 3.2808 |
| 14.0008 | 5.0536 | 3.2811 | 5.0536 | 3.2811 |
| 15.0006 | 5.0547 | 3.2813 | 5.0546 | 3.2814 |


Battery voltage started almost exactly at nominal 12.8 V.

Battery Charger LED Color Legend:\\
Green - Charged\\
Red - Charging\\
Red Flashing - Fault\\
Off - Off

Tested charging current - charging current starts at ~6 A, then drops exponentially to around 4.9 A. This is good because max charging current of battery is 7.2 A and charger can output up to 15 A, putting charger well within the acceptable range.

Battery took around 1 hour to completely charge. Charged in the typical capacitive curve with the battery voltage shooting up to 13 V and then 14 V very quickly and then very slowly to ~14.5 V. Once the battery was fully charged, LED turned green and the charger stopped supplying power.

Once the battery was fully charged or the charger was disconnected, the battery voltage began to fall back to somewhere in the 13 V range. Looking around online, it seems that this is normal and as long as it does not fall to far is perfectly ok.


Short Circuit Protection:\\

Tested charger short-circuit protection, taking the leads of the charger with no load and shorted them. Charger enters fault state. It appears that the charger has to be power cycled to reset it afterwards, but does so without issue. Charger does need to be unplugged for several seconds before the LED turns off, after which it can be plugged back in. 

Charger claims to have short circuit protection, and I thought that shorting the battery was a large enough risk to test it. The battery while connected to the charger was very briefly shorted to see what would happen. Nothing broke, though it took surprisingly long for anything to happen (~1 s). The battery was depleted a little and the charger began charging again. Did not enter fault state, do not know why.

Powering board from battery:

The board was perfectly functional when only powered by the battery, output the correct voltages. 

Connecting the charger to the battery while the battery (and charger) powered the board worked pretty much exactly as expected. The board functioned fine, and the battery would supply power with no issue. When the battery would become a little depleted, the charger would switch to charging mode, and charge the battery for a few seconds, then switch back to charged mode. Granted this is only with a small load, but this is a good sign.

Board under load:

The board worked perfectly fine under a small load (100 Ohms connected to each rail). A small load was used because the current capabilities are currently (haha) the biggest unknown. I realized that I can't test the full current capabilities using just resistors as of right now, since none of my resistors are able to tolerate even close to the power that will be dissipated at such high currents (5+ A). So for future tests will just need to wait for rudimentary motor control to be completed and then test that way, or think of a different device that can pull variable current, or find high-power, low resistance resistors.

Inductor Noise:

Measured the voltage across the inductors on an oscilloscope, did not take a picture but shape is similar to a decaying sinusoid that spikes periodically and then decays. A similar pattern (but much more attenuated) was found when measuring voltages between arbitrary points in the ground bus. This means that inductor noise may be an issue, but I am unsure if it will be so far.


Misc:

I found out that the chassis-mount connector meant to be screwed into the chassis and bridge beween an exterior cable and interior cable to the charger does not fit. The male side of the connector does not fit the female side of the cable. 