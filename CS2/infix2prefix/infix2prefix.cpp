#include "stack.hpp"
#include <iostream>
#include "string.hpp"
#include <vector>
#include <fstream>

String infix2prefix(String expr) {
	stack<String> S;
	std::vector<String> vec = expr.split(' ');
	String lhs, rhs, op;
	int i = 0;
	
	while (vec[i] != ';') {
		if (vec[i] == ')') {
			rhs = S.pop();
			op = S.pop();
			lhs = S.pop();
			S.push(op + lhs + rhs);
		} else if (vec[i] != '(') {
			S.push(vec[i]);
		}
		++i;
	}
	return S.pop();
}

int main() {
	std::ifstream in("data3-1.txt");

	if (!in.is_open()) {
		std::cout << "Unable to open file." << std::endl;
		return 0;
	}

	if (in) {
		String infixExpr;

		while (!in.eof()) {
			char ch = in.get();
			if (in.eof()) break;
			if (ch == ';') {
				String postfixExpr = infix2prefix(infixExpr += ';');
					std::cout << "Infix   Expression: " << infixExpr << std::endl;
					std::cout << "Prefix  Expression: " << postfixExpr << std::endl;
					infixExpr = "";
			}
			if (ch != ';' && ch != '\n' && ch != '\r') {
				infixExpr += ch;
			}
		}
	}

	in.close();

	return 0;
}
