// demonstrates move, C++11
// Mikhail Nesterenko
// 04/01/2014

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using std::cout; using std::endl;
using std::vector; using std::string;

int main() {
   vector<string> v={"one", "two", "three", "four", "five"}, w;
   w.resize(v.size());

   // two input iterators
   // one output iterator
   // moves contents from one range to another, with move semantics
   move(v.begin(), v.end(), w.begin());

   cout << "Contents of source vector: ";
   for(const auto &s: v) cout << s << ","; cout << endl;

   cout << "Contents of target vector: ";
   for(const auto &s: w) cout << s << ","; cout << endl;

   

   vector<string> u;
   // move with move-assignment
   u = move(w);
   cout << "Contents u after move-assignment: ";
   for(const auto &s: u) cout << s << ","; cout << endl;

   cout << "Contents w after move-assignment: ";
   for(const auto &s: w) cout << s << ","; cout << endl;




}