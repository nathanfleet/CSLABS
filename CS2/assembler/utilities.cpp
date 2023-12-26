#include "utilities.hpp"
#include "stack.hpp"
#include <vector>

String infix_to_postfix(String infixExpr) {
	std::vector<String> vec = infixExpr.split(' ');
	stack<String> S;
	String lhs, rhs, op;
	int i = 0;
	
	while (vec[i] != ';') {
		if (vec[i] == ')') {
			rhs = S.pop();
			op = S.pop();
			lhs = S.pop();
			S.push(lhs + " " + rhs + " " + op);
		} else if (vec[i] != '(') {
			S.push(vec[i]);	
		}
		++i;
	}
	return S.pop();
}

String infix_to_prefix(String infixExpr) {
	std::vector<String> vec = infixExpr.split(' ');
	stack<String> S;
	String lhs, rhs, op;
	int i = 0;

	while (vec[i] != ';') {
		if (vec[i] == ')') {
			rhs = S.pop();
			op = S.pop();
			lhs = S.pop();
			S.push(op + " " + lhs + " " + rhs);
		} else if (vec[i] != '(') {
			S.push(vec[i]);
		}
		++i;
	}
	return S.pop();
}

String prefix_to_assembly(std::ostream& out, String prefixExpr) {
	std::vector<String> vec = prefixExpr.split(' ');
	stack<String> S;
	String lhs, rhs;
	int temp = 0;

	for (size_t i = vec.size() - 1; i > 0; --i) {
		if (vec[i] != '+' && vec[i] != '-' && vec[i] != '*' && vec[i] != '/') {
			S.push(vec[i]);
		} else {
			rhs = S.pop();
			lhs = S.pop();
			S.push(evaluate_prefix(lhs, rhs, vec[i], temp, out));
		}
	}
	return S.pop();
}

String postfix_to_assembly(std::ostream& out, String postfixExpr) {
	std::vector<String> vec = postfixExpr.split(' ');
	stack<String> S;
	String lhs, rhs;
	int temp = 0;

	for (size_t i = 0; i < vec.size(); ++i) {
		if (vec[i] != '+' && vec[i] != '-' && vec[i] != '*' && vec[i] != '/') {
			S.push(vec[i]);
		} else {
			rhs = S.pop();
			lhs = S.pop();
			//push evaluate (left, t, right)
			S.push(evaluate_postfix(lhs, rhs, vec[i], temp, out));
		}
	}
	return S.pop();
}

String evaluate_prefix(String lhs, String rhs, String op, int& temp, std::ostream& out) {
	//load right
	out << "   " << "LD" << "     " << rhs << std::endl;

	//operation on left
	if (op == '+') {
		out << "   " << "AD" << "     " << lhs << std::endl;
	}
	else if (op == '-') {
		out << "   " << "SB" << "     " << lhs << std::endl;
	}
	else if (op == '*') {
		out << "   " << "MU" << "     " << lhs << std::endl;
	}
	else if (op == '/') {
		out << "   " << "DV" << "     " << lhs << std::endl;
	}

	//store temp
	String tmp("TMP");
	tmp = tmp + int_to_string(++temp);
	out << "   " << "ST" << "     " << tmp << std::endl;

 	//return TMPn
	return tmp;
}

String evaluate_postfix(String lhs, String rhs, String op, int& temp, std::ostream& out) {
	//load left
	out << "   " << "LD" << "     " << lhs << std::endl;

	//operation on right
	if (op == '+') {
		out << "   " << "AD" << "     " << rhs << std::endl;
	} else if (op == '-') {
		out << "   " << "SB" << "     " << rhs << std::endl;
	} else if (op == '*') {
		out << "   " << "MU" << "     " << rhs << std::endl;
	} else if (op == '/') {
		out << "   " << "DV" << "     " << rhs << std::endl;
	}

	//store temp
	String tmp("TMP");
	tmp = tmp + int_to_string(++temp);
	out << "   " << "ST" << "     " << tmp << std::endl;

	//return TMPn
	return tmp;
}

String int_to_string(int num) {
	String result;

	int temp = 0;
	while (num != 0) {
		temp = num % 10;
		num = num / 10;
		result = String(char(temp + '0')) + result;
	}
	return result;
}