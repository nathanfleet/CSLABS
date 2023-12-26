// search algorithms

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>

using std::cout; using std::endl;
using std::vector;

int main() {
    srand(time(nullptr));

    vector<int> vec(10);
    // fill the vecor with random numbers 0-9
    // in other words, fills the container (generates)
    // in range with values returned by callback
    generate(vec.begin(), vec.end(), []{return rand()%10; });

    auto begin = vec.cbegin();
    auto end = vec.cend();

    cout << "Generated sequence: " << endl;
    for(auto e : vec) { cout << e << ' '; };
    cout << endl;

    // returns iterator to minimum element in given range
    auto it = min_element(begin, end);
    cout << "minimum element is: " << *it << " at position " << it - begin << endl;

    // returns iterator to maximum element in given range
    it = max_element(begin, end);
    cout << "maximum element is: " << *it << " at position " << it - begin << endl;

    // finds the first pair of matching consecutive elements
    it = adjacent_find(begin, end);
    if(it != end) {
        cout << "Found two consecutive equal elements with value: " 
             << *it << endl;
        cout << "at position: " << it - begin << endl;
    } else {
        cout << "no two consequtive equal elements found" << endl;
    }

    vector<int> targets;
    targets.push_back(1);
    targets.push_back(2);

    // returns an iterator to the first occurrence of any element from
    // the second sequence in the first sequence
    // if none, returns iterator [last1]
    it = find_first_of(begin, end, targets.cbegin(), targets.cend());

    if(it != end) {
        cout << "Found one of 1 or 2: " << *it
             << " at poition: " << it - begin << endl;
    } else {
        cout << "Unable to find subsequence {1,2}" << endl;
    }

    // find the first subsequence of two consequetive 1s
    // search for a sequence of consequtive identical elements in a given range
    // [first, last] [count] [value]
    it = search_n(begin, end, 2, 1);
    if(it != end) {
        cout << "Found two consecutive ones" << "at position: "
             << it - begin << endl;
    } else {
        cout << "Unable to find two consecutive ones" << endl;
    }

}