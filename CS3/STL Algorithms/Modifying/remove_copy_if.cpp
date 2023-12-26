// remove_copy_if operation
// Mikhail Nesterenko
// 3/1/2023

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using std::cout; using std::endl;
using std::vector; using std::string;

int main() {
   vector<string> v = {"one", "two", "three", "four", "five", "six"}, w;
   w.resize(v.size());

   //copies elements for which callback returns false
   w.erase(
       // [input range] [input range] [output range] [predicate]
	   remove_copy_if(v.begin(), v.end(), 
			  w.begin(), [](const string& s) {return s > "four";}),
   w.end());

   cout << "Contents of v: ";
   for(auto &s: v) cout << s << ", "; cout << endl;

   cout << "Contents of w: ";
   for(auto &s: w) cout << s << ", "; cout << endl;
}
