// arithmetic/geometric mean using function pointers and lambads
// Mikhail Nesterenko, adopted from Prof. C++
// 3/29/2014

#include <numeric>
#include <vector>
#include <cmath>
#include <iostream>

using std::cout; using std::cin; 
using std::endl;
using std::vector;

// function to use as function pointer in accumulate()
int product(int num1, int num2){
   return num1 * num2;
}

int main() {
   vector<int> vect;

   cout << "Enter numbers (0 to stop): ";
   int num;
   while (cin >> num && num != 0)
      vect.push_back(num);


//    double sum = accumulate(vect.begin(), vect.end(), 0);
//    cout << sum/vect.size() << endl;

   cout << "The geometric mean is: "; 
   double mult = accumulate(vect.begin(), vect.end(), 1, product);
   cout << pow(abs(mult), 1.0/vect.size()) << endl;

//    cout << "The geometric mean (Lambda version) is: ";
//    double multLambda = 
//     accumulate(vect.begin(), vect.end(), 1,
// 	       [](int num1, int num2) { return num1 * num2; }
// 	       );
//    cout <<  pow(abs(multLambda), 1.0 / vect.size()) << endl;   
}