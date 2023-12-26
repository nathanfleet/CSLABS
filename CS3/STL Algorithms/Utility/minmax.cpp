// minmax algorithm

#include <algorithm>
#include <iostream>

using std::cout; using std::endl;
using std::minmax;

template<typename T>
void testUtility(T x, T y) {
    cout << "x is " << x << ", y is " << y;

    // returns pair where first is minimum value
    // and second is maximum value
    auto pair = minmax(x, y);

    cout << ", minmax is " << pair.first << ", "
         << pair.second << endl;


}

int main() {
    testUtility(1, 2);
    testUtility('b', 'a');
}