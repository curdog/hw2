// CLASS PROVIDED:  List (an ADT for a fraction)
//
// CONSTRUCTOR for the List class:
//   List()
//     Description: 	constructor will initialize List objects
//     Preconditions: none
//     Postcondition: creates object of type List
//
// MODIFICATION MEMBER FUNCTIONS for the List class
//   void setsize (const char value)
//     Description: 	set the size of the array
//     Precondition: value is an integer
//     Postcondition: pointer is set to the address of the array
//
//   void insert(const int value)
//     Description: 	fills the array
//     Precondition: value is an integer
//     Postcondition: first slot of the array is set to num
//
//   void setcount  (const int value)
//     Description: 	sets the memory location of the pointer
//     Precondition: value is an integer
//     Postcondition: location has been set to value
//
// CONSTANT MEMBER FUNCTIONS for the Fraction class
//   int getcount (void) const
//     Description: 	obtains the location of the pointer
//     Preconditions: none
//     Postcondition: count is returned
//
//   int getsize(void) const
//     Description: 	obtains the size of the array
//     Preconditions: none
//     Postcondition: size is returned
//
//   void print (void) const
//     Description: 	print the values that are in the array
//     Preconditions: none
//     Postcondition: values of the array are displayed on the screen

#ifndef STACK_
#define STACK_

#include <string>

using namespace std;

class Stack{
 public:
  Stack();
  string pop();
  string peek();
  void push( string );
 
 private:
  /*pointer to the top*/
  Node<string> *top;
};

//copy past node code here :-)

#endif /*STACK_H*/
