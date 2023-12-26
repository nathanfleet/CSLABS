//  String class test program
//
//  Tests: Swap assign
//

#include "string.hpp"
#include <cassert>
#include <iostream>

int main() {
	{
		String lhs("left");
		String rhs("right");

		lhs.swap(rhs);

		assert(lhs == "right");
		assert(rhs == "left");
	}
	{
		String lhs("left");
		String rhs("right");

		rhs.swap(lhs);

		assert(lhs == "right");
		assert(rhs == "left");
	}
	{
		String lhs('a');
		String rhs('b');

		lhs.swap(rhs);

		assert(lhs == 'b');
		assert(rhs == 'a');
	}
	{
		String lhs('a');
		String rhs('b');

		rhs.swap(lhs);

		assert(lhs == 'b');
		assert(rhs == 'a');
	}
	{
		String lhs("     ");
		String rhs("          ");

		lhs.swap(rhs);

		assert(lhs == "          ");
		assert(rhs == "     ");
	}
	{
		String lhs("     ");
		String rhs("          ");

		rhs.swap(lhs);

		assert(lhs == "          ");
		assert(rhs == "     ");
	}
	{
		String lhs("left");
		String rhs("");

		lhs.swap(rhs);

		assert(lhs == "");
		assert(rhs == "left");
	}
	{
		String lhs("left");
		String rhs("");

		rhs.swap(lhs);

		assert(lhs == "");
		assert(rhs == "left");
	}
	{
		String lhs("");
		String rhs("right");

		lhs.swap(rhs);

		assert(lhs == "right");
		assert(rhs == "");
	}
	{
		String lhs("");
		String rhs("right");

		rhs.swap(lhs);

		assert(lhs == "right");
		assert(rhs == "");
	}

	std::cout << "Done testing swap assign." << std::endl;

	return 0;
}