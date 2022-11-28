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
  blockSize = 512; 
  
  //initializes the 2D array using the previous variables and sets the deque
  //starting position. 
  blockmap = new int *[mapSize];
  blockmap[first_block] = new int[blockSize];
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

void deque::push_front(int number){
  //row = first_block; //possibly delete later
  //column = first_element;
  //if the column position isn't zero (out of space) then the element can be added.
  if(0 < first_element){
    //updates the first element so the new number is the first element.
    first_element--;
    //sets the index before the first_element to equal the number. 
    blockmap[first_block][first_element] = number;
    //size is increased to keep track if all elements in the deque. 
    size++;
  }
  else{
    //if there is a previous row exists, the entry is placed there
    if(0 < first_block - 1){
      //this line sets the first block in the row, the minus one is to account for zero
      //Without the minus 1, the program crashes. 
      blockmap[first_block - 1] = new int[blockSize];
      //makes the first_element the last entry in the in the new block. 
      first_element = blockSize - 1;
      //sets the first block to be the one we are currently on. 
      first_block--;
      //sets the index in the block to equal the number we are inserting.
      blockmap[first_block][first_element] = number;
      //increases the size to keep track of the elements in the deque. 
      size++;
    }
    //TODO NEED TO ADD CASE FOR IF THE PREVIOUS ROW DOESN'T EXIST 
  }   
}

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
  int row = first_block + (first_element + i) / blockSize;
  int column = (first_element + i) % blockSize;

  //the element in the 2D array is returned to the user. 
  return blockmap[row][column];
}
