//  String class test program
//
//  Tests: char array constructor
//

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        String str("nathan");

        assert(str == "nathan");
    }
    {
        String str("NATHAN");

        assert(str == "NATHAN");
    }
    {
        String str("nAthAn");

        assert(str == "nAthAn");
    }
    {
        String str("  ");

        assert(str == "  ");
    }
    {
        String str("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");

        assert(str == "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    }
    {
        String str(" ");

        assert(str == " ");
    }
    {
        String str("_test_");

        assert(str == "_test_");
    }
    {
        String str("&&&&&");

        assert(str == "&&&&&");
    }

    std::cout << "Done testing char array constructor." << std::endl;

    return 0;
}
