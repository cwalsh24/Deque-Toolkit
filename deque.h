/**
 * @file deque.h
 * @authors Connor Walsh, Isaac Copeland, Kyle Byassee (Code4Days)
 * @date 2022-11-18
 * @brief this is the deque header file
 * 
 * This header file contains the definition of the deque class. 
 */

#ifndef DEQUE_H
#define DEQUE_H


/**
 * The deque class represents a deque (double-ended queue) object that allows the 
 * user to push and pop integers from both ends of the queue.
 *
 * @class deque{ deque.h "deque/deque.h"
 * @brief class to create a deque object
 *
 */
class deque{
 private:
  
  int** blockmap; 
  int size;
  int mapSize;
  int blockSize;
  int first_block;
  int first_element;
  int last_block;
  int last_element;

 public:

/**
 * Default constructor for the deque class
 *
 * @pre A deque object must be declared in the driver. 
 * @post A deque object has been constructed and initialized. 
 * 
 */
  deque();
  ~deque();

/**
 * The push_front method pushes a new element onto the front of the deque.
 *
 * @param int number This is the element that is being added to the deque.
 * @pre There must be a deque object declared for the method to be run.
 * @return void This method returns nothing.
 * @post The integer has been added to the front of the deque.
 * 
 */
  void push_front(int number);
  void push_back(int number);

/**
 * This method removes the first element from the deque. This is accomplished 
 * by simply ignoring the element which will be overwritten if an element is pushed into its place.
 *
 * @pre There must be a deque object declared. 
 * @return void This method returns nothing.
 * @post The integer has been "popped" from the deque.
 * 
 */
  void pop_front();

/**
 * This method removes the last element from the deque. This is accomplished
 * by simply ignoring the element which will be overwritten if an element is pushed into its place.
 *
 * @pre There must be a deque object declared.
 * @return void This method returns nothing.
 * @post The integer has been "popped" from the deque.
 *
 */
  void pop_back();

/**
 * This method uses the operator method to print the first element in the deque.
 *
 * @pre A deque object must be declared.
 * @return int This function returns the first integer in the deque.
 * @post The first integer has been returned.
 * 
 */
  int front();
  
/**
 * This method uses the operator method to print the last element in the deque.
 *
 * @pre A deque object must be declared.
 * @return int This function returns the last integer in the deque.
 * @post The last integer has been returned. 
 *
 */
  int back(); 

/**
 * This function checks to see if the deque is empty and returns a boolean true 
 * or false value to tell the user if the deque is or isn't empty.
 *
 * @pre A deque object must be declared.
 * @return bool This function returns a true or false bool value depending on if 
 * the deque contains anything.
 * @post The true or false bool value has been returned.
 * 
 */
  bool empty();

/**
 * This method is a getter that returns the number of elements inside of the array.
 *
 * @pre A deque object must be declared.
 * @return int This function returns the number of elements in the deque as 
 * an integer.
 * @post The number of elements in the deque has been returned.
 * 
 */
  int getSize();

/**
 * This method allows for elements of the deque to be retrieved and altered using the brackets 
 * operator. 
 *
 * @param int i The method takes in an index value as a parameter. 
 * @pre A deque object must be declared. 
 * @return int& The method returns a reference to a position in the deque's array. 
 * @post The contents of the position in the deque have been retrieved.
 * 
 */
  int& operator[](int i);

};

#endif //DEQUE_H
