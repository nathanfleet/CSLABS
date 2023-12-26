// lists using smart pointers
// Nathan fleet
// 11/30/2023

#ifndef LIST_HPP_
#define LIST_HPP_

#include <iostream>
#include <memory>

using std::shared_ptr; using std::weak_ptr;

// the pointer part of every list is the same
// lists differ by data part
template <typename T>
class node{
public:
  node(const T& data): data_(data), next_(nullptr) {}

  // payload functions
  T    getData()       const { return data_; }
  void setData(const T& data){ data_=data;   }

  // pointer functions
  shared_ptr<node<T>> getNext() const;
  shared_ptr<node<T>> getPrev() const;
  void setNext(shared_ptr<node<T>>&);
  void setPrev(shared_ptr<node<T>>&);

  void resetNext(){ next_.reset(); }
  void resetPrev(){ prev_.reset(); }

private:
  T data_;
  shared_ptr<node<T>> next_; // ownership
  weak_ptr  <node<T>> prev_;
};

//
// member functions for node
//
template <typename T>
shared_ptr<node<T>> node<T>::getNext() const {
   return next_;
}

template <typename T>
shared_ptr<node<T>> node<T>::getPrev() const {
  return prev_.lock();
}

template<typename T>
void node<T>::setNext(shared_ptr<node<T>>& next){
   next_ = next;
}

template<typename T>
void node<T>::setPrev(shared_ptr<node<T>>& prev) {
  prev_ = prev;
}

#endif // LIST_HPP_