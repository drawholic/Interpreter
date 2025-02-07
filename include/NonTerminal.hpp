#ifndef NON_TERMINAL_HPP
#define NON_TERMINAL_HPP

#include "AbstractExpression.hpp"

enum Operator{
	ADD,
	SUB,

	MUL,
	DIV,

	POW,

	LP,
	RP,
	NONE
};

class NonTerminal: public AbstractExpression
{
	Operator op;
	AbstractExpression* left;
	AbstractExpression* right;

public:
	NonTerminal();
	NonTerminal(AbstractExpression*, AbstractExpression*);
	NonTerminal(Operator);
	NonTerminal(std::string&);


	value_type interpret() override;
	void print() override;

};

#endif