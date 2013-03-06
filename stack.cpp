#include "stack.hpp"
#include "node.hpp"

#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

Stack::Stack()
{
/*initializes top to NULL*/
  top = NULL;
}/*stack*/

string Stack::pop()
{
  /*creates temp*/
  Node<string> *temp;
  
  if(top != NULL)
    {
    temp = top;
    top = top->getNext();
    delete temp;
  }
  else{
    std::cout<< "Error: You cannot pop anything from an empty stack." << std::endl;
  }
}/*pop*/

string Stack::peek(){
  return top->getData();
}

void Stack::push(  string& newData )
{
  Node<string> *Node1;
  /*creates new Node*/
  Node1 = new Node<string>();

  Node1->setDatas( newData );
  Node1->setNext(  top );
  /*top equals the new Node*/
  top = Node1;
}/*push*/
