// LAB 1
// Nathan Fleet
// August 24, 2023
// FILE: diff.hpp

#ifndef DIFF_HPP
#define DIFF_HPP

#include <iostream>
#include <fstream>
#include <string>

bool checkLen(std::ifstream&, std::ifstream&, std::string, std::string);
void printDiff(int, int, std::string, std::string, std::string, std::string);
void findDiff(std::ifstream&, std::ifstream&, std::string, std::string);

bool checkLen(std::ifstream& file1, std::ifstream& file2, std::string filename1, std::string filename2) {
    std::string lineA;
    std::string lineB;
    int lineCount = 0;

    // count lines until one file reaches end
    while(std::getline(file1, lineA) && std::getline(file2, lineB)) {
        lineCount++;
    }

    // continue counting in first file to see if it had more lines
    while(std::getline(file1, lineA)) {
        // if it does then increment again and display the difference against file2's empty line
        if(!lineA.empty()) {
            lineCount++;
            printDiff(lineCount, 0, lineA, "", filename1, filename2);
            return true;
        }
    }

    // continue counting in second file to see if it had more lines
    while(std::getline(file2, lineB)) {
        // if it does then increment again and display the difference against file1's empty line
        if(!lineB.empty()) {
            lineCount++;
            printDiff(lineCount, 0, "", lineB, filename1, filename2);
            return true;
        }
    }

    // return false if files are the same length
    return false;

}

// when a difference is located, this function is invoked
// lineCount = line the difference was found on
// i = index of different character on on the line
void printDiff(int lineCount, int i, std::string lineA, std::string lineB, std::string filename1, std::string filename2) {
    std::cout << filename1 << ": " << lineCount << ": " << lineA << std::endl;
    std::cout << filename2 << ": " << lineCount << ": " << lineB << std::endl;

    // convert lineCount to string to get correct offset for '^' placement in console
    std::string line = std::to_string(lineCount);
    std::string spaceString((filename1.length() + line.length() + 4 + i), ' ');
    std::cout << spaceString << '^' << std::endl;
}

void findDiff(std::ifstream& file1, std::ifstream& file2, std::string filename1, std::string filename2) {
    std::string lineA;
    std::string lineB;

    int lineCount = 1;

    // iterate through each line of both files simultaneously
    while(!file1.eof() || !file2.eof()) {
        std::getline(file1, lineA);
        std::getline(file2, lineB);

        // for each line, check each character in the line for a difference
        for(int i = 0; i < lineA.length() || i < lineB.length(); ++i) {
            // print the difference if located
            if(lineA[i] != lineB[i]) {
                printDiff(lineCount, i, lineA, lineB, filename1, filename2);
                break;
            }
        }
        ++lineCount;
    }
}

#endif
