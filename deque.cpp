#include "deque.h"
#include <iostream>

deque::deque(){
  size = 0;
  mapSize = 50; //width
  int** arr = new int *[mapSize];
  for(int i = 0; i < mapSize; i++){
    arr[i] = new int[blocksize];
  }
}

deque::~deque(){

}

int deque::getSize(){
  return size;
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
