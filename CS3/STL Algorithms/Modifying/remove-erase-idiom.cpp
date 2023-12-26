// demonstrates remove in remove-erase idiom
// Mikhail Nesterenko
// 04/01/2014

#include <algorithm>
#include <iostream>
#include <vector>
#include <ctime>
#include <functional>

using std::cout; using std::endl;
using std::vector;
using namespace std::placeholders;

int main() {
   vector<int> v(10);

   srand(static_cast<unsigned>(time(nullptr)));
   generate(v.begin(), v.end(), []{return rand()%10;});

   cout << "v contents: "; 
   for(auto e: v) cout << e << " "; cout << endl;
    
   auto toRemove=remove(v.begin(), v.end(), 8);

   cout << "v contents after remove: "; 
   for(auto e: v) cout << e << ' ';
   cout << endl;

   v.erase(toRemove, v.end());

   
   v.erase(remove(v.begin(),v.end(),9), v.end()); 

   
   cout << "v contents after erase: "; 
   for(auto e: v) cout << e << ' ';
   cout << endl;

  
   v.erase(remove_if(v.begin(), v.end(),
		     std::bind(std::less_equal<>(), _1, 3)), 
	   v.end());

   cout << "v contents after remove_if: "; 
   for(auto e: v) cout << e << " "; cout << endl;

//    // use remove to  shift desired elements
//    auto toRemove = remove(v.begin(), v.end(), 8);
//    // use erase to remove undesired
//    v.erase(toRemove, v.end());
  
}