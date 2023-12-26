//  Stack class test program
//
//  Tests: Infix to postfix
//

#include <iostream>
#include <cassert>
#include "utilities.hpp"

int main() {
	{
		String lhs("( AX * ( B + C ) ) ;");
		String rhs = infix_to_postfix(lhs);
		assert(rhs == "AXBC+*");
	}
	{
		String lhs("( AX + ( ( B * C ) + D ) ) ;");
		String rhs = infix_to_postfix(lhs);
		assert(rhs == "AXBC*D++");
	}
	{
		String lhs("( ( H * ( ( ( ( A + ( ( B + C ) * D ) ) * F ) * G ) * E ) ) + J ) ;");
		String rhs = infix_to_postfix(lhs);
		assert(rhs == "HABC+D*+F*G*E**J+");
	}
	{
		String lhs("( ( AX * BX ) + ( ( ( ( ( ( CX - DY ) * EX ) * FX ) * GY ) * HX ) + JY ) ) ;");
		String rhs = infix_to_postfix(lhs);
		assert(rhs == "AXBX*CXDY-EX*FX*GY*HX*JY++");
	}
	{
		String lhs("( ( ( A * B ) / C ) - ( ( D + E ) * F ) ) ;");
		String rhs = infix_to_postfix(lhs);
		assert(rhs == "AB*C/DE+F*-");
	}

	std::cout << "Done testing infix to postfix conversion." << std::endl;

	return 0;
}
