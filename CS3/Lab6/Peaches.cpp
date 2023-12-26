// jamming peaches
// non STL-algorithm code to be replaced by algorthms
// Nathan Fleet
// 9/26/2023

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <functional>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::vector; using std::deque;
using std::generate; using std::for_each; using std::remove_copy_if;
using std::distance; using std::advance; using namespace std::placeholders;

struct Peaches{
   double weight; // oz
   bool ripe;  // ripe or not
   void print() const { cout << (ripe?"ripe":"green") << ", " <<  weight << endl; }
};



int main(){
   srand(time(nullptr));
   const double minWeight = 3.;
   const double maxWeight = 8.;

   cout << "Input basket size: ";
   int size;
   cin >> size;

   vector <Peaches> basket(size);

   // assign random weight and ripeness peaches in the basket
   generate(basket.begin(), basket.end(), [=](){ 
      Peaches peach;
      peach.weight = minWeight + static_cast<double>(rand())/RAND_MAX*(maxWeight - minWeight);
      peach.ripe = rand() % 2;
      return peach;
   });
   
   // for_each() possibly
   cout << "all peaches"<< endl;
   for_each(basket.begin(), basket.end(), [](const Peaches & peach){ peach.print(); });

   // moving all the ripe peaches from basket to peck
   // remove_copy_if() with back_inserter()/front_inserter() or equivalents
   deque<Peaches> peck;
   remove_copy_if(basket.begin(), basket.end(), std::back_inserter(peck), [](Peaches & peach){ return !peach.ripe; });

   // for_each() possibly
   cout << endl << "peaches remaining in the basket"<< endl;
   for_each(basket.begin(), basket.end(), [](const Peaches & peach){ peach.print(); });

   cout << endl;

   // for_each() possibly
   cout << "peaches moved to the peck"<< endl;
   for_each(peck.begin(), peck.end(), [](const Peaches & peach){ peach.print(); });


   // prints every "space" peach in the peck
   const int space=3; 
   cout << "\nevery " << space << "\'d peach in the peck"<< endl;

   // replace with advance()/next()/distance()
   // no explicit iterator arithmetic
   auto it = peck.cbegin();  
   while(it != peck.cend()){
      if(distance(it, peck.cend()) >= space) {
         advance(it, space - 1);
         it -> print();
         advance(it, 1);
      } else {
         break;
      }
   }

   // putting all small ripe peaches in a jam
   // use a binder to create a functor with configurable max weight
   // accumulate() or count_if() then remove_if()
   const double weightToJam = 10.0;
   double jamWeight = 0;
   auto isJammable = bind(std::greater<double>(), weightToJam, _1);
   count_if(peck.begin(), peck.end(), [&](Peaches peach){
      bool compared = isJammable(peach.weight);
      if(compared) jamWeight += peach.weight;
      return compared;
   });

   peck.erase(remove_if(peck.begin(), peck.end(), [&](Peaches & peach){ return isJammable(peach.weight); }));

   cout << "Weight of jam is: " << jamWeight << endl;

}