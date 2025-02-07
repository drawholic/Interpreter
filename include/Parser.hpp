#ifndef PARSER_HPP
#define PARSER_HPP

#include "AbstractExpression.hpp"

class Parser
{
	AbstractExpression* tree;

public:
	Parser();
	void buildTree(AbstractExpression*);
	void parse_add_sub();
	void parse_mul_div();
	void parser_parentheses();
};

#endif