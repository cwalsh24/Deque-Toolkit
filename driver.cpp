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
  //tests for the empty() and size() methods
  cout << "Test for the empty() and size() methods: " << endl << endl;
  
  //if the empty() method evaluates to false, we know that the deque is starting empty
  if (d.empty() == true){
  cout << "The deque is currently empty. " << endl;
  }
  
  //prints the size using the size() method to show the user that the deque is empty
  cout << "The size of the deque is currently " << d.getSize() << "." << endl << endl;
  
  //pushes 1000 integers into the deque
  cout << "push_back test with 1000 integers: " << endl << endl;
  cout << "Reading in integers..." << endl;
  for(int i = 0; i < 1000; i++){
    d.push_back(i);
  }
  
  cout << "Done. Printing deque..." << endl << endl;
  for(int i = 0; i < 1000; i++){
  cout << d[i] << " ";
  }
  
  cout << endl << endl;
  
  //tests for the front and back methods
  cout << "Front and back method tests: " << endl << endl;  
  cout << "The number at the front of the deque is " << d.front() << "." << endl;
  cout << "The number at the back of the deque is " << d.back() << "." << endl << endl;

  //tests the brace operator
  cout << "Brace operator test: Changing a value in the deque" << endl << endl;
  cout << "The number at index zero is " << d[0] << "." << endl;
  cout << "If deque[0] is set to equal 400..." << endl;
  d[0] = 400;
  cout << "The number at index zero is " << d[0] << "." << endl << endl;

  //pops 999 numbers 
  cout << "Test for pop_back: 999 elements popped:" << endl << endl;
    for(int i = 0; i < 999; i++){
    d.pop_back();
  }
  
  cout << "Done. Printing deque..." << endl << endl;
  for(int i = 0; i < d.getSize(); i++){
  cout << d[i] << " ";
  }
  
  cout << endl << endl;
  
  //shows both sides of the deque with a few numbers in them
  cout << "Reading in a few more integers..." << endl;
  for(int i = 0; i < 5; i++){
    d.push_back(i);
  }

  cout << "Done. Printing deque..." << endl << endl;
  for(int i = 0; i < d.getSize(); i++){
    cout << d[i] << " ";
  }

  cout << endl << endl;

  cout << "We can see here that 400 is at the front of the deque." << endl << endl; 
    
  cout << "push_front test with 1000 integers: " << endl << endl; //push front is doing the zeros thing, weird numbers
  cout << "Reading in integers..." << endl;
  for(int i = 0; i < 500; i++){
    d.push_front(i);
  }

  cout << d.getSize() << endl << endl; 
  
  cout << "Done. Printing deque..." << endl << endl;
  for(int i = 0; i < d.getSize(); i++){
  cout << d[i] << " ";
  }
  
  cout << endl << endl;

  cout << "There are now " << d.getSize()<< " elements in the deque." << endl << endl;

  cout << "Test for pop_front method: " << endl << endl;
  cout << "If 499 numbers are popped..." << endl << endl;
  for(int i = 0; i < 499; i++){
    d.pop_front();
  }

  cout << "Done. Printing deque..." << endl << endl;
  for(int i = 0; i < d.getSize(); i++){
    cout << d[i] << " ";
  }
  cout << endl << endl;
  cout << "The size is now " << d.getSize() << "." << endl << endl;

  //cout << endl << endl;
  
  return 0;
}
