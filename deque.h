/**
 * @file deque.h
 * @author Connor Walsh
 * @date 2022-11-18
 * @brief Stuff
 * 
 * Stuff
 */

#ifndef DEQUE_H
#define DEQUE_H

class deque{
 private:
  
  int** blockmap; 
  int size;
  bool isEmpty;
  int mapSize;
  int blocksize;
  int first_block;
  int first_element; 

 public:
  deque();
  ~deque();
  //void push_front(); //what does this take as a parameter? 
  //void pop_back();
  //void push_front();
  //void pop_back();
  //front(); //return a copy of the item at the location
  //back(); //need to know the return type
  bool empty();
  int getSize();
  int& operator[](int i);

};

#endif //DEQUE_H
