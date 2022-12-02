# Collaboration Assignment 3: Deque Toolkit
Group: Code4Days (Isaac Copeland, Connor Walsh, Kyle Byassee)
Date: 10/28/2022

This program is a deque data structure that stores integers. A deque is a type of dynamic sequence container with two ends that can be added to or removed from. Running the driver runs tests on the deque that demonstrate how this data structure works. 

## How to Run
* Type "make" to compile the program.
* Type ./deque to run the executable created by the compilation process.
* Type "make clean" to remove unwanted files created by the compilation process.
* When the executable is run, the tests are executed and printed automatically. There is no user interaction.

## Design Decisions
* Both the front() and back() methods were programmed to use the operator method instead of executing calculations themselves.
* The dynamic array is fully initialized from the start and is copied and then replaced by new arrays when the deque has to resize to store more values.
* We attempted to make a test case to show off every single aspect of the deque program.
* The pop_front and pop back methods work like a circular array where the element technically isn't removed from the deque, but it is now able to be overwritten by the next element that is pushed in. The elements gets ignored and then overwritten.
* The operator method in the deque utilizes the "computing row based on index" example code from the lecture.

## Challenges
* This was the hardest coding assignment all semester. 
* Trying to get the push_front method to work was hard due to weird errors like printing zeros.
* Everyone has been very busy this week so it was hard to meet and also get the project done in general.
* Currently, the deque stops working properly when large quantities of elements are pushed onto both sides at the same time and then printed. This issue has not yet been fixed. 

## How We Shared Work
* We had to work on the project whenever possible to get it done.
* Connor began the project and Kyle heavily revised it towards the end. Isacc commented some of the code and brainstormed.