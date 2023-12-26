// MAP of students and courses
// Nathan Fleet
// 9/18/2023

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include <map>

using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move; using std::map;

class Student{
public:
   Student(string firstName, string lastName): 
      firstName_(firstName), lastName_(lastName) {}
 
   // move constructor, not really needed, generated automatically
   Student(Student && org) noexcept:
      firstName_(move(org.firstName_)),
      lastName_(move(org.lastName_))
   {}
  
   // force generation of default copy constructor
   Student(const Student & org) = default;
   
  string print() const {return firstName_ + ' ' + lastName_;}

    // needed for unique() and for remove()
   friend bool operator== (Student left, Student right){
      return left.lastName_ == right.lastName_ &&
	     left.firstName_ == right.firstName_;
   }

   // needed for sort()
   friend bool operator< (Student left, Student right){
      return left.lastName_ < right.lastName_ ||
	     (left.lastName_ == right.lastName_ && 
	      left.firstName_ < right.firstName_);
   }
private:
   string firstName_;
   string lastName_;
};

// reading a map from a fileName
void readRoster(map<Student, list<string>>& roster, string fileName);  
// printing a map out
void printRoster(const map<Student, list<string>>& roster); 

int main(int argc, char* argv[]){

   if (argc <= 1){ cout << "usage: " << argv[0] 
      << " list of courses, dropouts last" << endl; exit(1);}
      
   // map of all studnets
   map<Student, list<string>> courseStudents;

   // read in student's name and enrolled course for each file
   for(int i=1; i < argc-1; ++i){
      readRoster(courseStudents, argv[i]);   
   }

   cout << "All students" << endl;
   cout << "first name last name: courses enrolled" << endl;
   printRoster(courseStudents);

   // reading in dropouts
   map<Student, list<string>> dropouts; 
   readRoster(dropouts, argv[argc-1]); 

   // if the dropout exists in the master map, remove them
   for(auto& dropout : dropouts) {
      auto it = courseStudents.find(dropout.first);
      if(it != courseStudents.end()) {
         courseStudents.erase(it);
      }
   }

   cout << endl << endl << "All students, dropouts removed and sorted" << endl;
   cout << "first name last name: courses enrolled" << endl;
   printRoster(courseStudents);
}

void readRoster(map<Student, list<string>>& roster, string fileName){
   ifstream course(fileName);

   // get course name from file name
   string courseName = fileName.substr(0, fileName.length() - 4);
   string first, last;
   while(course >> first >> last) {
    Student student = Student(first, last);

    auto it = roster.find(student);

    // if name already exists in the map
    if(it != roster.end()) {
        // add course to list
        // second to access list (first = key, second = value)
        it->second.push_back(courseName);
    } else {
        // add new map element since student doesn't exist
        list<string> newStudentList;
        newStudentList.push_back(courseName);
        // insert new pair into roster
        roster.insert({student, newStudentList});
        ++it;
    }
   }
   course.close();
}

// printing a map out
void printRoster(const map<Student, list<string>>& roster){
    for(const auto& student : roster) {
        cout << student.first.print() << ":";
        auto it = student.second.begin();
        while(it != student.second.end()) {
            cout << "   " << *it;
            ++it;
        }
        cout << endl;
    }
}