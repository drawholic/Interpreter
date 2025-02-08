#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <string>
#include "AbstractExpression.hpp"
#include "NonTerminal.hpp"
#include "Terminal.hpp"

#include <algorithm>
#include <cctype>

typedef std::string::iterator str_iter;

class Scanner{

	static bool isspace(char);

	str_iter find_past_number(str_iter, str_iter);
	bool is_negate(str_iter, str_iter);
	bool is_unary_add(str_iter, str_iter);
public:
	Scanner();
	void clear_whitespaces(std::string&);
	void gen_expressions_list(std::string&, token_list&);


};

#endif