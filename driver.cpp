/**
 * @file driver.cpp
 * @authors Connor Walsh, Isaac Copeland, Kyle Byassee (Code4Days)
 * @date 2022-11-27
 * @brief driver code for the deque program
 *
 * This program contains a series of automated tests of the deque's 
 * functionality.
 */
#include "deque.h"
#include <iostream>

using namespace std;

int main()
{
  deque d;
  cout << "Test for the empty() and size() methods: " << endl << endl;
  //if the empty() method evaluates to false, we know that the deque is starting empty
  if (d.empty() == true){
    cout << "The deque is currently empty. " << endl;
  }
  //prints the size using the size() method to show the user that the deque is empty
  cout << "The size of the deque is currently " << d.getSize() << "." << endl << endl;

  cout << "push_front test with 1000 integers: " << endl << endl;
  cout << "Reading in integers..." << endl;
  cout << "Done. Printing deque..." << endl << endl;

  //pushes 1000 integers into the deque 
  for(int i = 0; i < 1000; i++){
    d.push_front(i);
  }

  //prints the integers contained inside of the deque 
  for(int i = 0; i < 1000; i++){
    cout << d[i] << " ";
  }
  
  cout << endl << endl;

  cout << "The size of the deque is currently " << d.getSize() << "." << endl << endl;

  cout << "Front and back method tests: " << endl << endl;
  cout << "The number at the front of the deque is " << d.front() << "." << endl;
  cout << "The number at the back of the deque is " << d.back() << "." << endl << endl;

  cout << "Operator test: Changing a value in the deque" << endl << endl; 
  cout << "The number at index zero is " << d[0] << "." << endl;
  cout << "If deque[0] is set to equal 400..." << endl; 
  d[0] = 400;
  cout << "The number at index zero is " << d[0] << "." << endl << endl;

  cout << "Test for the pop_front() method:" << endl; 
  cout << "If 997 elements are popped from the front of the deque..." << endl << endl;

  //pops the first 997 elements
  for(int i = 0; i < 997; i++){
    d.pop_front();
  }
  
  //prints the elements contained in the deque
  for(int i = 0; i < 3; i++){
    cout << d[i] << " ";
  }
  cout << endl << endl;

  cout << "The size of the deque is currently " << d.getSize() << "." << endl << endl;

  return 0;
}
