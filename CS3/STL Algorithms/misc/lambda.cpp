#include <iostream>
#include <algorithm>

using std::cout; using std::endl;

int main() {
    auto f = []{ cout << "Hello, world!" << endl; };

    f();
    f();

    // Here, the parenthesis '()' force the execution
    []{ cout << "Hello, world!" << endl; }();

    return 0;
}