// using sorting algorihtms to demonstrate the Strategy Design Pattern
// Nathan Fleet
// 11/27/2023

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using std::cout; using std::endl;
using std::vector; 

typedef vector<int>::iterator It;  // shorthand for a vector iterator

// abstract strategy
// strategy interface, push method
class Sorter{
public:
   virtual void sort(It, It) const = 0;
};


// context using the strategies
class OrderedCollection{
public:
   void setSorter(Sorter *sorter) {sorter_ = sorter;}
   void setCollection(const vector<int> &v){v_ = v;}
   const vector<int>& getCollection() const{ return v_;}
   void sort() {sorter_->sort(v_.begin(), v_.end());}
private:
   vector<int> v_;
   Sorter *sorter_; 
};


// concrete strategy using bubble sort
class BubbleSorter: public Sorter {
public:
   void sort(It begin, It end) const override {
      bool swapped;
      do{
	 swapped = false;
	 for(It one=begin, two = next(one, 1); two != end; ++one, ++two)
	    if(*one > *two){
	       std::swap(*one, *two);
	       swapped=true;
	    }
      }while(swapped);
   }
};


// concrete strategy using STL sorting alg
class StdSorter: public Sorter{
public:
   void sort(It begin, It end) const override {
      std::sort(begin, end);
   }
};

// concrete strategy using insertion sort
class InsertionSorter : public Sorter {
public:
   void sort(It begin, It end) const override {
      for(It i = next(begin); i != end; ++i) {
         auto key = (*i);
         It j = prev(i);

         while(j >= begin && (*j) > key) {
            *(next(j)) = *j;
            j = prev(j);
         }
         *(next(j)) = key;
      }
   }
};

int main() {
   vector<int> v={3,55,2,103,7}, vc=v, vc2=v;

   OrderedCollection sortedVector;
   StdSorter ss;
   BubbleSorter bs;
   InsertionSorter is;

   // 
   // sorting short vectors to demo correctness
   //

   // STL sorter
   sortedVector.setSorter(&ss);
   sortedVector.setCollection(v);
   for(auto e: v) cout << e << " "; cout << endl;

   sortedVector.sort();
   v = sortedVector.getCollection();
   cout << "STL sorted" << endl; 
   for(auto e: v) cout << e << " "; cout << endl << endl;

   
   // BubbleSort sorter
   sortedVector.setSorter(&bs);
   sortedVector.setCollection(vc);
   for(auto e: vc) cout << e << " "; cout << endl;

   sortedVector.sort();
   vc = sortedVector.getCollection();
   cout << "bubble sorted" << endl; 
   for(auto e: vc) cout << e << " "; cout << endl << endl;

   // InsertionSort sorter
   sortedVector.setSorter(&is);
   sortedVector.setCollection(vc2);
   for(auto e: vc) cout << e << " "; cout << endl;

   sortedVector.sort();
   vc2 = sortedVector.getCollection();
   cout << "insertion sorted" << endl;
   for(auto e: vc) cout << e << " "; cout << endl << endl;

   // 
   // sorting large vectors to demo performance
   // 
   v.clear();
   srand(time(nullptr));

   std::generate_n(back_inserter(v), 40000, []{return rand()%100;});
   vc=v;
   vc2=v;

   std::chrono::time_point<std::chrono::high_resolution_clock>
      startTime, endTime; // chrono time points
   std::chrono::duration<double> duration; 
                          // chrono time interval

   // STL sorter
   sortedVector.setSorter(&ss);
   sortedVector.setCollection(v);

   startTime = std::chrono::high_resolution_clock::now();
   sortedVector.sort();
   endTime = std::chrono::high_resolution_clock::now();
   duration = endTime - startTime;
   v = sortedVector.getCollection();

   cout << "standard sort ran for " << duration.count() << " seconds" << endl;

   // bubble sort
   sortedVector.setSorter(&bs);
   sortedVector.setCollection(vc);
   
   startTime = std::chrono::high_resolution_clock::now();
   sortedVector.sort();
   endTime = std::chrono::high_resolution_clock::now();
   duration = endTime - startTime;
   vc = sortedVector.getCollection();

   cout << "bubble sort ran for " << duration.count() << " seconds" << endl;

   // insertion sort
   sortedVector.setSorter(&is);
   sortedVector.setCollection(vc2);
   
   startTime = std::chrono::high_resolution_clock::now();
   sortedVector.sort();
   endTime = std::chrono::high_resolution_clock::now();
   duration = endTime - startTime;
   vc2 = sortedVector.getCollection();

   cout << "insertion sort ran for " << duration.count() << " seconds" << endl;
   
   // confirming sorted vectors are the same
   if(v == vc)
      cout << "sorted vectors are the same" << endl;
   else
      cout << "sorted vectors are different" << endl;
   
}