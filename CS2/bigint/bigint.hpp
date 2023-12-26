
#ifndef BIGINT_HPP_
#define BIGINT_HPP_

#include <ostream>

const int CAPACITY = 500;

class bigint {
public:
	bigint();
	bigint(int);
	bigint(const char[]);

	std::ostream& debugPrint(std::ostream&) const;

	friend std::ostream& operator<<(std::ostream&, const bigint&);
	friend bool operator==(const bigint&, const bigint&);
	bigint operator+(const bigint&) const;
	bigint operator*(const bigint&) const;
	int operator[](const int&) const;

	friend std::istream& operator>>(std::istream&, bigint&);

	bigint timesDigit(int) const;
	bigint times10(int) const;

	bigint nfact(const int&) const;
	friend int trailingZero(const bigint&);

private:
	int integerArray[CAPACITY];

};



#endif // !BIGINT_HPP_
