// for_each is the "operational" non-modifying algorithm

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::cout; using std::cin; using std::endl;
using std::vector; using std::string;

void populate(vector<char>& v) {
    cout << "Enter chars, '0' to quit: ";
    char item;
    while(cin >> item && item != '0') {
        v.push_back(item);
    }
}

int main() {
    vector<char> vec; populate(vec);

    string result = "";
    // executes callback for each element in the range
    std::for_each(vec.begin(), vec.end(), [&](char c){
        result += c;
        result += ", ";
    });
    cout << "You entered: " << result << endl;
}