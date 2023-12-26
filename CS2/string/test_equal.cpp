//  String class test program
//
//  Tests: equal
//

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        String lhs("abc");
        String rhs("abc");

        assert(lhs == rhs);
    }
    {
        String lhs(" ");
        String rhs(" ");

        assert(lhs == rhs);
    }
    {
        String lhs;
        String rhs;

        assert(lhs == rhs);
    }
    {
        String lhs('a');
        String rhs('a');

        assert(lhs == rhs);
    }
    {
        String lhs(' ');
        String rhs(' ');

        assert(lhs == rhs);
    }
    {
        String lhs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        String rhs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");

        assert(lhs == rhs);
    }
    {
        String lhs(".--.abc");
        String rhs(".--.abc");

        assert(lhs == rhs);
    }
    {
        String lhs("00000");
        String rhs("00000");

        assert(lhs == rhs);
    }

    std::cout << "Done testing equal." << std::endl;

    return 0;
}
