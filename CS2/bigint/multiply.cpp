#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
	std::ifstream in("data1-2.txt");
	if (!in) {
		std::cerr << "Could not open data1-1.txt, exiting" << std::endl;
		exit(1);
	}

	bigint bigint1;
	bigint bigint2;

	while (!in.eof()) {
		in >> bigint1 && in >> bigint2;

		std::cout << "Num 1: " << bigint1 << std::endl;
		std::cout << "Num 2: " << bigint2 << std::endl;

		bigint result;
		result = bigint1 * bigint2;

		std::cout << "Result: " << result << std::endl;
	}

	in.close();

	return 0;
}