//
//
//
#include "bigint.hpp"
#include <iostream>

bigint::bigint() { //default constructor
	for (int i = 0; i < CAPACITY; i++) {
		integerArray[i] = 0;
	}
}

bigint::bigint(int userNum) { //integer constructor
	int temp;

	for (int i = 0; i < CAPACITY; ++i) {
		if (userNum > 9) {
			temp = userNum % 10;
			integerArray[i] = temp;
			userNum = userNum / 10;
		}
		else if (userNum <= 9) {
			integerArray[i] = userNum;
			userNum = userNum / 10;
		}
		else {
			break;
		}
	}

}

bigint::bigint(const char userChar[]) {
	int counter = 0;

	while (userChar[counter] != '\0') { //null character
		counter++;
	}//get the length of the character sequence
	int length = counter;
	for (int i = 0; i < CAPACITY; ++i) {
		if (i < length) {
			integerArray[i] = userChar[counter - 1] - '0';
			counter--;
		}
		else {
			integerArray[i] = 0;
		}
	}
}

std::ostream& bigint::debugPrint(std::ostream& out) const {
	for (int i = CAPACITY - 1; i > 0; i--) {
		out << integerArray[i] << "|";
	}
	return out;
}

std::ostream& operator<<(std::ostream& out, const bigint& bigintToPrint) {
	int counter = 0;

	if (counter == 500) {
		out << 0;
		return out;
	}

	for (int i = CAPACITY - 1; i > 0; --i) {
		if (bigintToPrint.integerArray[i] == 0) {
			counter++;
		}
		else {
			for (int j = CAPACITY - (counter + 1); j >= 0; --j) {
				out << bigintToPrint.integerArray[j];
			}
			break;
		}
	}
	return out;
}

bool operator==(const bigint& lhs, const bigint& rhs) {
	for (int i = 0; i < CAPACITY; i++) {
		if (lhs.integerArray[i] != rhs.integerArray[i]) {
			return false;
		}
	}
	return true;
}

bigint bigint::operator+(const bigint& rhs) const {
	bigint result;

	int carry = 0;
	for (int i = 0; i < CAPACITY; ++i) {
		if (((this->integerArray[i]) + (rhs.integerArray[i]) + carry) >= 10) {
			result.integerArray[i] = (this->integerArray[i] + (rhs.integerArray[i]) + result.integerArray[i] + carry) % 10;
			carry = 1;
		}
		else {
			result.integerArray[i] = this->integerArray[i] + (rhs.integerArray[i]) + carry;
			carry = 0;
		}
	}
	return result;
}

bigint bigint::operator*(const bigint& rhs) const {
	bigint product;
	bigint temp;

	for (int i = 0; i < CAPACITY - 1; ++i) {
		temp = this->timesDigit(rhs[i]);
		product = product + temp.times10(i);
	}
	return product;
}

int bigint::operator[](const int& spot) const {
	return (integerArray[spot]);
}

std::istream& operator>>(std::istream& in, bigint& rhs) {
	char ch;
	int count = 0;
	int temp[CAPACITY];

	while (in >> ch) {
		if (ch == ';') {
			break;
		}
		temp[count] = ch - '0'; //get decimal value
		++count;
	}

	for (int i = 0; i < count; ++i) {//assign temp values to rhs
		rhs.integerArray[i] = temp[i];
	}

	return in;

}

bigint bigint::timesDigit(int multiplier) const {
	bigint result;

	int temp = 0;
	int carry = 0;
	for (int i = 0; i < CAPACITY; ++i) {
		temp = integerArray[i] * multiplier;
		temp = temp + carry;
		carry = temp / 10;
		result.integerArray[i] = temp % 10;
	}
	return result;
}

bigint bigint::times10(int power) const {
	bigint result;

	for (int i = CAPACITY - power - 1; i >= 0; i--) {
		result.integerArray[i + power] = integerArray[i];
	}
	return result;
}

bigint bigint::nfact(const int& fact) const {
	bigint result("1");

	for (int i = 1; i <= fact; ++i) {
		result = result * i;
	}

	return result;
}

int trailingZero(const bigint& fact) {
	int factLength = 158; //#obtained by counting digits in 10)! output
	int result = 0;

	for (int i = 0; i < factLength; ++i) {
		if (fact.integerArray[i] == 0) {
			result++;
		} else {
			break;
		}
	}
	return result;
}