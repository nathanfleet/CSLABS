// Nathan Fleet
// Recursion and Tail Recursion Fibonacci Program
// 3/17/22

#include <iostream>

int recursiveFib(int n) {
	if (n <= 1) {
		return n;
	} else {
		return recursiveFib(n - 1) + recursiveFib(n - 2);
	}
}

int tailRecursiveFib(int n, int first = 0, int second = 1) {
	if (n == 0) {
		return first;
	} else if (n == 1) {
		return second;
	} else {
		return tailRecursiveFib(n - 1, second, first + second);
	}
}

int main() {
	int n = 0;
	std::cout << "Enter number of terms for recursive fibonacci sequence: ";
	std::cin >> n;

	int i = 1;
	std::cout << "0 ";
	while (i <= n) {
		std::cout << recursiveFib(i) << " ";
		++i;
	}

	std::cout << std::endl;

	std::cout << "Enter number of terms for TAIL recursive fibonacci sequence: ";
	std::cin >> n;

	i = 1;
	std::cout << "0 ";
	while (i <= n) {
		std::cout << tailRecursiveFib(i) << " ";
		++i;
	}

	return 0;
}