//  Stack class test program
//
//  Tests: default constructor
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main()
{
    {
        stack<int> rhs;

        assert(rhs.empty());
    }
    {
        stack<double> rhs;

        assert(rhs.empty());
    }
    {
        stack<float> rhs;

        assert(rhs.empty());
    }
    {
        stack<char> rhs;

        assert(rhs.empty());
    }

    std::cout << "Done testing default constructor." << std::endl;
    return 0;
}
