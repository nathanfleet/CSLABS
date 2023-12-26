// LAB: 2
// Nathan Fleet
// FILE: word.hpp
// 8/29/2023

#ifndef WORD_HPP_
#define WORD_HPP_

#include <string>

class WordOccurrence {
public:
    WordOccurrence(const std::string& word="", int num=0) {word_ = word; num_ = num; };
    bool matchWord(const std::string &);    // returns true if word matches stored
    void increment();                       // increments number of occurrences

    // overloaded to make print() easier
    friend std::ostream& operator<<(std::ostream&, const WordOccurrence&);

    // accessors
    std::string getWord() const; 
    int getNum() const;

private:
    std::string word_;
    int num_;
};

class WordList{
public:
    WordList();                       // default constructor
    ~WordList();                      // destructor
    WordList(const WordList& actual); // copy constructor


    // implement comparison as friend
    friend bool equal(const WordList&, const WordList&);
    
    // overloaded assignment
    WordList& operator=(const WordList&);

    void addWord(const std::string &);
    void print();
private:
    WordOccurrence *wordArray_; // a dynamically allocated array of WordOccurrences
                                // may or may not be sorted
    int size_;
};

#endif