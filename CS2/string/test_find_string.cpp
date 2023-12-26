//  String class test program
//
//  Tests: find string
//

#include "string.hpp"
#include <cassert>
#include <iostream>

int main()
{
    {
        String stringToSearch("noooooon");
        String str("on");

        assert(stringToSearch.findstr(0, str) == 6);
    }
    {
        String stringToSearch("noooooon");
        String str("on");

        assert(stringToSearch.findstr(3, str) == 6);
    }
    {
        String stringToSearch("I live in the United States of America");
        String str("live");

        assert(stringToSearch.findstr(0, str) == 2);
    }
    {
        String stringToSearch("I live in the United States of America");
        String str("of");

        assert(stringToSearch.findstr(20, str) == 28);
    }
    {
        String stringToSearch("How much wood could a woodchuck chuck if a woodchuck could chuck wood?");
        String str("wood?");

        assert(stringToSearch.findstr(0, str) == 65);
    }
    {
        String stringToSearch("How much wood could a woodchuck chuck if a woodchuck could chuck wood?");
        String str("wood?");

        assert(stringToSearch.findstr(64, str) == 65);
    }
    {
        String stringToSearch("How much wood could a woodchuck chuck if a woodchuck could chuck wood?");
        String str("wood?");

        assert(stringToSearch.findstr(65, str) == 65);
    }
    {
        String stringToSearch("Sally sold sea shells by the seashore");
        String str("eas");

        assert(stringToSearch.findstr(0, str) == 30);
    }
    {
        String stringToSearch("Sally sold sea shells by the seashore");
        String str("eas");

        assert(stringToSearch.findstr(29, str) == 30);
    }
    {
        String stringToSearch("Sally sold sea shells by the seashore");
        String str("eas");

        assert(stringToSearch.findstr(30, str) == 30);
    }
    {
	String stringToSearch("Sally sold sea shells by the seashore");
	String str("ocean");

	assert(stringToSearch.findstr(0, str) == -1);
    }

    std::cout << "Done testing find string." << std::endl;

    return 0;
}
