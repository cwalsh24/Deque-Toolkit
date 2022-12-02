# Collaboration Assignment 3: Deque Toolkit
Group: Code4Days (Isaac Copeland, Connor Walsh, Kyle Byassee)
Date: 10/28/2022

This program is a deque data structure that stores integers. A deque is a type of dynamic sequence container with two ends that can be added to or removed from. Running the driver runs tests on the deque that demonstrate how this data structure works. This implementation of a deque takes integers and can either store them at the front or back of the deque or pop them from either end. Elements inside of the deque can be accessed and manipulated via the [] operator and the elements at the front and back of the deque can be returned to the user at any time by calling their respective accessor methods. Lastly, this implementation of the deque contains an accessor method for whether or not the queue is empty, which returns a bool value, and one of the number of elements in the queue, which returns an integer.

## Container properties
* The deque is a sequence containor meaning that its elements are arranged in a linear sequence of indexes. Specific elements can be accessed based on their possition in the sequence.
* The deque is backed by a dynamic, 2-dimensional array, which allows for direct access to any element contained in the deque and allows for fast insertion and deletion from the queue.

## Member functions
* (constructor)	Construct deque container (public member function)
* (destructor)	Deque destructor (public member function)
* Capacity: getSize Returns the number of elements in the deque
* Capacity: empty Tests to see if the deque is empty
* Element Access: operator[] Direct access to element
* Element Access: front Returns element at the front of the deque
* Element Access: back Returns element at the back of the deque
* Modifiers: push_front Adds element to the front of the deque
* Modifiers: pop_front Removes element from the front of the deque
* Modifiers: push_back Adds element to the back fo the deque
* Modifiers: pop_back Removes element from the back of the deque

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

## Observations
* Currently, the deque stops working properly when large quantities of elements are pushed onto both sides at the same time and then printed. This issue has not 
yet been fixed. This is either an operator or resizing problem. 
* The front() and back() methods work correctly as evidenced in the tests.
* push_front() and push_back() appear to be adding to the deque properly aside from the aformentioned issue.
* The destructor has been tested and is working properly.
* The empty() and getSize() methods work properly.

## Challenges
* This was the hardest coding assignment all semester. 
* Trying to get the push_front method to work was hard due to weird errors like printing zeros.
* Everyone has been very busy this week so it was hard to meet and also get the project done in general. 

## How We Shared Work
* We had to work on the project whenever possible to get it done.
* Connor began the project and Kyle heavily revised it towards the end. Isacc commented some of the code and brainstormed.