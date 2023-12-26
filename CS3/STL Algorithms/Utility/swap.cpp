// swap algorithm

#include <algorithm>
#include <iostream>

using std::cout; using std::endl;
using std::swap;

template<typename T>
void testUtility(T x, T y) {
    cout << "x is " << x << ", y is " << y;

    // swaps x and y
    swap(x, y);

    cout << ". After swapping, x is " << x << ", y is " << y << endl;
}

int main() {
    testUtility(1, 2);
    testUtility('a', 'b');
}