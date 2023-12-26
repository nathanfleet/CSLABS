// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 4);
    }
    {//testing char
	bigint bi("4");
	int digit = bi[0];

	assert(bi == 4);
	assert(digit == 4);
    }
    {//testing middle of bigint
	bigint bi("9999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
	int digit = bi[99];

	assert(digit == 9);
    }
    {//tesing last digit of bigint
	bigint bi("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999");
	int digit = bi[199];

	assert(digit == 9);
    }
    {
	bigint bi(123);
	int digit = bi[1];

	assert(digit == 2);
    }
    {
	bigint bi(123);
	int digit = bi[2];

	assert(digit == 1);
    }
    {
	bigint bi(123);
	int digit = bi[0];

	assert(digit == 3);
    }

    std::cout << "Done testing subscript." << std::endl;
    return 0;
}

