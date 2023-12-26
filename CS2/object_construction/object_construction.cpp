// object construction implementation
//
// Nathan Fleet
#include "object_construction.hpp"
#include <iostream>

ABC::ABC() { //default constructor
	std::cout << "DEFAULT CONSTRUCTOR CALLED" << std::endl;
}

ABC::~ABC() { //destructor
	std::cout << "DESTRUCTOR CALLED" << std::endl;
}

ABC::ABC(const ABC& rhs) { // copy constructor
	std::cout << "COPY CONSTRUCTOR CALLED" << std::endl;
}

ABC& ABC::operator=(ABC rhs) {
	std::cout << "ASSIGNMENT OPERATOR CALLED" << std::endl;

	return *this;
}