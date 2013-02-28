#include <iostream>
#include <fstream>
#include "stack.hpp"

using namespace std;

int main() {
  ifstream input;
  input.open("input.txt");

  /**
   *infix->postfix
   *loop
   *if '(' push onto stack
   *elsif ')' pop and place in output until an '('
   *
   *"do not put ( ) in output
   *
   *elsif operator
   *if stack empty or stack top '(' then push operator
   *elsif operator precendence is > than stack top then push oper onto stack
   *elsif precendenc <= stack top then pop and place in output and do so for each <= then push new oper onto stack
   *
   *elsif number place in output
   *
   *else {eof} pop all values to output
   *
   *
   *if any problems poping then invalid input
   *
   *evaluation: push until operator then eval and push ans back on stack
   */


  input.close();
  return 0;
}
