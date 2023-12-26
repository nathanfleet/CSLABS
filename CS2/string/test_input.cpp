//  String class test program
//
//  Tests: input
//

#include "string.hpp"
#include <cassert>
#include <iostream>
#include <cstdlib>
#include <fstream>


int main()
{
    std::ifstream in("test_input_operator.txt");

    if (!in) {
        std::cerr << "Could not open test_input_operator.txt, exiting" << std::endl;
        exit(1);
    }

    String str;
    String result;
    while (!in.eof()) {
        in >> str;
	result += str;
        if (!in.eof()) {
            result += " ";
        } 
    }

    in.close();

    //std::cout << result << std::endl;
    assert(result == "This is a text file that I made to test the input operator.");

    std::cout << "Done testing input." << std::endl;

    return 0;
}
