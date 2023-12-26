//  String class test program
//
//  Tests: len cap
//

#include "string.hpp"
#include <cassert>
#include <iostream> 

int main()
{
    {//default len
        String str;

        assert(str.length() == 0);
    }
    {//single char len
        String str(' ');

        assert(str.length() == 1);
    }
    {//charArray max len
        String str("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");

        assert(str.length() == 255);
    }
    {
        String str("How much wood could a woodchuck chuck if a woodchuck could chuck wood?");

        assert(str.length() == 70);
    }
    {
        String str("test");

        assert(str.length() == 4);
    }
    {//charArray max len spaces
        String str("                                                                                                                                                                                                                                                               ");

        assert(str.length() == 255);
    }

    std::cout << "Done testing len cap." << std::endl;

    return 0;
}
