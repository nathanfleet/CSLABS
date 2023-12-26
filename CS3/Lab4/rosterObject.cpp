// Nathan Fleet ... (original file from: Mikhail Nesterenko)
// LAB 4 : Roster With Class Schedule
// 9/13/23
// FILE : rosterObject.cpp

#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include <algorithm>

using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move;


class Student{
public:
   Student(string firstName, string lastName): 
      firstName_(firstName), lastName_(lastName) {}
 
   // move constructor, not really needed, generated automatically
   Student(Student && org) noexcept:
      firstName_(move(org.firstName_)),
      lastName_(move(org.lastName_)),
      courses_(move(org.courses_))
   {}
  
   // force generation of default copy constructor
   Student(const Student & org) = default;
   
   string print() const {
      string name = firstName_ + ' ' + lastName_ + ": ";

      auto it = courses_.begin();

      while(it != courses_.end()) {
         name += *it + "   ";
         ++it;
      }

      return name;
      
   }

   // added function to add course to course list
   void addCourse(const string & course) { courses_.push_back(course); };

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
   list<string> courses_;
};

// reading a list from a fileName
void readRoster(list<Student>& roster, string fileName);  
// printing a list out
void printRoster(const list<Student>& roster); 

int main(int argc, char* argv[]){

   if (argc <= 1){ cout << "usage: " << argv[0] 
      << " list of courses, dropouts last" << endl; exit(1);}

   // list of courses of students; 
   list<Student> courseStudents;

   for(int i=1; i < argc-1; ++i){
      readRoster(courseStudents, argv[i]);  
   }

   cout << "All students" << endl;
   cout << "first name last name: courses enrolled" << endl;
   printRoster(courseStudents); 

   cout << endl << endl;

   // read dropout list and remove them from master list
   list<Student> dropouts; 
   readRoster(dropouts, argv[argc-1]);

   for(auto& dropout : dropouts) {
      auto it = std::find(courseStudents.begin(), courseStudents.end(), dropout);
      if(it != courseStudents.end()) {
         it = courseStudents.erase(it);
      }
   }

   courseStudents.sort();

   cout << endl << endl << "All students, dropouts removed and sorted" << endl;
   cout << "first name last name: courses enrolled" << endl;

   printRoster(courseStudents);

}

void readRoster(list<Student>& roster, string fileName){
   ifstream course(fileName);

   // get course name from file name
   string courseName = fileName.substr(0, fileName.length() - 4);
   string first, last;
   while(course >> first >> last) {
      Student student = Student(first, last);

      // try to find student in master list
      auto it = std::find(roster.begin(), roster.end(), student);

      // if iterator is at the end the student does not exist in the list
      if(it != roster.end()) { 
         // add course to list
         it->addCourse(courseName);
      } else {
         // otherwise; student does exist so add them
         student.addCourse(courseName);
         roster.push_back(student);
         ++it;
      }
   }
   course.close();
}

// printing a list out
void printRoster(const list<Student>& roster){
   for(const auto& student : roster)
      cout << student.print() << endl;
}