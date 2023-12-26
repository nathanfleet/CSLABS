//  String class test program
//
//  Tests: split
//

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        String rhs("aa bb cc");

        std::vector<String> result = rhs.split(' ');

        assert(result.size() == 3);
    }
    {
        String rhs("aabbcc");

        std::vector<String> result = rhs.split(' ');

        assert(result.size() == 1);
    }
    {
        String rhs("aaaaa bbbbb");

        std::vector<String> result = rhs.split(' ');

        assert(result.size() == 2);
        
    }
    {
        String rhs("abc ef gh");

        std::vector<String> result = rhs.split(' ');

        assert(result.size() == 3);
    }
    {
        String rhs("-a--b-");

        std::vector<String> result = rhs.split('-');

        assert(result.size() == 5);
    }
    {
        String rhs("*a**b*");

        std::vector<String> result = rhs.split('*');

        assert(result.size() == 5);
    }


    std::cout << "Done testing split." << std::endl;

    return 0;
}
