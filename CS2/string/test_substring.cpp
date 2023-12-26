//  String class test program
//
//  Tests: substring
//

#include "string.hpp"
#include <cassert>
#include <iostream> 

int main()
{
    {
        String str("test");

        String result = str.substr(0, 0);

        assert(result == 't');
    }
    {
        String str("test");

        String result = str.substr(1, 2);

        assert(result == "es");
    }
    {
        String str(' ');

        String result = str.substr(0, 0);

        assert(result == ' ');
    }
    {
        String str("this is a test");

        String result = str.substr(0, 14);

        assert(result == "this is a test");
    }
    {
        String str("          ");

        String result = str.substr(5, 9);

        assert(result == "     ");
    }
    {
        String str("123456789");

        String result = str.substr(0, 9);

        assert(result == "123456789");
    }
    {//testing max capacity
        String str("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");

        String result = str.substr(0, 255);

        assert(result == "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    }
    {//testing max capacity spaces
        String str("                                                                                                                                                                                                                                                               ");

        String result = str.substr(0, 255);

        assert(result == "                                                                                                                                                                                                                                                               ");
    }
    {
        String str("How much wood could a woodchuck chuck if a woodchuck could chuck wood?");

        String result = str.substr(22, 30);

        assert(result == "woodchuck");
    }

    std::cout << "Done testing substring." << std::endl;

    return 0;
}
