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
  Node<string> *top;
};

//copy past node code here :-)

#endif
