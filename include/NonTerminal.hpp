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

	Operator pick_op(char&);
	Operator pick_op(std::string&);
	void print_operator();

public:
	~NonTerminal() override;
	NonTerminal();
	NonTerminal(AbstractExpression*, AbstractExpression*, Operator);
	NonTerminal(Operator);
	NonTerminal(std::string&);
	NonTerminal(char&);

	void set_left(AbstractExpression*);
	void set_right(AbstractExpression*);
	bool empty();
	
	Operator get_op();
	bool is_term() override;
	value_type interpret() override;
	void print() override;

};

#endif