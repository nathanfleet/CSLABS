// selecting oranges
// converting vectors to multimaps
// Nathan Fleet
// 9/25/2023

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <map> // for multimap

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector;
using std::multimap;

enum class Variety {orange, pear, apple};
vector<string> colors = {"red", "green", "yellow"};

int main(){
   srand(time(nullptr));
   multimap<Variety, string> tree;

   // random fruit and color selection
   for(int i = 0; i < (rand() % 100 + 1); ++i) {
      Variety variety = static_cast<Variety>(rand() % 3);
      string color = colors[rand()%3];
      tree.emplace(variety, color);
   }

   // printing colors of oranges
   cout << "Colors of the oranges: ";
   auto begin = tree.lower_bound(Variety::orange);
   auto end   = tree.upper_bound(Variety::orange);

   // displaying the colors of the oranges
   while(begin != tree.end()) {
      cout << begin->second;
      ++begin;
      if(begin != tree.end()) cout << ", ";
   }

   cout << endl;
}
