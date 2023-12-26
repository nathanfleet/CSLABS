//  Stack class test program
//
//  Tests: push pop
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main()
{
    //integer tests
    {
        stack<int> rhs;

        rhs.push(12);

        assert(rhs.top() == 12);
    }
    {
        stack<int> rhs;

        rhs.push(12);
        rhs.push(13);
        rhs.push(14);

        assert(rhs.top() == 14);
    }
    {
        stack<int> rhs;

        rhs.push(12);
        rhs.push(13);
        rhs.push(14);       
        rhs.push(15);
        rhs.push(16);
        rhs.push(17);

        assert(rhs.top() == 17);
    }
    {
        stack<int> rhs;

        rhs.push(11);
        rhs.push(12);
        rhs.pop();

        assert(rhs.top() == 11);
    }
    {
        stack<int> rhs;

        rhs.push(11);
        rhs.push(12);
        rhs.push(13);
        rhs.push(14);
        rhs.pop();

        assert(rhs.top() == 13);
    }
    {
        stack<int> rhs;

        rhs.push(11);
        rhs.pop();
        rhs.push(12);
        rhs.pop();
        rhs.push(13);
        rhs.pop();
        rhs.push(14);

        assert(rhs.top() == 14);
    }
    //double tests
    {
        stack<double> rhs;

        rhs.push(12);

        assert(rhs.top() == 12);
    }
    {
        stack<double> rhs;

        rhs.push(12);
        rhs.push(13);
        rhs.push(14);

        assert(rhs.top() == 14);
    }
    {
        stack<double> rhs;

        rhs.push(12);
        rhs.push(13);
        rhs.push(14);
        rhs.push(15);
        rhs.push(16);
        rhs.push(17);

        assert(rhs.top() == 17);
    }
    {
        stack<double> rhs;

        rhs.push(11);
        rhs.push(12);
        rhs.pop();

        assert(rhs.top() == 11);
    }
    {
        stack<double> rhs;

        rhs.push(11);
        rhs.push(12);
        rhs.push(13);
        rhs.push(14);
        rhs.pop();

        assert(rhs.top() == 13);
    }
    {
        stack<double> rhs;

        rhs.push(11);
        rhs.pop();
        rhs.push(12);
        rhs.pop();
        rhs.push(13);
        rhs.pop();
        rhs.push(14);

        assert(rhs.top() == 14);
    }

    std::cout << "Done testing push pop." << std::endl;
    return 0;
}