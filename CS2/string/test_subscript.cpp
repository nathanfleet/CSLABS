//  String class test program
//
//  Tests: subscript
//

#include "string.hpp"
#include <cassert>
#include <iostream> 
 
int main ()
{
    {
        String str("nathan");

        String result = str[0];

        assert(result == 'n');
    }
    {
        String str(' ');

        String result = str[0];

        assert(result == ' ');
    }
    {
        String str("     0");

        String result = str[5];

        assert(result == '0');
    }
    {
        String str("Sally sells sea shells by the sea shore");

        String result = str[38];

        assert(result == 'e');
    }
    {
        String str("How much wood could a woodchuck chuck if a woodchuck could chuck wood?");

        String result = str[69];

        assert(result == '?');
    }
    {
        String str("---------- ");

        String result = str[10];

        assert(result == ' ');
    }
    {
        String str('?');

        String result = str[0];

        assert(result == '?');   
    }
    {
        String str("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");

        String result = str[254];

        assert(result == 'x');
    }
    
    std::cout << "Done testing subscript." << std::endl;

    return 0;
}
