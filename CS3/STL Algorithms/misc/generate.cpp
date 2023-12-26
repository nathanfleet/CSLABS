#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <ctime>

using std::list; using std::vector; using std::cout;
using std::endl;

int main() {
    list<int> lst(10);
    srand(time(nullptr)); // generate different rand seed
    
    // using generate() algorithm to fill lst
    // values are generated from provided range (begin and end)
    // each value generated is a random number
    generate(lst.begin(), lst.end(), []{return rand()%10;});
    for(auto& e : lst) {
        cout << e << " ";
    }

    cout << endl;

    return 0;
}