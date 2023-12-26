// LAB: 2
// Nathan Fleet
// FILE: word.cpp
// 8/29/2023

#include "word.hpp"
#include <iostream>

//////////////////////////////////////////////////////////////////////
// CLASS: WordOccurrence
//
//

// returns true if word matches stored
bool WordOccurrence::matchWord(const std::string & word) {
    return(word_ == word);
}

// increments number of occurrences
void WordOccurrence::increment() {
    ++num_;
}

std::string WordOccurrence::getWord() const {
    return word_;
}

int WordOccurrence::getNum() const {
    return num_;
}

//////////////////////////////////////////////////////////////////////
// CLASS: WordList
//

// default constructor
WordList::WordList() {
    size_ = 0;
    wordArray_ = new WordOccurrence[size_];
}

// destructor
WordList::~WordList() {
    delete [] wordArray_;
}

// copy constructor
WordList::WordList(const WordList & actual) {
    size_ = actual.size_;
    wordArray_ = new WordOccurrence[size_];
    for(int i = 0; i < size_; ++i) {
        wordArray_[i] = actual.wordArray_[i];
    }
}

// assignment overload
WordList& WordList::operator=(const WordList & rhs) {
    // self assignment
    if(this == &rhs) {
        return *this;
    }

    // deallocate old array
    delete [] wordArray_;

    size_ = rhs.size_;
    wordArray_ = new WordOccurrence[size_];
    for(int i = 0; i < size_; ++i) {
        wordArray_[i] = rhs.wordArray_[i];
    }
    return *this;
}

void WordList::addWord(const std::string & word) {
    // check to see if there is duplicate in array
    // if duplicate exists, increment occurrences and exit function
    for(int i = 0; i < size_; ++i) {
        if(wordArray_[i].getWord() == word) {
            wordArray_[i].increment();
            return;
        }
    }

    // initialize pointer to array one word larger
    WordOccurrence *newArray = new WordOccurrence[size_ + 1];

    // otherwise copy into new array
    for (int i = 0; i < size_; ++i) {
        newArray[i] = wordArray_[i];
    }

    // add new word to end of array and initialize occurrence to 1
    newArray[size_] = WordOccurrence(word, 1);

    wordArray_ = newArray;

    // adjust size
    size_ += 1;
}

void WordList::print() {
    int i; int j; 
    WordOccurrence key;

    // insertion sort algorithm to sort in ascending order
    for(int i = 1; i < size_; ++i) {
        key = wordArray_[i];
        // one index before key
        j = i - 1;

        // while the index before the key is not 0
        // and the occurrences at j are greater than the key
        while(j >= 0 && wordArray_[j].getNum() > key.getNum()) {
            // move element one position forward
            wordArray_[j + 1] = wordArray_[j];
            // decrement j
            --j;
        }
        wordArray_[j + 1] = key;
    }

    // print the sorted array
    for(int i = 0; i < size_; ++i) {
        std::cout << wordArray_[i] << std::endl;
    }
}

//////////////////////////////////////////////////////////////////////
// FRIENDS
// 

bool equal(const WordList& lhs, const WordList& rhs) {
    // return false if not the same size
    if(lhs.size_ != rhs.size_) {
        return false;
    }

    // check each object in both lists
    for(int i = 0; i < lhs.size_; ++i) {
        if(!(lhs.wordArray_[i].getWord() == rhs.wordArray_[i].getWord() && lhs.wordArray_[i].getNum() == rhs.wordArray_[i].getNum())) {
            return false;
        }
    }

    // lists are equal
    return true;
}

// output operator overload so that i can output WordOccurrence objects to the console
std::ostream& operator<<(std::ostream& out, const WordOccurrence& word) {
    out << word.word_ << ": " << word.num_ << std::endl;
    return out;
}
