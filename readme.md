# INFORMATION
| Type     |      info      | 
|----------|:-------------:|
|`Starting date`| April 2021|
| `COMPETITION` |  Polymaze| 
| `CODING LANGUAGE` |   C++   | 
| `Time spent on coding/designing the robot` | > 1 month  | 
|`member of the team`| 2|
## Introduction
Polymaze is a MAZE SOLVING competition. Similar events have been held throughout the 
world, and are most popular in the UK, the U.S, Japan, Singapoura, India, South Korea...etc.
I participated to the first edition of ths competiton , the code used to control the micromouse will be detailled below.
The first version of the M2-KB Robot will not be displayed in this repository , the second version shown in the first two images below was a robot type called micromouse , this version was used during the competition . The final version shown in the last image was our last version and was presented during an event called `TECHITUP`.

To hold the mechanical construction, the perf board was used directly, on which all other
 components are fixed. (Motors, components, sensors, wheel. . . ).
This can be seen below:
M2-KB version 1 (front)             |  M2-KB version 1 (Back)  
:-------------------------:|:-------------------------:
<img src="https://github.com/khelafimassylia/MAZERUNNER/blob/main/frontversion1.png" width="200" height="200">|<img src="https://github.com/khelafimassylia/MAZERUNNER/blob/main/backversion1.png" width="200" height="200">


However, this version of the robot is only used as a first prototype. For the
final version, a printed circuit board is used. It will connect (mechanically and electrically)
the different parts of the robot.

Autodesk Eagle was used to design the circuit board.
<p align="center">
<img src="https://github.com/khelafimassylia/MAZERUNNER/blob/main/finalversion.png" width="200" height="200">
</p>

## Rules

It should be noted that in the POLYMAZE competition, the labyrinth had the following characteristics
following characteristics:

1. The height of the walls is 15cm.

2. The distance between a wall and its opposite is 30cm.

3. A black line 2cm thick is drawn along the tracks in the middle of two
opposite walls.

4. The labyrinth is made of wood (floor and walls), the floor is white.

5. The end of the labyrinth is marked by a black square of 20cm*20cm.

But for the case of a line follower robot the walls are non-existent so the only
characteristic that we will take into account are the 2nd, 4th and 5th

## Line-following control algorithm

We have seen in the previous chapter, the sensors used, their locations and
the algorithm used to read their values.
Now we will see how these sensors are used to control the robot's
the movements of the robot.
In order for the robot to follow a straight line (or even a little bit curved), we need to find a way to control it, and
find a way to control it, and correct its movement and trajectory.
One of the most effective and used methods for control is the method known as "PID" (PID = Power Inducted Device).
under the name "PID" (Proportional, Integral, Derivative). This method aims to minimize
an error, by finding a linear equation that calculates the correction to be applied to the
the trajectory, which is in the form :

D = Kp.P + Kd.D + Ki.I

Where :

P: It is the value of the error.

D: It is the derivative of the error with respect to time.

I: It is the integral of the error with respect to time.
 ## Movement functions
In addition to the basic movement function, the one that allows to follow a straight line.
straight line. We need functions that will allow us to make rotations and to follow
to follow 90° turns and to stop.
The functions that allow this are :

`void right()`

`void left()`

`void rotation()`

`void stoop()`

## Maze solving functions
The best known rule for traversing mazes is the wall follower, also known as the left or right rule.
also known as the left-hand rule or the right-hand rule.The two functions are named as follow:

`void LH()`

`void RH()`

`void short_path(int v[], int tiime[], int taille)`:
The purpose of this function is to give the different movements to reach the exit of the labyrinth
of the labyrinth, while removing all dead ends, it does not necessarily give the optimal
the optimal solution but gives us a solution that will take much less time than a simple
than a simple passage following the right hand rule or the left hand rule,
but in the case of simple labyrinths (no islands), it will give the
shortest path. For labyrinth sizes smaller than 20x20 the solution given by this function
function is quite satisfactory and is almost the same solution if one had applied a
search algorithm like Djikstra or A*.

`void translate()`:This function translate the path given from short path function into mouvement using the movement function .


 
