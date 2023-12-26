#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>

using std::cout; using std::endl; using std::cin;
using std::vector; using std::list; 

int main(){
   vector<int> vec = {1, 2, 3, 4, 5};
   
   auto it = find(vec.begin(), vec.end(), 9);

   if(it != vec.end()) {
    cout << "Element was found" << endl;
    return 0;
   }

   std::cerr << "Element was NOT found" << endl;
   return -1;

}