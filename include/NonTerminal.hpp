#ifndef NON_TERMINAL_HPP
#define NON_TERMINAL_HPP

#include "AbstractExpression.hpp"
#include <iostream>
#include <cmath>

enum Operator{
	ADD, SUB,

	MUL, DIV,

	POW,

	LP,	RP,
	
	NONE
};

class NonTerminal: public AbstractExpression
{
	Operator op;
	AbstractExpression* left;
	AbstractExpression* right;


	Operator pick_op(std::string&);
	void print_operator();
	bool empty();

public:
	~NonTerminal() override;
	NonTerminal();
	NonTerminal(AbstractExpression*, AbstractExpression*, Operator);
	NonTerminal(Operator);
	NonTerminal(std::string&);


	value_type interpret() override;
	void print() override;

};

#endif