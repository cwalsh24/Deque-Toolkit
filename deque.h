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
  
  //T** blockmap currently dont know what this is

 public:
  deque();
  ~deque();
  void push_front(); //what does this take as a parameter? 
  void pop_back();
  void push_front();
  void pop_back();
  //front(); //return a copy of the item at the location
  //back(); //need to know the return type
  bool empty();
  int size();
  //operator[] 

};

#endif //DEQUE_H
