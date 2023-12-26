#ifndef STACK_HPP_
#define STACK_HPP_
////////////////////////////////////////////////////////////////////////////
//
// File: stack.hpp
//
// Programmer: Nathan Fleet
// Updated:    Spring 2022
//
//
// Do not change the names of the classes or methods.  Otherwise, instructor
//  tests will not work.
//

#include <new>
#include <cassert>

////////////////////////////////////////////////////////////////////////////
//
template<typename T>
class Node {
public:
    Node() : next(nullptr) {};
    Node(const T& x) : data(x), next(nullptr) {}
    T   data;       //the data (element)
    Node<T>* next;  //pointer to a node
};


////////////////////////////////////////////////////////////////////////////
// CLASS INV:
//
//
template <typename T>
class stack {
public:
    stack() : tos(nullptr) {};
    stack(const stack<T>&);
    ~stack();
    void      swap(stack<T>&);
    stack<T>& operator= (stack<T>);
    bool      empty() const { return tos == 0; };
    bool      full() const;
    T         top() const;
    T         pop();
    void      push(const T&);

private:
    Node<T>* tos;
};

template <typename T>
void stack<T>::push(const T& item) {
    assert(!full());
    Node<T>* temp = new Node<T>(item);
    temp->next = tos;
    tos = temp;
}

template <typename T>
T stack<T>::pop() {
    assert(!empty());
    T result = tos->data;
    Node<T>* temp = tos;
    tos = tos->next;
    delete temp;
    return result;
}

template <typename T>
stack<T>::~stack() { //destructor
    Node<T>* temp;
    while (tos != 0) {
        temp = tos;
        tos = tos->next;
        delete temp;
    }

}

template <typename T>
stack<T>::stack(const stack<T>& actual) : stack() { //copy ctor
    Node<T>* temp = actual.tos;
    Node<T>* bottom = actual.tos;
    while (temp != 0) {
        if (tos == 0) {
            tos = new Node<T>(temp->data);
            bottom = tos;
        }
        else {
            bottom->next = new Node<T>(temp->data);
            bottom = bottom->next;
        }
        temp = temp->next;
    }

}

template <typename T>
void stack<T>::swap(stack<T>& rhs) {
    Node<T>* temp = rhs.tos;
    rhs.tos = tos;
    tos = temp;
}

template <typename T>
stack<T>& stack<T>::operator=(stack<T> rhs) {
    swap(rhs);
    return *this;
}

template <typename T>
bool stack<T>::full() const {
    Node<T>* temp = new(std::nothrow) Node<T>();
    if (temp == 0) return true; //no more memory
    delete temp;                //deallocate what you allocated
    return false;
}

template <typename T>
T stack<T>::top() const {
    return tos->data;
}

#endif