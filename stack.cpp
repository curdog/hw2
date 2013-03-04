#include "stack.hpp"

#include <string>

Stack::Stack()
{
/*initializes top to NULL*/
  top = NULL;
}

string Stack::pop()
{
  /*creates temp*/
  Node *temp;
  
  if(top != NULL)
  {
    temp = top;
    top = top->connect;
    delete temp;
  }
  else 
  cout<< "Error: You cannot remove anything from an empty list." << endl;

}/*pop*/

string Stack::peek(){

}

void Stack::push( const Obj& new )
{
Node *Node1;
/*creates new Node*/
Node1 = new Node;

Node1->info = new;
Node1->connect = top;
/*top equals the new Node*/
top = Node1;
}/*push*/
