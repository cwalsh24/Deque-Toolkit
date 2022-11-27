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
  
  //initializes the 2D array 
  blockmap = new int *[mapSize];
  blockmap[first_block] = new int[blocksize];
}

deque::~deque(){

}

int deque::getSize(){
  return size;
}

bool deque::empty(){
  bool isEmpty = false;
  if(size == 0){
    isEmpty = true;
  }
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
  return operator[](0);
}

int deque::back(){ 
  return operator[](size - 1);
}

int& deque::operator[](int i){ 
  //The row and column indices are calculated and the correct
  //value in the 2D array is returned.
  int row = first_block + (first_element + i) / blocksize;
  int column = (first_element + i) % blocksize;

  return blockmap[row][column];
}
