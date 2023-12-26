//  String class test program
//
//  Tests: defualt constructor
//

#include "string.hpp"
#include <cassert>
#include <iostream>

int main() { 
    {
        String str;

        assert(!(str.length() > 0));
    }

    std::cout << "Done testing default constructor." << std::endl;
    
    return 0;
}
