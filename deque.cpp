/**
 * @file deque.cpp
 * @authors Connor Walsh, Isaac Copeland, Kyle Byassee (Code4Days)
 * @date 2022-11-27
 * @brief deque implementation
 * 
 * This file contains the implementation of the methods for the deque class.
 */

#include "deque.h"
#include <iostream>

deque::deque(){
  //initializes the size at zero
  size = 0;
  //sets the size of the rows in the array
  mapSize = 10;
  //sets the values for the first block and first element in the deque
  first_element = 50; 
  first_block = 5;
  //sets the size of the blocks
  blocksize = 512; 
  
  //initializes the 2D array using the previous variables 
  blockmap = new int *[mapSize];
  blockmap[first_block] = new int[blocksize];
}

deque::~deque(){

}

int deque::getSize(){
  //returns the value of size to the user. 
  return size;
}

bool deque::empty(){
  bool isEmpty = false;
  //if the value of size is zero, the isEmpty variable
  //is changed to true. 
  if(size == 0){
    isEmpty = true;
  }
  //the isEmpty boolean is returned to the user. 
  return isEmpty; 
}

/**void deque::push_front(int number, int**& arr){
  if(size == 0){ //inserts in the middle, middle is the starting point for the deque
    arr[25][25] = number; //row, column
    size++;
  }
  else{
    //arr[+size?][]
  }

}
**/

int deque::front(){
  //This calls the operator method to return the element at the front
  //of the deque. 
  return operator[](0);
}

int deque::back(){
  //This calls the operator method to return the element at the back
  //of the deque. Subtracting 1 accounts for starting at index 0. 
  return operator[](size - 1);
}

int& deque::operator[](int i){ 
  //The row and column indices are calculated and the correct
  //value in the 2D array is returned. This is based on in class example. 
  int row = first_block + (first_element + i) / blocksize;
  int column = (first_element + i) % blocksize;

  //the element in the 2D array is returned to the user. 
  return blockmap[row][column];
}
