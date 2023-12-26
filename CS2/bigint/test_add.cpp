// bigint Test Program
//
// Tests:  int constructor, uses ==
//
// NEED TO IMPLEMENT
//
#include <iostream> 
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }
    {
	bigint left(99999999);
	bigint right(99999999);
	bigint result;

	result = left + right;

	assert(left == 99999999);
	assert(right == 99999999);
	assert(result == 199999998);
    }
    {
	bigint left("99999999");
	bigint right("99999999");
	bigint result;

	result = left + right;

	assert(left == 99999999);
	assert(right == 99999999);
	assert(result == 199999998);
     }
     {
	bigint left("0");
	bigint right("0");
	bigint result;

	result = left + right;

	assert(left == 0);
	assert(right == 0);
	assert(result == 0);
     }
     {
	bigint left;
	bigint right;
	bigint result;

	result = left + right;

	assert(left == 0);
	assert(right == 0);
	assert(result == 0);
     }

    std::cout << "Done with testing addition." << std::endl;
    return 0;
}

