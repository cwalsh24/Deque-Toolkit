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
  //sets the number of array rows. 
  mapSize = 10;
  //sets the values for the starting block and first element position in the deque
  first_element = 50; 
  first_block = 5;
  //sets the size of the blocks
  blockSize = 512; 
  //initializes the 2D array using the previous variables and sets the deque
  //starting position in the middle block. 
  blockmap = new int *[mapSize];
  blockmap[first_block] = new int[blockSize];
  //sets last_element to begin as being equal to first_element
  last_element = first_element;
}

deque::~deque(){
  //Isaac - since a deque is a 2D dynamic array, the destructor should start to free memory at
  //the deepest level, starting with each int* array within the higher int** array and working
  //its way up the chain
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
  //if the element (column) position isn't zero (out of space) then the element can be added.
  if(0 < first_element){
    //updates the first element so the new number is the first element.
    first_element--;
    //increases the last element value so the end of the deque can be kept track of
    last_element++; 
    //sets the index before the first_element to equal the number. 
    blockmap[first_block][first_element] = number;
    //size is increased to keep track of all elements in the deque. 
    size++;
  }
  else{
    //if there is a previous block (row) exists, the entry is placed there
    if(0 < first_block - 1){
      //sets the first block to be the one we are currently on.
      first_block--; 
      //this line sets the first block in the row, the minus one is to account for zero 
      blockmap[first_block] = new int[blockSize];
      //makes the first_element the last entry in the in the new block. 
      first_element = blockSize - 1;
      //sets the last element to be equal to the first in the new block since it
      //is now the rightmost entry in the new row. 
      last_element = first_element;  
      //sets the index in the block to equal the number we are inserting.
      blockmap[first_block][first_element] = number;
      //increases the size to keep track of the elements in the deque. 
      size++;
    }
    //TODO NEED TO ADD CASE FOR IF THE PREVIOUS ROW DOESN'T EXIST 
  }   
}

/**void deque::push_back(int number){ //not working right
  //if the first and last element values are the same then the element is inserted
  //in the index to the right of the first element. 
  if(first_element == last_element){
    last_element++;
    blockmap[first_block][last_element] = number;
    //size is increased to account for the new element. 
    size++;
  }
  else{
    //if the last element value is less than the blockSize (meaning that the row block isn't full)
    //then the new element can be inserted in this position. We need the minus 1 due to the array.
    if(last_element < blockSize - 1){
      blockmap[first_block][last_element] = number;
      last_element++;
      size++;
    }
    //if the block is full... 
    
    }**/ 

void deque::pop_front(){
  //this needs to be here to avoid size going into negatives
  if(size == 0){
    return;
  }
  //shifts the first_element value right, ignoring the popped value
  first_element++;
  //reduces the size count to account for the popped element
  size--;
}

void deque::pop_back(){
  //this needs to be here to avoid size going into negatives
  if(size == 0){
    return;
  }
  //shifts the first_element value left, ignoring the popped value
  last_element--;
  //reduces the size count to account for the popped element
  size--;
}

int& deque::operator[](int i){ 
  //The row and column indices are calculated and the correct
  //value in the 2D array is returned. This is based on in class example. 
  int row = first_block + ((first_element + i) / blockSize);
  int column = (first_element + i) % blockSize;
  //the element in the 2D array is returned to the user. 
  return blockmap[row][column];
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
