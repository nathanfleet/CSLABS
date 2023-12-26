//  String class test program
//
//  Tests: find char
//

#include "string.hpp"
#include <cassert>
#include <iostream> 

int main()
{
    {
        String str("test");

        int result = str.findch(0, 't');

        assert(result == 0);
    }
    {
        String str("test");

        int result = str.findch(1, 't');

        assert(result == 3);
    }
    {
        String str(' ');

        int result = str.findch(0, ' ');

        assert(result == 0);
    }
    {
        String str("test ");

        int result = str.findch(0, ' ');

        assert(result == 4);
    }
    {
        String str(" t e s t ");

        int result = str.findch(1, ' ');

        assert(result == 2);
    }
    {
        String str("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");

        int result = str.findch(254, 'x');

        assert(result == 254);
    }
    {//testing out of bounds
        String str("testing");

        int result = str.findch(10, ' ');

        assert(result == -1);
    }
    { //testing out of bounds
        String str("testing");

        int result = str.findch(str.length(), ' ');

        assert(result == -1);
    }
    {//testing out of bounds (negative)
        String str("testing");

        int result = str.findch(-1, 'e');

        assert(result == 1);
    }

    std::cout << "Done testing find char." << std::endl;

    return 0;
}
