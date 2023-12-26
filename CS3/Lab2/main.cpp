// LAB: 2
// Nathan Fleet
// FILE: main.cpp
// 8/29/2023

#include <iostream>
#include <string>
#include <fstream>
#include "word.hpp"

using std::cout; using std::endl;

int main(int argc, char * argv[]) {
   // argument checking
   if(argc != 2) {
      std::cerr << "Invalid arguments.";
      return -1;
   }

   std::ifstream file(argv[1]);

   // check if open
   if(!file.is_open()) {
      std::cerr << "Error opening file";
      return -1;
   }

   WordList wordList;
   std::string line;
   std::string tempWord;

   // whiele there are still lines in the file
   while(std::getline(file, line)) {
      for(int i = 0; i < line.length(); ++i) {
         // get each character in the line one by one
         char c = line[i];

         // check if character is outside of alphanumeric ASCII bounds
         if(!((c < 'a' || c > 'z') && (c < 'A' || c > 'Z') && (c < '0' || c > '9'))) {
            // add character to word if valid
            tempWord += c;

            // otherwise add word to list and reset temp
         } else if(tempWord.length() > 0) {
            wordList.addWord(tempWord);
            tempWord = "";
         }
      }

      // handle last word in line in case not followed by whitespace/punctuation
      if(!(tempWord.length() == 0)) {
         wordList.addWord(tempWord);
         tempWord = "";
      }
   }

   // print word list after file is read
   wordList.print();

   return 0;
}