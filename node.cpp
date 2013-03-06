
#include "node.hpp"

template <class prim>
Node<prim>::Node( prim  datas ){
  data = datas;
  nextNode = 0;
}

template <class prim>
Node<prim>::Node(prim  datas, Node<prim>* next ){
  data = datas;
  nextNode = next;
}

template <class prim>
Node<prim>::~Node( ){
  
}

template <class prim>
Node<prim>* Node<prim>::getNext(){
  return nextNode;
}

template <class prim>
void Node<prim>::setNext( Node<prim>*  next ){
 nextNode  = next;
}

template <class prim>
void Node<prim>::setDatas( prim datas){
  data = datas;
}


template <class prim>
prim Node<prim>::getData( ){
  return data;
}
