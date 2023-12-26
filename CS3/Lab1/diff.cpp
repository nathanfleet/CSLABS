// LAB 1
// Nathan Fleet
// August 24, 2023
// FILE: diff.cpp

#include "diff.hpp"

int main(int argc, char* argv[]) {
    // check for correct # of arguments before proceeding
    if(argc != 3) {
        std::cout << "Invalid arguments, quitting..." << std::endl;
        return 1;
    } else {
        std::string filename1;
        filename1 = argv[1];

        std::string filename2;
        filename2 = argv[2];

        std::ifstream check1(argv[1]);
        std::ifstream check2(argv[2]);

        // check the number of lines in each file, if one file has more lines checkLen returns true
        if(checkLen(check1, check2, filename1, filename2)){
            check1.close();
            check2.close();
            return 0;
        }

        // check each line character by character and display difference (if there is one)
        std::ifstream file1(argv[1]);
        std::ifstream file2(argv[2]);
        findDiff(file1, file2, filename1, filename2);

        file1.close();
        file2.close();
    }

    return 0;
}
