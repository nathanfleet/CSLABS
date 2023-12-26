// sorting apples
// non STL-algorithm code to be replaced by algorthms
// Nathan Fleet
// 09/25/2023

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <numeric>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector; using std::deque;
using std::generate; using std::for_each; using std::count_if;
using std::find_if; using std::max_element; using std::accumulate;
using std::transform; using std::remove_if; using std::sort;

struct Apples{
   double weight; // oz
   string color;  // red or green
   void print() const { cout << color << ", " <<  weight << endl; }
};

int main(){
   srand(time(nullptr));
   const double minWeight = 3.;
   const double maxWeight = 8.;

   cout << "Input crate size: ";
   int size;
   cin >> size;

   vector <Apples> crate(size);

   // assign random weight and color to apples in the crate
   generate(crate.begin(), crate.end(), [minWeight, maxWeight](){ 
      Apples apple;
      apple.weight = static_cast<double>(rand())/RAND_MAX*(maxWeight - minWeight); 
      apple.color = rand() % 2 == 1 ? "green" : "red";
      return apple;
      });

   // for_each() possibly
   cout << "all apples"<< endl;
   for_each(crate.begin(), crate.end(), [](const Apples & apple){ apple.print(); });
   
   cout << "Enter weight to find: ";
   double toFind;
   cin >> toFind;

   // count_if()
   int cnt = count_if(crate.begin(), crate.end(), [toFind](const Apples & apple){ 
      return apple.weight > toFind;
   });

   cout << "There are " << cnt << " apples heavier than " << toFind << " oz" <<  endl;

   // find_if()
   cout << "at positions ";
   auto it = find_if(crate.begin(), crate.end(), [toFind](const Apples & apple){ return apple.weight > toFind; });
   while(it != crate.end()) {
      cout << (it - crate.begin());
      it = find_if(it + 1, crate.end(), [toFind](const Apples & apple){ return apple.weight > toFind; });
      if(it != crate.end()) cout << ", ";
   }
   cout << endl;

   // max_element()
   Apples maxApple = *max_element(crate.begin(), crate.end(), [](const Apples & leftApple, const Apples & rightApple){ 
      return leftApple.weight < rightApple.weight; 
   });
   cout << "Heaviest apple weighs: " << maxApple.weight << " oz" << endl;

   // for_each() or accumulate()
   double sum = accumulate(crate.begin(), crate.end(), 0.0, [](double partialSum, const Apples & apple) {
      return apple.weight;
   });
   cout << "Total apple weight is: " << sum << " oz" << endl;

   
   cout << "How much should they grow: ";
   double toGrow;
   cin >> toGrow;

   // transform();
   transform(crate.begin(), crate.end(), crate.begin(), [toGrow] (Apples & apple){ 
      apple.weight += toGrow; 
      return apple;
   });

   cout << "Input minimum acceptable weight: ";
   double minAccept;
   cin >> minAccept;

   // remove_if()
   auto end = remove_if(crate.begin(), crate.end(), [minAccept](const Apples& apple){ return apple.weight < minAccept; });
   crate.erase(end, crate.end());
   cout << "removed " << size - crate.size() << " elements" << endl;

   // bubble sort, replace with sort()
   sort(crate.begin(), crate.end(), [](const Apples & leftApple, const Apples & rightApple){ 
      return leftApple.weight < rightApple.weight;
   });

   // for_each() possibly
   cout << "sorted remaining apples"<< endl;
   for_each(crate.begin(), crate.end(), [](const Apples & apple){ apple.print(); });
}
