#include "string.hpp"
#include <cassert>

String::String() { //default ctor
	stringSize = 1;
	str = new char[stringSize];
	str[0] = 0;
}

String::String(char ch) : String() { //single char ctor
	if (ch != 0) {
		stringSize = 2;
		str = new char[stringSize];
		str[0] = ch;
		str[1] = 0;
	}
}

String::String(const char ch[]) {  //charArray ctor
	int charLength = 0;
	while (ch[charLength] != '\0') {
		++charLength;
	}

	stringSize = charLength + 1;
	str = new char[stringSize];

	int i = 0;
	while (i < stringSize - 1) {
		str[i] = ch[i];
		++i;
	}
	str[i] = 0;
}

String::String(const String& actual) { //copy ctor
	stringSize = actual.stringSize;
	str = new char[stringSize];

	int i = 0;
	while (i < stringSize - 1) {
		str[i] = actual.str[i];
		++i;
	}
	str[i] = 0;
}

String::~String() {
	delete[] str;
}

void String::swap(String& rhs) { //constant time swap
	char* temp = str;
	str = rhs.str;
	rhs.str = temp;

	int tempStringSize = stringSize;
	stringSize = rhs.stringSize;
	rhs.stringSize = tempStringSize;
}

String& String::operator=(String rhs) {
	swap(rhs);
	return *this;
}

int String::capacity() const {
	return length();
}

int String::length() const {
	int result = 0;
	if (str[0] == 0) {
		return 0;
	}

	while (str[result] != 0) ++result;

	return result;
}

char& String::operator[](int i) { //modifier
	assert(i >= 0);
	assert(i < length());
	return str[i];
}

char String::operator[](int i) const { //accessor
	assert(i >= 0);
	assert(i < length());
	return str[i];
}

String& String::operator+=(const String& rhs) { //concatenation
	int t = length();
	int r = rhs.length();

	stringSize = length() + rhs.length() + 1;
	char* temp = new char[stringSize];

	int i = 0;
	while (i < t) {
		temp[i] = str[i];
		++i;
	}
	int j = 0;
	while (j < r) {
		temp[i] = rhs[j];
		++i;
		++j;
	}
	temp[i] = 0;

	delete[] str;
	str = temp;

	return *this;
}

String operator+(String lhs, const String& rhs) { return lhs += rhs; }

bool String::operator==(const String& rhs) const {
	int i = 0;
	while ((str[i] != 0) && str[i] == rhs.str[i]) ++i;
	return str[i] == rhs.str[i];
}

bool operator==(char lhs, const String& rhs) { return String(lhs) == rhs; }
bool operator==(const char lhs[], const String& rhs) { return String(lhs) == rhs; }

bool String::operator<(const String& rhs) const {
	int i = 0;
	while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i])) ++i;
	return str[i] < rhs.str[i];
}

bool operator<(char lhs, const String& rhs) { return String(lhs) < rhs; }
bool operator<(const char lhs[], const String& rhs) { return String(lhs) < rhs; }

bool operator!=(const String& lhs, const String& rhs) { return !(lhs == rhs); }
bool operator<=(const String& lhs, const String& rhs) { return lhs < rhs || lhs == rhs; }
bool operator>=(const String& lhs, const String& rhs) { return !(lhs < rhs); }
bool operator> (const String& lhs, const String& rhs) { return rhs < lhs; }

int String::findch(int start, char ch) const {
	if (start >= length()) return -1; //length() is invoked on this
	if (start < 0) start = 0;

	int i = start;

	while (str[i] != 0) {
		if (str[i] == ch) return i;
		++i;
	}
	return -1;
}

int String::findstr(int start, const String& rhs) const {
	int result = -1;

	bool flag = false;
	int counter = 0;

	for (int i = start; i < length(); ++i) {
		if (str[i] == rhs[0]) {
			for (int j = i; j <= length(); ++j) {
				if (counter < rhs.length() && str[j] == rhs[counter]) {
					flag = true;
					result = j;
					if (counter == rhs.length() - 1) {
						break;
					}
				}
				else {
					flag = false;
					counter = 0;
					result = -1;
					break;
				}
				counter++;
			}
			if (flag) {
				result = result - (rhs.length() - 1);
				break;
			}
		}
	}

	return result;
}

String String::substr(int start, int end) const {
	String result;

	if (start < 0) start = 0;
	if (end >= length()) end = length() - 1;
	if (end < start) return result;
	if (start >= length()) return result;

	for (int i = start; i <= end; ++i) {
		result += str[i];
	}

	return result;
}

std::vector<String> String::split(char ch) const {
	std::vector<String> result;

	int start = 0;

	if (findch(start, ch) == -1) {
		result.push_back(substr(start, length()));
		return result;
	}
	
	int end = 0;

	while (findch(start, ch) != -1) {
		if(findch(start, ch) == -1) break;
		end = findch(start, ch) - 1;
		result.push_back(substr(start, end));
		start = findch(start, ch) + 1;
	}

	result.push_back(substr(start, length()));

	return result;
}

std::ostream& operator<<(std::ostream& out, const String& rhs) {
	out << rhs.str;
	return out;
}

std::istream& operator>>(std::istream& in, String& rhs) {
	char buffer[STRING_SIZE];

	if (in.eof()) {
		buffer[0] = 0;
	}
	else {
		in >> buffer;
	}

	rhs = String(buffer);

	return in;
}
