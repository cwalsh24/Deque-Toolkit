#include "deque.h"
#include <iostream>

deque::deque(){
  //initializes the size at zero
  size = 0;
  //sets isEmpty to be true by default
  isEmpty = true;
  //sets the size of the rows in the array
  mapSize = 10;
  //first_element not sure what these are for yet
  //first_block
  blocksize = 512; //in class it said 4096 so we might want to use that, 1024, 512 etc. 
  
  //initializes the 2D array 
  blockmap = new int *[mapSize];
}

deque::~deque(){

}

int deque::getSize(){
  return size;
}

bool deque::empty(){
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

int& deque::operator[](int i){
  //The row and column indices are calculated and the correct
  //value in the 2D array is returned.
  int row = first_block + (first_element + i) / blocksize;
  int column = (first_element + i) % blocksize;

  return blockmap[row][column];
}
