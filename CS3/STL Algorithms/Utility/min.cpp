// min algorithm

#include <algorithm>
#include <iostream>

using std::cout; using std::endl;
using std::min;

template<typename T>
void testUtility(T x, T y) {
    cout << "x is " << x << ", y is " << y;
    cout << ", min is " << min(x, y) << endl;
}

int main() {
    testUtility(1, 2);
    testUtility('a', 'b');
}