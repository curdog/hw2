#include "stack.hpp"
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
    top = top->connect;
    delete temp;
  }
  else 
  cout<< "Error: You cannot pop anything from an empty stack." << endl;

}/*pop*/

string Stack::peek(){

}

void Stack::push( const Obj& new )
{
  Node<string> *Node1;
  /*creates new Node*/
  Node1 = new Node;

  Node1->info = new;
  Node1->connect = top;
  /*top equals the new Node*/
  top = Node1;
}/*push*/
