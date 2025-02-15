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
	static bool is_left_parenthesis(AbstractExpression*);
	static bool is_right_parenthesis(AbstractExpression*);
	static bool is_parenthesis(AbstractExpression*);
	static bool is_power(AbstractExpression*);
	static bool is_unary(AbstractExpression*);

public:
	Parser();
	void build_tree(token_list&);
	void parse_unary(token_list&);
	void parse_add_sub(token_list&);
	void parse_mul_div(token_list&);
	void parse_parentheses(token_list&);
	void parse_power(token_list&);

};

#endif