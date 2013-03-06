#include "stack.hpp"
#include "node.hpp"

#include <cstdlib.h>
#include <string>

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
  else 
  cout<< "Error: You cannot pop anything from an empty stack." << endl;

}/*pop*/

string Stack::peek(){
  return top->getData();
}

void Stack::push( const Obj& newData )
{
  Node<string> *Node1;
  /*creates new Node*/
  Node1 = new Node<string>();

  Node1->setData( newData );
  Node1->setNext(  top );
  /*top equals the new Node*/
  top = Node1;
}/*push*/
