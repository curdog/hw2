// CLASS PROVIDED:  Stack
//
// CONSTRUCTOR for the List class:
//   Stack()
//     Description: constructor will initialize Stack to NULL
//     Preconditions: none
//     Postcondition: creates object of type Stack
//
// MODIFICATION MEMBER FUNCTIONS for the List class
//   void push()
//     Description: pushes value onto the stack
//     Precondition: value is an integer
//     Postcondition: pointer is set to the address of the array
//
//   void pop()
//     Description:  removes values from stack, pops to output file 
//     Precondition: if Stack is not NULL
//     Postcondition: deletes temp or error message
//
//   void peek  (const int value)
//     Description:      sets the memory location of the pointer
//     Precondition: creates pointer and creates new Node
//     Postcondition: top equals new Node
//
//   void ~Stack()
//     Description: destructor
//     Precondition: none
//     Postcondition: all the values are removed from the stack
//
//   bool FullStack();
//     Description: true or false return
//     Precondition: none
//     Postcondition: returns false
//
//   bool EmptyStack();
//     Description: true or false 
//     Precondition: none
//     Postcondition: return top == NULL
//
//   void print (void) const
//     Description:      print the values that are in the stack
//     Preconditions: none
//     Postcondition: values of the stack are displayed on the screen

#ifndef STACK_
#define STACK_

#include <string>
#include "node.hpp"

using namespace std;

class Stack{
 public:
  /*constructor*/
  Stack();

  /*destructor*/
   ~Stack();

  string pop();
  string peek();
  void push( string& ); 
  bool FullStack() const;
  bool EmptyStack() const;
 
 private:
  /*pointer to the top*/
  Node<string>* top;
};

#endif /*STACK_H*/
