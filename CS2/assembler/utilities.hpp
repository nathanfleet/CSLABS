#ifndef UTILITIES_HPP_
#define UTILITIES_HPP_

#include "string.hpp"

String infix_to_postfix   (String);
String infix_to_prefix    (String);
String postfix_to_assembly(std::ostream&, String);
String prefix_to_assembly (std::ostream&, String);
String evaluate_postfix   (String, String, String, int&, std::ostream&);
String evaluate_prefix    (String, String, String, int&, std::ostream&);
String int_to_string      (int num);

#endif
