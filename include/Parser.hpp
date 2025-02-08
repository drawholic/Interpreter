#ifndef PARSER_HPP
#define PARSER_HPP

#include "AbstractExpression.hpp"
#include "NonTerminal.hpp"
#include <algorithm>

class Parser
{
	AbstractExpression* tree;

	static bool is_add_sub(AbstractExpression*);
	static bool is_mul_div(AbstractExpression*);

public:
	Parser();
	void build_tree(token_list&);
	void parse_add_sub(token_list&);
	void parse_mul_div(token_list&);
	void parse_parentheses(token_list&);
};

#endif