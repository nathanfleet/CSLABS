// object construction main
//
// Nathan Fleet

#include "object_construction.hpp"
#include <iostream>

int main() {
	{
		std::cout << "ENTERING BLOCK" << std::endl;
		ABC lhs;
		ABC rhs;
		ABC abc(rhs);
		lhs = rhs;
		std::cout << "EXITING BLOCK" << std::endl;
	}
}