// CLASS PROVIDED:  Node<kind>
//   Description: Tempate Class for Nodes in a Single Linked Data Structure
//
// CONSTRUCTOR for the Node class:
//   Node( <kind>)
//     Description:  	Initializes a new node with data
//     Preconditions:  none
//     Postcondition:  New Node with data as well as a next Node = NULL
//
//   Node( <kind>, Node<kind>)
//     Description:  	Initializes a new node with data and a next node
//     Preconditions:  none
//     Postcondition:  New Node with data as well as a next Node
//
// MEMBER FUNCTIONS for the Node class
//   void setNext ( Node<kind>)
//     Description:  	Sets the next Node.
//     Precondition:   none
//     Postcondition:  Next Node is set.
//
//   Node<> getNext  ( void )
//     Description:  	Return the next node.
//     Precondition:   None
//     Postcondition:  None
//
//   void setDatas ( <kind> )
//     Description:  	Sets the value of the Node
//     Precondition:    none
//     Postcondition:  Internal data set.
//
//   <kind> getData  ( void )
//     Description:    Returns the data
//     Precondition:   none
//     Postcondition:  none
//

#ifndef _NODE_C
#define _NODE_C

template <class prim> class Node{

public:
  Node( prim );
  Node( prim, Node<prim>* );
  ~Node();
  
  Node<prim>* getNext( void );
  void setNext( Node<prim>* );
  void setDatas( prim );
  prim getData( void );
private:
  prim data;
  Node<prim> *nextNode;
};

#include "node.cpp"

#endif
