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
  
  //pushes 1000 integers into the deque
  cout << "push_front test with 1000 integers: " << endl << endl;
  cout << "Reading in integers..." << endl;
  for(int i = 0; i < 1000; i++){
    d.push_front(i);
  }
  
  //prints the integers contained inside of the deque
  cout << "Done. Printing deque..." << endl << endl;
  for(int i = 0; i < d.getSize(); i++){
    cout << d[i] << " ";
  }
  
  cout << endl << endl;
  
  cout << "The size of the deque is currently " << d.getSize() << "." << endl << endl;
  
  //tests front and back
  cout << "Front and back method tests: " << endl << endl;
  
  cout << "The number at the front of the deque is " << d.front() << "." << endl;
  cout << "The number at the back of the deque is " << d.back() << "." << endl << endl;

  //tests the brace operator
  cout << "Brace operator test: Changing a value in the deque" << endl << endl;
  cout << "The number at index zero is " << d[0] << "." << endl;
  cout << "If deque[0] is set to equal 400..." << endl;
  d[0] = 400;
  cout << "The number at index zero is " << d[0] << "." << endl << endl;

  //pops the first 997 elements
  cout << "Test for the pop_front() method:" << endl;
  cout << "If 997 elements are popped from the front of the deque and the first 5 elements are printed..."
       << endl << endl;
  for(int i = 0; i < d.getSize() - 3; i++){
    d.pop_front();
  }
  //prints the first 5 elements contained in the deque
  for(int i = 0; i < 5; i++){
    cout << d[i] << " ";
  }
  cout << endl << endl;
  
  cout << "The size of the deque is currently " << d.getSize()
       << " and we can see that that 2 is now at the front of the deque." << endl << endl;
  
  cout << "Behind 2 1 0 you can see zeros which are just empty indexes" << endl;
  
  //pushes 10 more integers into the deque
  for(int i = 0; i < 10; i++){
    d.push_front(2 * 2);
  }

  //
  for(int i = 0; i < 13; i++){
    cout << d[i] << " ";
  }
  
  cout << endl;
  cout << "From this we can see that the new integers have filled the deque" << endl;
  
  //pushes 1000 integers into the deque
  cout << "push_back test with 1000 integers: " << endl << endl;
  cout << "Reading in integers..." << endl;
  for(int i = 0; i < 1000; i++){
    d.push_back(i);
  }
  
  //prints the integers contained inside of the deque
  cout << "Done. Printing deque again..." << endl << endl;
  for(int i = 0; i < d.getSize(); i++){
    cout << d[i] << " ";
  }
  cout << endl;
  
  return 0;
}
