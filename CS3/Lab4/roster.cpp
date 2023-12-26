// Nathan Fleet ... (original file from: Mikhail Nesterenko)
// LAB 4 : Roster With Class Schedule
// 9/13/23
// FILE : roster.cpp

#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <cstdlib>

using std::ifstream;
using std::string; using std::getline;
using std::list;
using std::cout; using std::endl;

// reading a list from a fileName
void readRoster(list<string>& roster, string fileName);  

// printing a list out
void printRoster(const list<string>& roster); 

// printing (master) list of lists
void printMaster(const list<list<string>>& outerList);

int main(int argc, char* argv[]){

   if (argc <= 1){ 
      cout << "usage: " << argv[0] 
      << " list of courses, dropouts last" 
      << endl;
      exit(1);
   }

   // master list of all students with courses
   list<list<string>> studentEntries; 

   // for each text file (course)
   for(int i=1; i < argc-1; ++i){
      list<string> roster;

      // store file name
      string fileName = argv[i];
      string course = fileName.substr(0, fileName.length() - 4);

      // read the roster
      readRoster(roster, argv[i]);

      // for every student in the roster
      for(auto& student : roster) {
         bool existingStudent = false;
         // for every entry in student entries list
         for(auto& entry : studentEntries) {
            // if student exists in list already
            if(student == entry.front()) {
               // append new course to end
               entry.push_back(course);
               existingStudent = true;
               break;
            }
         }
         // if the student does not already exist in the list
         if(!existingStudent) {
            // make a new list
            list<string> newEntry;
            // add student name and the course to the list
            newEntry.push_back(student);
            newEntry.push_back(course);

            // add that list to the master list
            studentEntries.push_back(newEntry);
         }
      }

   }

   cout << "All students" << endl;
   cout << "first name last name: courses enrolled" << endl;

   printMaster(studentEntries);

   cout << endl << endl << "All students, dropouts removed and sorted" << endl;
   cout << "first name last name: courses enrolled" << endl;

   // reading in dropouts
   list<string> dropouts; 
   readRoster(dropouts, argv[argc-1]); 

   // iterating through the dropouts list
   for (auto dropoutIT = dropouts.begin(); dropoutIT != dropouts.end(); ++dropoutIT) {
      auto entryIT = studentEntries.begin();

      // while not at the end of master list
      while (entryIT != studentEntries.end()) {
         // if dropout exists in master list, remove them
         if (*dropoutIT == entryIT->front()) {
            // remove inner list associated with dropout
            entryIT = studentEntries.erase(entryIT);
         } else {
            ++entryIT;
         }
      }
   }

   // sort and print list with dropouts removed
   studentEntries.sort();
   printMaster(studentEntries);
   
}

// reading in a file of names into a list of strings
void readRoster(list<string>& roster, string fileName){
   ifstream course(fileName);
   string first, last;
   while(course >> first >> last)
      roster.push_back(first + ' ' + last);
   course.close();
}

// printing a list out
void printRoster(const list<string>& roster){
   for(const auto& str : roster)
      cout << str << endl;
}

// printing out master list
void printMaster(const list<list<string>>& outerList) {
   // for every inner list in the outer list
   for(const auto& innerList : outerList) {
      auto IT = innerList.begin();
      // print the student's name first
      cout << *IT << ": ";
      // then print the courses they are enrolled separated by tab
      if(IT != innerList.end()) {
         for(++IT; IT != innerList.end(); ++IT) {
            cout << *IT << "   ";
         }
      }
      cout << endl;
   }
}
