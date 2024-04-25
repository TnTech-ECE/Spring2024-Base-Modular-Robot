# Lessons Learned

## Luke Chapman

Reflect on the project, both technical and organizational. What went well? What didn’t go well? 

- For the most part the power-related subsystems went well. The power distribution PCB performed adequately and passed all tests. The battery vastly outlasted what it was expected to and .... Finish ....

What unanticipated problems occurred? 

- There was a motor driver failure that we do not have 100% confirmation for the suspected cause of, but are quite certain is what happened. When running the robot back and forth repeatedly to test the battery life, the motor drivers got extremely hot. This is because the motors were switching directions about once per second, and when motors switch directions they send a very large voltage spike back into the driving circuitry. This got something very hot on the motor driver, and some component failed. After getting a new driver and changing the battery-life test program to a continuous robot rotation there were no more issues. A small issue found was that the screw terminals are a bit fragile. If hit from the front (opening side), the screw terminal leads will bend very easily, so different choices in the future may be a good idea.

What would you do differently if you were to do it over again? 

- If I were to do it over again I would have done a little more research into the wireless power transfer subsystem. Because not all of the aspects of that subsystem were thought out, only a very basic proof-of-concept could be demonstrated by the end.

What “best practices” have you identified? 

- One of the best practices I identified was in PCB design (in other areas as well) to make things as modifiable and adaptable as possible. This is particularly important in PCB design, where real board-level modifications are very difficult if that idea was not designed into the board. For instance: all of the motor terminals have an optional component place at the output. When it was realized that diodes were the wrong choice, capacitors could be swapped out very easily. Another example was that the choice of making rows of through-hole connectors for the output voltage rails allowed for very easy additions and changes to be made for different component connections (e.g. adding more pin connectors, screw terminals, etc.).

What words of wisdom would you pass on to future students?

- If you are doing a design in the first semester to be tested in the second, especially if it is something foundational: DO YOUR HOMEWORK. It will save you time in the long run. I checked and double checked everything, from the current capacities of the traces on the PCB to the SPICE simulations of the buck converters. I credit this to not having any failures in the power board, and while it took a lot of work in the first semester of Capstone, it saved me and my team an lot amount of additional stress in the second semester.

What new knowledge or skills did you acquire throughout capstone.

- I learned a lot more about good PCB design. Particularly in the use of having a shared ground connection between "clean" and "dirty" ground connections (in this case between the motors and 3.3/5 V rails). By isolating the two everywhere except for one single small connection, there was no noticeable interference between the motors and other buses through the ground plane, resulting in (to my knowledge) not a single brownout.

What classes have you taken that helped you in capstone? What did they help with?

- ...

## Reid Crews

Reflect on the project, both technical and organizational. What went well? What didn’t go well? 

- For technical part of project, the team work well to complete the tasks individually and together with their unique skill set and knowlwdge.
- For organizational part of the project, the team was efficent in meeting and complete tasks except for a few misunderstandings.

What unanticipated problems occurred? 

- The library for the Grove Time of Flight Sensor (VL53L0X) did not allow to set a different address because it was privated in the class. I had to find a different library to set a different address because two I2C devices with the same address can not work at the same time.
- The I2C bus encountered a low voltage when ran at 5V, but not on 3.3V. This caused our sensors to read maximum values until switching to 3.3V

What would you do differently if you were to do it over again? 

- I would make a custom PCB for the I2C hub and connections for all the sensors to be easier to plug in play adaptable.
- Use a different brand/company for the Time of Flight (VL53L0X).

What “best practices” have you identified? 

- Using print statements in the code to debug issues is a great practice. It allows to see how the works and eliminate possible problems.

What words of wisdom would you pass on to future students?

- Research and collect many solutions to solve your problem, and then use pros and cons to compare all of your solutions. Use the criteria of money, time, complexity, and feasibility to make the correct decision.

What new knowledge or skills did you acquire throughout capstone.

- Understanding I2C communication
- Testing and Debugging Problems
- Understanding Technical Documentation
- PID Controller

What classes have you taken that helped you in capstone? What did they help with?

- ...

## Isaac Hoese

Reflect on the project, both technical and organizational. What went well? What didn’t go well? 

- The bluetooth data transmission and sensors went smoothly.

What unanticipated problems occurred? 

- The I2C bus encountered a low voltage when ran at 5V, but not on 3.3V. This caused our sensors to read maximum values until switching to 3.3V
- The back line following sensor was shorted. However, the robot runs equally as well with only the front line following sensor active.

What would you do differently if you were to do it over again? 

- I would have combined the Arduino Mega and ESP32 onto a custom PCB. This would eliminate most of the wires on the robot (or at least made them much shorter) since the pin headers could be placed in ideal spots for our specific robot.

What “best practices” have you identified? 

