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
  cout << "This is a test for deque functionality: " << endl << endl;
  //if the empty() method evaluates to false, we know that the deque is starting empty
  if (d.empty() == true){
    cout << "The deque is currently empty. " << endl;
  }
  //prints the size using the size() method to show the user that the deque is empty
  cout << "The size of the deque is currently " << d.getSize() << "." << endl << endl;
  cout << "Reading in integers..." << endl << endl;

  return 0;
}
