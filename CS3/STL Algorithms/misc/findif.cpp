#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using std::cout; using std::endl; using std::cin;
using std::vector; using std::list; 

int main(){
    vector<int> vec = {1, 2, 3, 4, 5};
    list<int> lst = {1, 2, 3, 4, 5};

    auto it = find_if(vec.begin(), vec.end(), [](const auto & e){
        return e > 2;
    });

    if(it != vec.end()) {
        cout << "Elements greater than 2 found at position(s): " << endl;
        cout << it - vec.begin() << ":   " << *it << endl;

        // do{
        //     cout << it - vec.begin() << " ";
        //     it = find_if(vec.begin(), vec.end(), [](const auto & e){
        //         return e > 2;
        //     });
        // } while(it != vec.end());
    } else { // no elements match callback condition
        cout << "no elements found" << endl;
    }
}