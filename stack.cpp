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

Stack::~Stack(){
	while ( top!=NULL) 
		pop();
}
string Stack::pop()
{
  string retMe = "";
	/*creates temp*/
  Node<string> *temp;
  
  if(top != NULL) {
		retMe = top->getData();
		temp = top;
		top = top->getNext();
    delete temp;
  }
  
	return retMe;
}/*pop*/

string Stack::peek(){
  if( top ){
    return top->getData();
  }
  else {
    return "";
  }
}

void Stack::push(  string newData )
{
  Node<string> *Node1;
  /*creates new Node*/
  Node1 = new Node<string>();

  Node1->setDatas( newData );
  Node1->setNext(  top );
  /*top equals the new Node*/
  top = Node1;
}/*push*/
