#ifndef ABSTRACT_EXPRESSION_HPP
#define ABSTRACT_EXPRESSION_HPP

#include <list>

typedef int value_type;


class AbstractExpression
{


public:
	virtual value_type interpret();
	virtual void print();
};


typedef std::list<AbstractExpression*> token_list;


#endif