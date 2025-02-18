# Modular IEEE Robot

## Executive Summary

Each year, Tennessee Technological University (Tech) participates in the Institute of Electrical and Electronics Engineers (IEEE) Southeastern Conference (SECON) hardware competition. The competition asks participants to create a robot that can perform various tasks, and competitors are scored based on their robot’s capability to complete tasks as quickly as possible. In past years, Tech has placed well, but the same problems have arisen each year that have inhibited wins: choppy navigation, shorted cables, and battery depletion are just a few of the many problems teams have repeatedly faced in previous competitions. The team sets out to fix the besetting problems that teams face each year not by competing in SECON, but rather by building a generalized platform that will optimize the basic robotic functionality for future teams. Sensing, movement, and centralized charging are the top priorities in the team’s design, all fitted together in a modular, adaptable framework that can be manipulated to fit most – if not all – IEEE hardware competition specifications. No longer will teams have to spend countless hours learning and designing movement systems or hoping everything works after rewiring a battery mid-competition. The design will take care of these basic competition necessities and leave the custom tailoring to the competition team.  


## Capabilities

The current version of the robot has the following capabilities:
1. Autonomous navigation
2. Modular components that can be easily adapted for different uses
3. Robust, centralized charging system
4. Functioning emergency stop button
5. Can travel inclines and declines up to 25 degrees
7. 360 degrees of movement
8. Knows location within a 2 inch tolerance
9. Sensors are are plug and play adpatable with the use of an I2C bus
10. Foundation layed for autonomous navgivaton with LiDAR and ROS2
11. User manual for teams to understand design considerations, common problems, and solutions


## Salient Outcomes

As projects progress, there are typically outcomes tht are more impressive than others. Here is a list of salient outcomes of this project:
1. Wireless charging proof of concept
2. Multiple navigation subsets for teams to choose between
3. Foundation for layed for ROS2 mapping for future uses
4. Plug and play adapatibility with sensors through I2C buses
5. Power board with ground isolation
6. GUI for teams to see their live data transmission 

## Project Demonstration & Images

![image](https://github.com/lchapman42/Control-Sensing-Wireless-Charging-Robot/blob/main/Documentation/Images/ModelvsCreated.png)

3D model of the robot vs the final product

[Watch the video](https://youtu.be/stM9KGa8I_E) of the robot autonomously navigating a line.

[Watch the video](https://youtu.be/3MeIy1WahUA) of the robot autonomously sweeping the board given its location.

[Watch the video](https://youtu.be/3MeIy1WahUA](https://www.youtube.com/watch?v=_iFhnvbLboQ)) of the robot detecting objects in front of it.

## About Us

### Team

**[Luke Chapman](https://www.linkedin.com/in/luke-chapman-/)** is an electrical engineering major at Tennessee Technological University with a minor in mathematics. He is interested in electromagnetics, telecommunications, and signal processing. Luke is responsible for the power management and distribution systems of the robot as well as the experimental wireless power charging system.

**[Reid Crews](https://www.linkedin.com/in/jackson-crews-381187257/)** is an electrical engineering major, mechatronics concentration at Tennessee Technological University with a minor in mathematics. Reid's interests are mechatronics and control systems. For the project, Reid is a contributor for the navigation sensing, primarily the location and object detection subsystems.

**[Isaac Hoese](https://www.linkedin.com/in/isaac-hoese-425748251)** is a senior electrical engineering student from Greeneville, Tn. He is interested in both power system analysis and embedded system design. In this project, Isaac will be a contributor for the navigation sensing, primarily the line following and orientation subsystems.

**[Isaac Jennings](www.linkedin.com/in/isaac-jennings-a04680209)** is a senior electrical engineering student with a minor in mathematics from Church Hill, TN. He takes interest in control systems, programming, and embedded systems, which is where he allocated his time by working on the master control systems on the project. He is responsible for the navigation and localization of the robot as it interfaces with the game board.  

**[Abigail Kennedy](https://www.linkedin.com/in/abigail-kennedy-tech/)** is an electrical engineering major at Tennessee Technological University with minors in mathematics and education. Abigail's primary interest is in controls and PLC design, and for this project, she worked on the motor control subsystem to ensure the robot can move quickly and smoothly.

**[Mabel Olson](https://www.linkedin.com/in/mabelolson/)** is an electrical engineering major at Tennessee Technological University with a minor in mathematics. She is intrested in power and control systems. In this project, Mabel is responsible for the chassis design, robot layout, organization, and any 3D designing of component attachment pieces. 


### Faculty Supervisor

The faculty supervisor for this project is [Dr. Nan Chen][def1]. She completed her electrical and control engineering Bachelor's degree from Nanjing University of Aeronautics and Astronautics. She also completed her Master's and Ph.D. in electrical engineering from the University of Waterloo. 

[def1]: https://www.linkedin.com/in/nan-chen-319aa185/

### Stakeholders

The primary customer for the project is [Professor Jesse Roberts](https://www.linkedin.com/in/jessetnroberts/) - the advisor for the IEEE SECON hardware teams. Future teams are impacted by this design but unable to be stakeholders, so he gives input on their behalf based on his years of experience with the competition.


### Recognitions

We would like to recognize and thank Professor Jesse Roberts, Dr. Nan Chen, and Dr. Charles Van Neste for their continuous input and guidance on the project.

## Repo Organization

### [Reports](/Reports)

The [Project Proposal](./Reports/Project%20Proposal/Project%20Proposal%20Revised.pdf) is the initial document for the project where the problem is defined and the goals for the project.

The [Conceptual Design](./Reports/Conceptual%20Design/Conceptual%20Design%20and%20Planning%20V2.pdf) gives a more detailed solution to the problem as well as subsystem breakdowns and a projected timeline and budget.

The [Experimentation](/Documentation/Experimental%20Analysis) gives the experimental results of the different subsystems and how constraints were met or not.

The [Poster](./Reports/Poster/Modular%20IEEE%20Robot%20Poster.pdf) is what the team presented at the 2024 capstone showcase.

The [Final Presentation](./Reports/Final%20Presentation/Final%20Presentation.pdf) is the presentation that the team gave to the IAB.

The [Lessons Learned](./Reports/LessonsLearnedAndAquiredSkills.md) gives team members' reflections on their progress, oversights, noteable incidents, and successes.

### [Documentation](/Documentation)
All documentation for the project is included in the above folder. Documentation includes all schematics, images, models, BOM, and designs used in the project.

The [Meeting Minutes](/Documentation/Meeting%20Minutes) folder contains the dated minutes from weekly meetings and allows a quick view into the progress of the team.

[Signoffs](/Documentation/Signoffs) are used to finalize designs for each subsystem. This includes schematics, design decisions, BOM, and analysis. 


### [Software](/Software)

 All software used and created is listed in the [Software](./Software) directory. For each subsystem, there are specific folders listed to find the necessary code.


