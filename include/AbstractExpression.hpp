#ifndef ABSTRACT_EXPRESSION_HPP
#define ABSTRACT_EXPRESSION_HPP

#include <list>

typedef int value_type;


class AbstractExpression
{


public:
	virtual ~AbstractExpression();
	virtual value_type interpret() = 0;
	virtual void print() = 0;
};


typedef std::list<AbstractExpression*> token_list;


#endif