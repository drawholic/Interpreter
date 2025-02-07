#ifndef TERMINAL_HPP
#define TERMINAL_HPP

#include "AbstractExpression.hpp"

class Terminal: public AbstractExpression
{
	value_type value;
public:
	Terminal();
	value_type interpret() override;
	void print() override;
};

#endif