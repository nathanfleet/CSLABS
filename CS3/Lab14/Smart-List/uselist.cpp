// demoes list template usage
// Nathan Fleet
// 11/27/2023

#include <iostream>
#include "list.hpp" // list template

using std::cout; using std::endl; using std::make_shared;

int main(){
   // creating nodes
   auto node1 = make_shared<node<int>> (1);
   auto node2 = make_shared<node<int>> (2);
   auto node3 = make_shared<node<int>> (3);

   // linking nodes
   node1->setNext(node2);
   node2->setPrev(node1);
   node2->setNext(node3);
   node3->setPrev(node2);

   cout << "==========FORWARD TRAVERSAL==========" << endl;

   // traversing nodes forwards
   auto currentNode = node1;
   while (currentNode != nullptr) {
      std::cout << currentNode->getData() << endl;
      currentNode = currentNode->getNext();
   }

   cout << endl << "==========BACKWARD TRAVERSAL==========" << endl;

   // traversing nodes backwards
   currentNode = node3;
   while (currentNode != nullptr) {
      std::cout << currentNode->getData() << endl;
      currentNode = currentNode->getPrev();
   }

   return 0;
}