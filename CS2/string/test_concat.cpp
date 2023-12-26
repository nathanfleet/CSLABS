//  String class test program
//
//  Tests: concat
//

#include "string.hpp"
#include <cassert>
#include <iostream> 
 
int main ()
{
    {
        String lhs("nathan");
        String rhs("fleet");

        String result = lhs + rhs;

        assert(result == "nathanfleet");
    }
    {
        String lhs("aaaa");
        String rhs("aaaa");

        String result = lhs + rhs;

        assert(result == "aaaaaaaa");
    }
    { //testing +=
        String lhs("nathan");
        String rhs("fleet");

        lhs += rhs;

        assert(lhs == "nathanfleet");
    }
    {
        String lhs("fleet");
        String rhs("nathan");

        lhs += rhs;

        assert(lhs == "fleetnathan");
    }
    {
        String lhs("noooo");
        String rhs("oooon");

        String result = lhs + rhs;

        assert(result == "noooooooon");
    }
    {
        String lhs(" ");
        String rhs(" ");

        String result = lhs + rhs;

        assert(result == "  ");
    }
    {
        String lhs(" ");
        String rhs(" ");

        lhs += rhs;

        assert(lhs == "  ");
    }
    {
        String lhs("This sentence is a test");
        String rhs("this sentence is a test");

        String result = lhs + rhs;

        assert(result == "This sentence is a testthis sentence is a test");
    }
    {
        String lhs("This sentence is a test");
        String rhs(" this sentence is a test");

        String result = lhs + rhs;

        assert(result == "This sentence is a test this sentence is a test");
    }
    
    std::cout << "Done testing concat." << std::endl;

    return 0;
}