- I think the main "best practice" was adopting the universal coding conventions which will allow future users to easily adopt code. Using the coding conventions also eliminates ambiguity between integer types ( uint32_t, uint16_t, etc.) and makes variable allocation an easier process.

What words of wisdom would you pass on to future students?

- Do as much research on your topic as you can up front. In hindsight, we could have chosen one sensor for navigation rather than the 14 that we have on the board. The more you research upfront the less work you will have to do in the long run.

What new knowledge or skills did you acquire throughout capstone.
- Basic ROS knowledge (From helping Isaac J.)
- Wireless Data Transmission
- GUI creation
- PID programming

What classes have you taken that helped you in capstone? What did they help with?

- ...

## Isaac Jennings

Reflect on the project, both technical and organizational. What went well? What didn’t go well? 

- ...

What unanticipated problems occurred? 

- ...

What would you do differently if you were to do it over again? 

- ...

What “best practices” have you identified? 

- ...

What words of wisdom would you pass on to future students?

- ...

What new knowledge or skills did you acquire throughout capstone.

- ...

What classes have you taken that helped you in capstone? What did they help with?

- ...

## Abigail Kennedy

Reflect on the project, both technical and organizational. What went well? What didn’t go well? 

- Our team structure seemed to work well since we were able to agree on most things and conflicts were short-lived. However, there seemed to be some communication issues where problems would come up and not be discussed until it was too late.
- On the technical side, the team did well with specializing in different areas while still being knowledgeable of everyone's work which was useful when combining work in the building and testing stage.

What unanticipated problems occurred? 

- There were several problems with our constraints or measures of success where we weren't able to fully complete them, so we had to work with our advisor to modify them.
- The robot went slower than I expected which was part of my section, and I had to find was to test the robot to determine the root cause.

What would you do differently if you were to do it over again? 

- I would have ensured we had better communication to know where everyone was at on their part of the project so we could all encourage and help one another more easily.

What “best practices” have you identified? 

- Document everything - especially in the testing phase - to make sure you aren't wasting time repeating tasks
- Be organized for documents and the project since it speeds up a lot of work

What words of wisdom would you pass on to future students?

- Make sure to take your time in the planning phase and understand everything that you're doing
- Communicate everything with your team good and bad

What new knowledge or skills did you acquire throughout capstone.

- Team and project leadership
- Technical knowledge of motor control and mecanum wheel movement
- How to do electrical schematics
- How to give a good technical presentation

What classes have you taken that helped you in capstone? What did they help with?

- ECE 4370 - Mechatronics showed me the basics of motor control and how to integrate software with different physical components.
- ECE 2050, 3050, 4050 - All of the circuits and electronics classes came into play when determining how components should interact regarding different voltages and currents.
- ECE 3920 - Professionalism helped me determine how to give a better technical presentation, make ethical decisions, and work in an engineering team.

## Mabel Olson

Reflect on the project, both technical and organizational. What went well? What didn’t go well? 

- On the technical side of the project, I felt like my team was extremely well rounded and this allowed for easy distribution of work to people and allowed everyone to enjoy what we did. I also felt like us being well rounded allowed for a really smooth integration and experimentation portion of our project.
- Overall, I think the organization portion of our project went well. Towards the end there were some concerns that were brough forward, but it was too late to fix them. It stemmed from some poor communication between the group throughout the project that was never addressed. 

What unanticipated problems occurred? 

- With the motor attachment, there were problems with getting them made out of PLA and being a certain thickness due to a height contraint. Where the attachment was too thin/too weak, it caused bowing on the motors on the frame of the robot. I tried a new design with the same material and it also did not work. Therefore, I had to contact the machine shop to create the attachment out of metal instead. Over two iterations, the mount worked and we could proceed on with building. This caused a slight delay in progress for the robot in January. 

What would you do differently if you were to do it over again? 

- I would communicate more clearly every step of the project and through every concern to ensure there were no misunderstandings and more exact expectations layed out.
- I would have looked more best uses or suggestions for 3D printing componets to avoid needing to do as many iterations of designs and prints. 

What “best practices” have you identified? 

- For 3D models, more adimatantly saving each version of a components. There were times were I would make changes and not save a new version and need the old version I had just erased.
- Document problems faced as they are faced so that when you need to write about it for the presentation or somehting else you already have it written down so you can remember more details.

What words of wisdom would you pass on to future students?

- Make more clear expectations and communicate them clearly to keep meetings and communication as easy as possible.
- Document everything. You will thank yourself later.
- Keep all group files organized as you go. This will make it easier to find things and save time later.

What new knowledge or skills did you acquire throughout capstone.

- I definitely further progressed my skill and knowledge in 3D modeling and CAD software in general. If I use something similar in the future it will be alot easier to pick up.
- Team and project leadership
- How to create and present a good technical presentation
- Project intergration. Seeing and understanding how everyone's subsystems worked together to create our robot.

What classes have you taken that helped you in capstone? What did they help with?

- ...
