//  String class test program
//
//  Tests: char constructor
//

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        String str('x');

        assert(str == 'x');
    }
    {
        String str('0');

        assert(str == '0');
    }
    {
        String str('X');

        assert(str == 'X');
    }
    {
        String str('&');

        assert(str == '&');
    }
    {
        String str('1');

        assert(str == '1');
    }
    {
        String str('=');

        assert(str == '=');
    }
    {
        String str('/');

        assert(str == '/');
    }
    {
        String str(' ');

        assert(str == ' ');
    }

    std::cout << "Done testing char constructor." << std::endl;

    return 0;
}
