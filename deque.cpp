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
  // Empty state
  size = 0;

  // Number of rows, 8 seemed like a good number
  mapSize = 8;

  // Middle row in the blockmap
  first_block = mapSize / 2;

  // Empty condition
  last_block = first_block;

  // sets the amount of entries allowed per block, 128 seemed like a good number.
  blockSize = 128;

  // Beginning of middle row
  first_element = 0;

  // Empty condition
  last_element = first_element;

  // Initializes the 2D array with mapSize number of rows
  blockmap = new int *[mapSize];

  // Initializes each row
  for(int i = 0; i < mapSize; i++){
    blockmap[i] = new int[blockSize];
  }
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
  // If empty
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
    blockmap[first_block][first_element] = number;
    size++;
    return;
  }

  // If beginning of first row is reached, then resize
  /** mapSize++; /= 2;
  int **mapReplacement = new int*[mapSize];

  // Initialize the new map
  for(int i = 0; i < mapSize; i++){
    mapReplacement[i] = new int[blockSize];
  }

  // Copy all of the values in blockmap
  for(int i = 0; i < mapSize; i++){
    mapReplacement[i] = blockmap[i];
  }

  // blockmap points at the new map
  blockmap = mapReplacement;

  // Store number in the blockmap
  first_element = blockSize - 1;
  blockmap[first_block][first_element] = number;
  size++;**/
  // If beginning of first row is reached, then resize
  //mapSize++;
  int **mapReplacement = new int*[mapSize + 1];
  first_block = 0;
  // Initialize the new map
  for(int i = 0; i < mapSize; i++){
    mapReplacement[i] = new int[blockSize];
  }

  // Copy all of the values in blockmap
  for(int i = 0; i < mapSize; i++){
    mapReplacement[i + 1] = blockmap[i];
  }

  // blockmap points at the new map
  blockmap = mapReplacement;

  mapSize++;

  // Store number in the blockmap
  first_element = blockSize - 1;
  blockmap[first_block][first_element] = number;
  size++;
}


void deque::push_back(int number){
  // If empty
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
  if(last_block < mapSize - 1){
    last_block++;
    last_element = 0;
    blockmap[last_block][last_element] = number;
    size++;
    return;
  }

  // If end of last row is reached, then resize
  mapSize++; //*= 2;
  int **mapReplacement = new int*[mapSize];

  // Initialize the new map
  for(int i = 0; i < mapSize; i++){
    mapReplacement[i] = new int[blockSize];
  }

  // Copy all of the values in blockmap
  for(int i = 0; i < mapSize - 1; i++){
    mapReplacement[i] = blockmap[i];
  }

  // blockmap points at the new map
  blockmap = mapReplacement;

  // Set the indexes
  last_block++;
  last_element = 0;

  // Store number in the blockmap
  blockmap[last_block][last_element] = number;
  size++;
}

void deque::pop_front(){
  if(size == 0){
    return;
  }
  // Shifts first_element right
  // The first_element is free to be overwritten
  first_element++;
  size--;
}

void deque::pop_back(){
  if(size == 0){
    return;
  }
  // Shifts last_element left
  // The last_element is free to be overwritten
  last_element--;
  size--;
}

// The row and column indices are calculated and the blockmap value is returned
int& deque::operator[](int i){
  int row = first_block + ((first_element + i) / blockSize);
  int column = (first_element + i) % blockSize;

  return blockmap[row][column];
}

int deque::front(){
  return operator[](0);
}

int deque::back(){
  // size - 1 for 0 based indexing
  return operator[](size - 1);
}
