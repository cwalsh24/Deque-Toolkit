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
  //sets the number of array rows. The deque starts with 10.  
  mapSize = 10;
  //sets the value for the first element position in the deque
  //the middle of the row seemed to be a good starting point
  first_element = 50;
  //sets the starting value for the first_block, which is the middle one in the
  //blockmap
  first_block = 5;
  //sets the amount of entries allowed per block, 100 seemed like a good number. 
  blockSize = 100; 
  //initializes the 2D array using the previous variables and sets the deque
  //starting position in the middle of the middle block. 
  blockmap = new int *[mapSize];
  blockmap[first_block] = new int[blockSize];
  //sets last_element to begin as being equal to first_element to start
  last_element = first_element;
}

deque::~deque(){
  //loop deletes every row in the deque with their columns
  for(int i = 0; i < mapSize; i++){
    delete [] blockmap[i];
  }
  //sets blockmap pointer to null to avoid deleting something bad
  blockmap = nullptr;
  //deletes pointer 
  delete [] blockmap; 
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
  //if there is nothing inside of the deque, the number is placed
  //in the index of the first element (50) in block 5 
  if(size == 0){
    blockmap[first_block][first_element] = number;
    //the size is increased to account for the new entry
    size++;
  }
  //if there is already information stored in the deque, the following
  //if and else statements are executed.
  else{
    //If the first_element value is greater than zero (still inside the row)
    //then the element is added to the row in the previous index to the first_element.
    if(0 < first_element){ 
      //the first element is shifted to the left by one to add the new number
      first_element--;
      //the number is added in the new index position
      blockmap[first_block][first_element] = number;
      //the size is increased to account for the new number.
      size++;
    }
    //if the block is full then the element must be shifted to the previous row
    //or a new row needs to be created.
    else{
      //if the first block value is greater than zero (it starts at 10) then the previous
      //row can be used.
      if(0 < first_block){
	//first_element's value must be changed to that of the last index of the previous row.
	first_element = blockSize - 1;
	//first_block's value is reduced by 1 to move to the previous row. 
	first_block--;
	//the previous row now has to be initialized with the proper size.
	blockmap[first_block] = new int[blockSize];
	//this line fills the index with the number
	blockmap[first_block][first_element] = number;
	//the size is increased to account for the new number. 
	size++;
      }
      
      //This condition is executed if there is no previous row that exists.
      else{
	//creates a new blockmap that is one row larger so we can store
	//the number in the deque
	int **mapReplacement = new int*[mapSize + 1];
	
	//first_block is now set to zero to start at the beginning of the blockmap
	first_block = 0;
	//the new row that was added is initialized
	mapReplacement[first_block] = new int[blockSize];
	//first_element is now changed to be set at the last index of the row
	first_element = blockSize - 1;

	//This loop copies over all of the values stored in the previous blockmap.
	//We need the + 1 because the new row was not included there and we need to
	//skip it. Without it, we get a segmentation fault.  
	for(int i = 0; i < mapSize; i++){
	  mapReplacement[i + 1] = blockmap[i];
	}

	//blockmap now points at the new map 
	blockmap = mapReplacement;
	//the number is placed inside of the new row at the proper index
	blockmap[first_block][first_element] = number;
	
	//the mapSize is increased to account for the new row. 
	mapSize++;
	//size is increased to account for the new entry
	size++;
      }
    }
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
