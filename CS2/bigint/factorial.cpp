#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {
	std::cout << "Calculating 100 factorial (100!)..." << std::endl;

	bigint fact;
	fact = fact.nfact(100);

	std::cout << fact << std::endl;

	std::cout << "=================Description=================" << std::endl;

	std::cout << "The way I calculated this answer was because I knew that for 5!" << std::endl;
	std::cout << "you do 1*2*3*4*5. I applied this same logic to 100 by starting the for loop" << std::endl;
	std::cout << "at 1 because (0*X) is always 0, then I had it iterate to whatever factorial the user wants to evaluate." << std::endl;
	std::cout << "Then, I created a bigint that would store the previous value of i multiplied by the current value of i." << std::endl;
	std::cout << "This would calculate 1*2*3...*99*100 and store it in the result bigint and return it." << std::endl;

	std::cout << "=================Trailing Zeroes=================" << std::endl;

	std::cout << "Calculating 100! trailing zeros..." << std::endl;
	std::cout << trailingZero(fact) << std::endl;
	std::cout << "The way I calculated this answer was by counting the zeros at displated at the end of the output for the nfact function." << std::endl;
	std::cout << "Then, I created a for loop to iterate from the beginning of the bigint and count each zero until it finds a number > 0" << std::endl;
	std::cout << "It then outputs the result. There is likely a formula for calculating the trailing zeroes mathematically. While I don't know" << std::endl;
	std::cout << "The formula I think that it could have something to do with multiples of 10, where each multiple of 10 would add a zero." << std::endl;

	return 0;
}