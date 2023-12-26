//
// Kent State University
// CS 23001 - J. Maletic
//
// Part of lab 6 on dynamic memory
//
// Memory allocation and array bounds checking
//
// C/C++ does not check array bounds, so accessing an element of an
//    array outside of its defined size results in Undefined Behavior
//
// TO COMPILE: clang++ -Wall array_bounds_check.cpp -o bounds_check
// TO RUN: ./bounds_check
//           Then enter a postivie interger value at the prompt
//
// Instructions:
//   Read the code.  Then run the program multiple times.  Examing the output.
//   If on wasp/hornet use values of 10, 16, 32, 33, 40
//   If on a Mac use values of 10 16, 17, 20
//
//   What is wrong with this code?

     // The code is wrong because when the user inputs larger numbers, values that were
     // supposed to be stored in str1 are written over str2.

//   Why is no error raised?

     // No error is raised because even though the program is trying to store values that
     // are past the last index of str1, it is still able to write on memory, because that
     // memory overlaps str2.

//   How many bytes are between the start of str1 and str2?

     // 15 bytes

//   How could you test for this logical error?

     // You could test for this logical error by displaying the values in the array, and
     // making sure that values from another array did not get written on top of it.

//   How could you prevent this type of error?

     // You could prevent this type of error by asking the user for the size first, and then
     // making the dynamic array so that it will have the correct number of indexes.

//   Include the delete[] at then end and recompile, what changes?

     // After uncommenting delete[], the program aborts and says "size too large"

#include <iostream>

int main() {
    char* str1 = new char[5];     //Allocate two arrays on the heap
    char* str2 = new char[20];
    int n = 0;

    std::cout << "str1->char[5]" << std::endl;
    std::cout << "str2->char[20]" << std::endl;
    std::cout << "Enter positive integer value: ";  // n > 0
    std::cin >> n;

    std::cout << "Write to array str1:" << std::endl;
    for (int i = 0; i < n; ++i) {   //Write to str1[0...n-1]
        str1[i] = 'X';
        std::cout << "str1[" << i << "] = 'X'" << std::endl;
    }

    std::cout << "Contents of array str1:" << std::endl;
    for (int i = 0; i < n; ++i) {   //Print str1[0...n-1]
        std::cout << "str1[" << i << "] == " << "|" << str1[i] << "|" << std::endl;
    }

    std::cout << "Contents of array str2:" << std::endl;
    for (int i = 0; i < 20; ++i) {    //Print str2[0...19]
        std::cout << "str2[" << i << "] == " << "|" << str2[i] << "|" << std::endl;
    }

    delete[] str1;
    delete[] str2;

    return 0;
}

