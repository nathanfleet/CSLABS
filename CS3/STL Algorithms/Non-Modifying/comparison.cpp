#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using std::cout; using std::cin; using std::endl;
using std::vector; using std::list;

template<typename Container>
void populate(Container cont) {
    cout << "Enter chars, '0' to quit: ";
    char item;
    while(cin >> item && item != '0') {
        cont.push_back(item);
    }
}

int main() {
    vector<char> vec;
    list<char> lst;

    cout << "Populate the vector..." << endl;
    populate(vec);

    cout << "Populate the list..." << endl;
    populate(lst);

    if(vec.size() < lst.size()) {
        std::cerr << "vector is not long enough" << endl;
        exit(1);
    }

    // checks the first range against the second range
    // if any element in the first range does not match an
    // element in the second range, returns false
    // otherwise, returns true
    if(equal(vec.begin(), vec.end(), lst.begin())) {
        cout << "The two containers are equal!" << endl;
    } else {
        // use mismatch
        cout << "The containers are not equal" << endl;
        // returns a pair of iterators
        // first iterator points to the position in the first sequence
        // second iterator points to the corresponding position in the second sequence
        // if identical, iterators point to end
        auto miss = std::mismatch(vec.begin(), vec.end(), lst.begin());
        cout << "The first  mismatched elements: "
             << *(miss.first) << " and " << *(miss.second) << endl;
    }

    // takes two ranges (four iterators) and compares the elements lexicographically
    // true if the first range is lexicographically less than the second
    // otherwise false
    if(std::lexicographical_compare(vec.begin(), vec.end(), lst.begin(), lst.end())) {
        cout << "vector comes first lexicographically" << endl;
    } else {
        cout << "list comes first lexicographically" << endl;
    }

    return 0;
}