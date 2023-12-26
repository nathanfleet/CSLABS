// Nathan Fleet
// LAB 3 : Templated List
// 9/10/23
// FILE  : Collection.hpp

#ifndef COLLECTION_HPP_
#define COLLECTION_HPP_

#include "List.hpp"

template<typename T>
class Collection {
public:
    Collection () : first_(nullptr) {};

    void add   (const T&);
    void remove(const T&);
    T    last  () const;
    void print () const;

    template<typename U>
    friend bool equal(const Collection<U>&, const Collection<U>&);

private:
    node<T>* first_;
};

template<typename T>
void Collection<T>::add(const T& item) { // add to front
    // create pointer to the memory location for the new node object
    node<T>* newNode = new node<T>;
    // set data for new node
    newNode->setData(item);
    // link new node to node that was already in the list
    newNode->setNext(first_);
    // set the new first node to be the recently added node
    first_ = newNode;
}

template<typename T>
void Collection<T>::remove(const T& item) {
    node<T>* prev = nullptr;
    node<T>* curr = first_;

    // while not at end of list
    while(curr != nullptr) {
        // if the current node's data matches the remove data
        if(curr->getData() == item) {
            // store the next node in nextNode obj
            // (solution to accessing next node data after deallocating curr)
            node<T>* nextNode = curr->getNext();

            // if prev node pointer is not outside list
            if(prev != nullptr) {
                // point prev to the next item after the deleted node
                prev->setNext(curr->getNext());
                // deallocate the node
                delete curr;
            } else {
                // if prev pointer IS outside the list
                // update first item in the list
                first_ = nextNode;
                // deallocated the node
                delete curr;
            }

            // set the new current node pointer to next item in the list
            curr = nextNode;
        } else {
            // increment prev and curr pointers
            prev = curr;
            curr = curr->getNext();
        }
    }
}

template<typename U>
bool equal(const Collection<U>& lhs, const Collection<U>& rhs) {
    node<U>* curr1 = lhs.first_;
    node<U>* curr2 = rhs.first_;

    // iterating through both lists at same time
    // while either collection is  not at the end
    while(curr1 != nullptr && curr2 != nullptr) {
        // if the data does not match return false (lists not equal)
        if(curr1->getData() != curr2->getData()) {
            return false;
        }
        // increment 'current' pointers
        curr1 = curr1->getNext();
        curr2 = curr2->getNext();
    }

    // if both pointers are at the end then return true (equal)
    // if one pointer is not at the end then the lists are not equal (false)
    return (curr1 == nullptr && curr2 == nullptr);
}

template<typename T>
T Collection<T>::last() const {
    // return data of node most recently added to the lsit
    return first_->getData();
}

template<typename T>
void Collection<T>::print() const {
    node<T>* curr = first_;

    // while not at end of lsit
    while(curr != nullptr) {
        // print node data
        std::cout << curr->getData() << std::endl;
        // increment pointer
        curr = curr->getNext();
    }
}

#endif