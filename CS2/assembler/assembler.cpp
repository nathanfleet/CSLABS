#include "utilities.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
	std::ifstream in(argv[1]);

	if (!in.is_open()) {
		std::cerr << "Unable to open input file." << std::endl;
		return 1;
	}

	char ch;
	String infixExpr1; //one for postfix expression
	String infixExpr2; //two for prefix  expression
	if (argc == 2) {
		while (!in.eof()) {
			in.get(ch);
			if (in.eof()) break;
			if (ch == ';') {
				String postfixExpr = infix_to_postfix(infixExpr1 += ';');
				std::cout << "Infix   Expression: " << infixExpr1 << std::endl;
				std::cout << "Postfix Expression: " << postfixExpr << std::endl;
				
				//postfix assembler output
				std::cout << std::endl;
				postfix_to_assembly(std::cout, postfixExpr);
				std::cout << std::endl;

				String prefixExpr = infix_to_prefix(infixExpr2 += ';');
				std::cout << "Prefix Expression: " << prefixExpr << std::endl;

				//prefix assembler output
				std::cout << std::endl;
				prefix_to_assembly(std::cout, prefixExpr);
				std::cout << std::endl;
				
				//separate output
				std::cout << "================================================================" << std::endl;

				infixExpr1 = "";
				infixExpr2 = "";
			}
			if (ch != ';' && ch != '\n' && ch != '\r') {
				infixExpr1 += ch;
				infixExpr2 += ch;
			}
		}
	}
	else if (argc == 3) { //output to file
		std::ofstream out(argv[2]);
		if (!out.is_open()) {
			std::cerr << "Unable to open output file." << std::endl;
			return 1;
		}
		while (!in.eof()) {
			in.get(ch);
			if (in.eof()) break;
			if (ch == ';') {
				String postfixExpr = infix_to_postfix(infixExpr1 += ';');
				out << "Infix   Expression: " << infixExpr1 << std::endl;
				out << "Postfix Expression: " << postfixExpr << std::endl;
				
				//postfix assembler output
				out << std::endl;
				postfix_to_assembly(out, postfixExpr);
				out << std::endl;

				String prefixExpr = infix_to_prefix(infixExpr2 += ';');
				out << "Prefix Expression: " << prefixExpr << std::endl;

				//prefix assembler output
				out << std::endl;
				prefix_to_assembly(out, prefixExpr);
				out << std::endl;

				//separate output
				out << "================================================================" << std::endl;

				infixExpr1 = "";
				infixExpr2 = "";
			}
			if (ch != ';' && ch != '\n' && ch != '\r') {
				infixExpr1 += ch;
				infixExpr2 += ch;
			}
		}
		out.close();
	}

	in.close();

	return 0;
}
