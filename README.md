# Collaboration Assignment 3: Deque Toolkit
Group: Code4Days (Isaac Copeland, Connor Walsh, Kyle Byassee)
Date: 10/28/2022

This program is a deque data structure that stores integers. Running the driver runs tests on the deque. 

## How to Run
* Type "make" to compile the program.
* Type ./deque to run the executable created by the compilation process.
* Type "make clean" to remove unwanted files created by the compilation process.
* When the executable is run, the tests are executed and printed automatically. There is no user interaction.

## Design Decisions
* For the operator method we based our code on the "computing row based on index" example code from the lecture.
* Both the front and back methods were programmed to use the operator method instead of doing any calculations themselves.
* The dynamic array is fully initialized from the start and is replaced with new arrays.
* We attempted to make a test case to show off every single aspect of the deque program.
* The pop front and pop back methods work like how they would in a circular array where the element technically isn't removed from the deque, but it is now able to be overwritten by the next element that is pushed in. It gets ignored and then overwritten essentially.

## Challenges
* This was the hardest coding assignment all semester. 
* Trying to get the push_front method to work was hard due to weird errors like printing zeros.
* Everyone has been very busy this week so it was hard to meet and also get the project done in general. 

## How We Shared Work
* We had to work on the project whenever possible to get it done.
* Connor began the project and Kyle heavily revised it towards the end. Isacc commented some of the code and brainstormed.