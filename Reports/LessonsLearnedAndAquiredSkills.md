# Lessons Learned

## Luke Chapman

Reflect on the project, both technical and organizational. What went well? What didn’t go well? 

- For the most part the power-related subsystems went well. The power distribution PCB performed adequately and passed all tests. The battery life vastly exceeded expectations. The wireless charging subsystem has the potential for future growth, but will require much more research and development. The largest oversight in the entire power system was the inclusion of reverse-biased diodes at the outputs of the 12V rail on the power board. In the case of a single-directional motors, this may be fine, but in the case of bi-directional motors this could cause issues as voltage polarities switch. At best this would lower the efficiency of a motor and at worst cause a component failure. Organizationally the team was very efficient and communicated very effectively. There were some issues that arose from some subsystems waiting on other subsystems to be finished before beginning development, but for the most part those issues were avoided as much as possible.

What unanticipated problems occurred? 

- There was a motor driver failure that we do not have 100% confirmation for the suspected cause of, but are quite certain is what happened. When running the robot back and forth repeatedly to test the battery life, the motor drivers got extremely hot. This is because the motors were switching directions about once per second, and when motors switch directions they send a very large voltage spike back into the driving circuitry. This got something very hot on the motor driver, and some component failed. After getting a new driver and changing the battery-life test program to a continuous robot rotation there were no more issues. A small issue found was that the screw terminals are a bit fragile. If hit from the front (opening side), the screw terminal leads will bend very easily, so different choices in the future may be a good idea.

What would you do differently if you were to do it over again? 

- If I were to do it over again I would have done a little more research into the wireless power transfer subsystem. Because not all of the aspects of that subsystem were thought out, only a very basic proof-of-concept could be demonstrated by the end.

What “best practices” have you identified? 

- One of the best practices I identified was in PCB design (in other areas as well) to make things as modifiable and adaptable as possible. This is particularly important in PCB design, where real board-level modifications are very difficult if that idea was not designed into the board. For instance: all of the motor terminals have an optional component place at the output. When it was realized that diodes were the wrong choice, capacitors could be swapped out very easily. Another example was that the choice of making rows of through-hole connectors for the output voltage rails allowed for very easy additions and changes to be made for different component connections (e.g. adding more pin connectors, screw terminals, etc.).

What words of wisdom would you pass on to future students?

- If you are doing a design in the first semester to be tested in the second, especially if it is something foundational: DO YOUR HOMEWORK. It will save you time in the long run. I checked and double checked everything, from the current capacities of the traces on the PCB to the SPICE simulations of the buck converters. I credit this to not having any failures in the power board, and while it took a lot of work in the first semester of Capstone, it saved me and my team an lot amount of additional stress in the second semester.

What new knowledge or skills did you acquire throughout capstone.

- PCB Design
- Trace current capacity calculations
- Ground isolation between motors and other components
- Back-EMF Mitigation
- Basics of Capacitive Wireless power transfer
- Being a part of a project with distinct subsystems


What classes have you taken that helped you in capstone? What did they help with?

- Electronics: Electronics taught me a lot of the basics of electronics and more advanced electronics circuits and devices. For example, how a buck converter works can be understood through what we learned in this class. Finally, developing a more sophisticated understanding of circuit analysis helped me to analyze and develop circuit layouts for the power board.
- Signals and Systems: In signals and systems we were taught about the basics of different types of electric signals. This was useful for understanding how a buck converter switching waveform operates. We were also introduced to reading datasheets in this course, which helped in the layout of the power board.
- Electromagnetics I and II: Electromagnetism played a role in several parts of the power subsystem. The wireless power transfer is an explicitly electromagnetics topic, and required knowledge of electromagnetics for development and research. Additionally, the potential interference of an inductor into other circuitry is understood through electromagnetics and so having some knowledge helped me in that regard as well.
- Intro to Digital Systems: In this class we learned the basics of digital logic and digital circuits. This was helpful in that it taught me about the voltage levels functionality required for the power board to be able to be used as a high or low value for digital circuit operation.


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

-CSC 1300, CSC1310, ECE3130, ECE4140 all helped with microcontroller programming and code structure
-ECE4370 for integrating mechanical and electrical systems
-ECE2050 for basic electrial knowledge for evaluating datasheets


## Isaac Jennings

Reflect on the project, both technical and organizational. What went well? What didn’t go well? 

- Overall, the project went well, but there were some things that better than others: in the master control subsystem, simultaneous mapping in ROS2 was achieved and was properly 
organized for future teams to use with very minor changes. Future teams can easily pick up where we left off and continue developing the next iteration of the project. 

What unanticipated problems occurred? 

- Connection with the Jetson Nano proved very difficult due to a lack in understanding of networking connections. The issues were resolved by dual booting Ubuntu on my laptop and 
connecting via CAT5 cable. 
- We also ran into problems establishing ROS's base_scan and odom sources. ROS requires either LIDAR or GPS for base_scan and either an IMU or LiDAR for odometry, so we utilized a 
previously used rplidar a2m8 to establish these transforms. 


What would you do differently if you were to do it over again? 

- I would say the most important change would be to use ROS supported sensors. Having ROS drivers would save a lot of time adapting between the two, and I would recommend future teams
utilized a one or more LiDAR sensors

What “best practices” have you identified? 

- Use ROS enhancement protocols (REPs). This will make the code easy to follow for future teams. Also, name systems intuitively. This is crucial for reproducibility.  

What words of wisdom would you pass on to future students?

- If your team decides to use ROS, start learning early. It is a sharp learning curve, but if you have the time to invest, it is possible to learn well enough to make improvements.
Also make documentation an even bigger deal. Add to the user manual we created this year and tell the next team to continue adding. It may take many years to create a code base that enables
very competitive ROS bots consistently. 

What new knowledge or skills did you acquire throughout capstone.

- I learned a ton about ROS middleware. My research and learning helped me to get a job working with ROS that quickly increased my knowledge and skills. I also learned a little bit of 
Object Oriented Programming (OOP). In addition to the hard skills, I also got a lot better at conflict management and team communication. 

What classes have you taken that helped you in capstone? What did they help with?

- CSC 1300 (Intro to programming) and 1310 (Data Structures and Algorithms): Basic programming knowledge for working with ROS2
- Microcomputer Systems: Helped with making serial connection witht he Arduino microcontrollers. 

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

- ECE 4370 : Mecatronics showed me intergration with full systems from the ground up really well. I felt like it prepared me to be able to understand everyone else's subsystems to be able to create a base that would be able to support all functionalities. This class also taught me great trouble shooting techniques that I was able to apply when helping teammates during the construction and experimentation.
- ECE 3920 : Professionalism prepared me for more of the organizational side of the project. I was able to apply the ethical decision making learned as well as how to give a technical presentation.
- ECE 2010,3060, 3160: EE Lab 1 & 2 and Digital Systems lab taught me the importance of and how to have great wiring techniques and convention, especially as it related to trouble shooting cirucits.
- To clarify, I created the chassis and all 3D printed components for the group. Therefore, a majority of my work was done with CAD softwares annd there is no CAD class as part of our curriculum.
