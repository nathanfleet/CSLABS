//  String class test program
//
//  Tests: copy constructor
//

#include "string.hpp"
#include <cassert>
#include <iostream> 

int main()
{
    {//charArray test
        String lhs("test");
        String rhs(lhs);

        assert(lhs == "test");
        assert(rhs == "test");
        assert(lhs == rhs);
    }
    {//single char test
        String lhs(' ');
        String rhs(lhs);

        assert(lhs == ' ');
        assert(rhs == ' ');
        assert(lhs == rhs);
    }
    {
        String lhs("Testing copy with a larger string.");
        String rhs(lhs);

        assert(lhs == "Testing copy with a larger string.");
        assert(rhs == "Testing copy with a larger string.");
        assert(lhs == rhs);
    }
    {//max capacity copy
        String lhs("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        String rhs(lhs);

        assert(lhs == "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        assert(rhs == "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
        assert(lhs == rhs);
    }
    {
        String lhs("          ");
        String rhs(lhs);

        assert(lhs == "          ");
        assert(rhs == "          ");
        assert(lhs == rhs);
    }
    {
        String lhs('&');
        String rhs(lhs);

        assert(lhs == '&');
        assert(rhs == '&');
        assert(lhs == rhs);
    }
    {//max capacity spaces only
        String lhs("                                                                                                                                                                                                                                                               ");
        String rhs(lhs);

        assert(lhs == "                                                                                                                                                                                                                                                               ");
        assert(rhs == "                                                                                                                                                                                                                                                               ");
        assert(lhs == rhs);
    }
    {
        String lhs("abcdefghijklmnopqrstuvwxyz123456789!@#$%^&*()-=_+[]{}|,.<>/?;':~ ");
        String rhs(lhs);

        assert(lhs == "abcdefghijklmnopqrstuvwxyz123456789!@#$%^&*()-=_+[]{}|,.<>/?;':~ ");
        assert(rhs == "abcdefghijklmnopqrstuvwxyz123456789!@#$%^&*()-=_+[]{}|,.<>/?;':~ ");
        assert(lhs == rhs);
    }
    {
        String lhs;
        String rhs(lhs);

        assert(!(lhs.length() > 0));
        assert(!(rhs.length() > 0));
        assert(lhs == rhs);
    }

    std::cout << "Done testing copy constructor." << std::endl;

    return 0;
}
