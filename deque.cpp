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
  size = 0;
  
  //sets the number of rows, 8 seemed like a good number.
  mapSize = 8;

  //sets the starting value for the first_block, which is the middle one in the blockmap
  first_block = mapSize / 2;

  last_block = first_block;

  //sets the amount of entries allowed per block, 128 seemed like a good number.
  blockSize = 128;
  
  //the middle of the row seemed to be a good starting point
  first_element = 0;

  //last_element == first_element to start
  last_element = first_element;
  
  //initializes the 2D array with mapSize number of rows
  blockmap = new int *[mapSize];

  //starting position is the middle of the middle block.
  blockmap[first_block] = new int[blockSize];
}

deque::~deque(){
  // Deletes every row in the deque
  for(int i = 0; i < mapSize; i++){
    delete [] blockmap[i];
  }
  // Then deletes the deque itself
  delete [] blockmap;
}

int deque::getSize(){
  return size;
}

bool deque::empty(){
  if(size != 0){
    return false;
  }
  return true;
}

void deque::push_front(int number){
  // If size == 0
  if(size == 0){
    blockmap[first_block][first_element] = number;
    size++;
    return;
  }

  // If end of row is not reached
  if(first_element > 0){
    first_element--;
    blockmap[first_block][first_element] = number;
    size++;
    return;
  }
  
  // If end of row is reached && no resize
  if(first_block > 0){
    first_block--;
    first_element = blockSize - 1;
    
    //initialize the previous row.
    //blockmap[first_block] = new int[blockSize];
    
    blockmap[first_block][first_element] = number;
    size++;
    return;
  }
  
  // If first block == 0 ... make a new map
  mapSize *= 2;
  int **mapReplacement = new int*[mapSize];
  first_block = mapSize / 2;
  mapReplacement[first_block] = new int[blockSize];
  // Copy all of the values in blockmap
  for(int i = 0; i < mapSize / 2; i++){
    mapReplacement[i] = blockmap[i];
  }
  //blockmap points at the new map
  blockmap = mapReplacement;

  // Sets the indexes
  first_block--;
  first_element = blockSize - 1;
  
  //number is stored in the blockmap
  blockmap[first_block][first_element] = number;
  size++;
}

void deque::push_back(int number){ //not working right
  //if the first and last element values are the same then the element is inserted
  //in the index to the right of the first element. 
  /**  if(first_element == last_element){
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
  
  
  if(size == 0){
    blockmap[last_block][last_element] = number;
    size++;
    return;
  }

  // If end of row is not reached
  if(last_element < blockSize - 1){
    last_element++;
    blockmap[last_block][last_element] = number;
    size++;
    return;
  }
  
  // If end of row is reached && no resize
  if(last_block < mapSize){
    last_block++;
    last_element = 0;
    blockmap[last_block][last_element] = number;
    size++;
    return;
  }
  
  // If last block == mapSize then resize
  mapSize *= 2;
  int **mapReplacement = new int*[mapSize];
  last_block = mapSize / 2;
  mapReplacement[last_block] = new int[blockSize];
  
  // Copy all of the values in blockmap
  for(int i = 0; i < mapSize / 2; i++){
    mapReplacement[i] = blockmap[i];
  }
  
  // blockmap points at the new map
  blockmap = mapReplacement;

  // Sets the indexes
  last_block++;
  last_element = 0;

  // Stores number
  blockmap[last_block][last_element] = number;
  size++;
}
  
void deque::pop_front(){
  if(size == 0){
    return;
  }
  //shifts the first_element value right
  first_element++;
  size--;
}

void deque::pop_back(){
  if(size == 0){
    return;
  }
  //shifts the first_element value left
  last_element--;
  size--;
}

// The row and column indices are calculated and the blockmap value is returned
int& deque::operator[](int i){
  int row = first_block + ((first_element + i) / blockSize);
  int column = (first_element + i) % blockSize;
  
  return blockmap[row][column];
}

// Calls the [] operator
int deque::front(){
  return operator[](0);
}

// Calls the [] operator
// size - 1 for 0 based indexing
int deque::back(){
  return operator[](size - 1);
}
