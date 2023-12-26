//  Stack class test program
//
//  Tests: copy constructor
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main()
{
    //integer tests
    {
        stack<int> lhs;
        lhs.push(12);
        stack<int> rhs(lhs);
        assert(rhs.pop() == 12);
        assert(rhs.empty());
    }
    {
        stack<int> lhs;
        lhs.push(12);
        lhs.push(13);
        lhs.push(14);
        lhs.push(15);
        stack<int> rhs(lhs);
        assert(rhs.top() == 15);
    }
    {
        stack<int> lhs;
        lhs.push(12);
        lhs.pop();
        lhs.push(13);
        lhs.pop();
        lhs.push(14);
        stack<int> rhs(lhs);
        assert(rhs.top() == 14);
    }
    //double tests
    {
        stack<double> lhs;
        lhs.push(12);
        stack<double> rhs(lhs);
        assert(rhs.top() == 12);
    }
    {
        stack<double> lhs;
        lhs.push(12);
        lhs.push(13);
        lhs.push(14);
        lhs.push(15);
        stack<double> rhs(lhs);
        assert(rhs.pop() == 15);
        assert(rhs.top() == 14);
    }
    {
        stack<double> lhs;
        lhs.push(12);
        lhs.pop();
        lhs.push(13);
        lhs.pop();
        lhs.push(14);
        stack<double> rhs(lhs);
        assert(rhs.top() == 14);
    }
    //char tests
    {
        stack<char> lhs;
        lhs.push(12);
        stack<char> rhs(lhs);
        assert(rhs.top() == 12);
    }
    {
        stack<char> lhs;
        lhs.push(12);
        lhs.push(13);
        lhs.push(14);
        lhs.push(15);
        stack<char> rhs(lhs);
        assert(rhs.pop() == 15);
        assert(rhs.top() == 14);
    }
    {
        stack<char> lhs;
        lhs.push(12);
        lhs.pop();
        lhs.push(13);
        lhs.pop();
        lhs.push(14);
        stack<char> rhs(lhs);
        assert(rhs.top() == 14);
    }

    std::cout << "Done testing copy constructor." << std::endl;
    return 0;
}
