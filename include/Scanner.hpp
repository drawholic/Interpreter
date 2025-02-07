#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "AbstractExpression.hpp"

class Scanner{


public:
	Scanner();
	void clear_whitespaces(std::string&);
	void gen_expressions_list(std::list<AbstractExpression*>&);


};

#endif