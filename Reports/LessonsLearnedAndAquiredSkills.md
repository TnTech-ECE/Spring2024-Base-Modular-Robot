# Lessons Learned

## Luke Chapman

Reflect on the project, both technical and organizational. What went well? What didn’t go well? 

- For the most part the power-related subsystems went well. 

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

## Reid Crews

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

## Isaac Hoese

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

## Abigail Kennedy

Reflect on the project, both technical and organizational. What went well? What didn’t go well? 

- Our team structure seemed to work well since we were able to agree on most things and conflicts were short-lived. However, there seemed to be some communication issues where problems would come up and not be discussed until it was too late.
- On the technical side, the team did well with specializing in different areas while still being knowledgeable of everyone's work which was useful when combining work in the building and testing stage.

What unanticipated problems occurred? 

- There were several problems with our constraints or measures of success where we wouldn't be able to complete them, so we had to work with our advisor to modify them.
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

## Mabel Olson

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
