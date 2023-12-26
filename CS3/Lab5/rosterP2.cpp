// set of student names who are enrolled in at least one course
// Nathan Fleet
// 9/18/2023

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include <set>

using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move; using std::set;

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

// reading a set from a fileName
void readRoster(set<Student>& roster, string fileName);  
// printing a set out
void printRoster(const set<Student>& roster); 

int main(int argc, char* argv[]){

   if (argc <= 1){ cout << "usage: " << argv[0] 
      << " list of courses, dropouts last" << endl; exit(1);}

   // set of students enrolled in at least one course
   set<Student> studentNames;

   for(int i=1; i < argc-1; ++i){
      readRoster(studentNames, argv[i]);  
   }

   // reading in dropouts
   set<Student> dropouts; 
   readRoster(dropouts, argv[argc-1]); 

   // reading dropout list and comparing to names in the master set
   for(auto& dropout : dropouts) {
    auto it = studentNames.find(dropout);
    // if dropout is found, remove them from the set
    if(it != studentNames.end()) {
        it = studentNames.erase(it);
    }
   }

   cout << "Currently Enrolled Students" << endl;
   printRoster(studentNames);

}

void readRoster(set<Student>& roster, string fileName){
   ifstream course(fileName);
   string first, last;

   while(course >> first >>  last) {
    Student student = Student(first, last);
    // insert every student into the list since std::set does not store duplicates
    roster.insert(student);
   }
   course.close();
}

// printing a set out
void printRoster(const set<Student>& roster){
   for(const auto& student : roster)
      cout << student.print() << endl;
}