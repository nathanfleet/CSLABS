#include <iostream>
#include <fstream>

void readToSpace() {
	std::ifstream file("fileio-text.txt");

	if (!file.is_open()) { //if file is not open
		std::cout << "Unable to open file." << std::endl;
		return;
	}

	char ch;
	file.get(ch);
	while (!file.eof()) {
		while (!file.eof()) { //while not at end of file
			if (ch == ' ') {
				break;
			}
			std::cout << ch;
			file.get(ch);
		}
		std::cout << std::endl;
		file.get(ch);
	}
	file.close();

}


void sum() {
	std::ifstream file("fileio-data-1.txt");

	if (!file.is_open()) {
		std::cout << "Unable to open file.";
		return;
	}

	char ch;
	int num1 = 0;
	int num2 = 0;

	file.get(ch);
	while (!file.eof()) {
		if (ch == ';') {
			while (!file.eof()) {
				file.get(ch);
				if (ch == ';') {
					break;
				}
				num2 = (int(ch) - int('0')); //same as static cast
			}
			break;
		} 
		if (num1 == 0) {
			num1 = int(ch) - int('0');
			num1 = (num1 * 10);
			file.get(ch);
		} else {
			num1 += (int(ch) - int('0'));
			file.get(ch);
		}
	}

	std::cout << "Num 1: " << num1 << std::endl << "Num 2: " << num2 << std::endl;
	std::cout << "Sum: " << (num1 + num2) << std::endl;

	file.close();
	
}	


int main() {
	std::ifstream in("fileio-text.txt");


	readToSpace();
	std::cout << "-------------------------------------------------------------" << std::endl;
	sum();
}