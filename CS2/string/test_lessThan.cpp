//  String class test program
//
//  Tests: less than
//

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        String lhs("a");
        String rhs("b");

        assert(lhs < rhs);
    }
    {
        String lhs("aaa");
        String rhs("aaaa");

        assert(lhs < rhs);
    }
    {
        String lhs("abc");
        String rhs("abcd");

        assert(lhs < rhs);
    }
    {
        String lhs('y');
        String rhs('z');

        assert(lhs < rhs);
    }
    {
        String lhs("abcx");
        String rhs("abcy");

        assert(lhs < rhs);
    }
    {
        String lhs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        String rhs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");

        assert(lhs < rhs);
    }
    {
        String lhs(" ");
        String rhs("  ");

        assert(lhs < rhs);
    }
    {
        String lhs('1');
        String rhs('2');

        assert(lhs < rhs);
    }

    std::cout << "Done testing less than." << std::endl;

    return 0;
}
