#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

using std::cout; using std::cin; using std::endl;
using std::vector;

// QUESTION 6: MIDTERM PRACTICE
// int main() {
//     vector<int> vec;

//     srand(time(nullptr));

//     for(int i = 0; i < 10; ++i) {
//         vec.push_back(rand()%10);
//     }

//     cout << "The elements in vec are: ";
//     for(auto e : vec) { cout << e << ", "; }
//     cout << endl;

//     auto count = count_if(vec.begin(), vec.end(), 
//             [](int e){ return (e%2) == 0; });

//     cout << "There are: " << count << " even integers." << endl;

//     return 0;
// }

// QUESTION 7: MIDTERM PRACTICE
int main() {
    vector<int> c1 = {1, 2, 3, 4, 5};
    vector<int> c2 = {5, 4, 3, 2, 1};
    vector<int> c3;

    // transform expects four iterators
    // back_inserter is needed since c3 is uninitialized
    transform(c1.begin(), c1.end(), c2.begin(), back_inserter(c3),
    [](int a, int b){
        return std::max(a, b);
    });

    for(auto e : c3) {
        cout << e << ", ";
    }
    cout << endl;
}