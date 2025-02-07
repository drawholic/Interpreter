#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include "Scanner.hpp"
#include "Parser.hpp"

class Interpreter
{
	Scanner sc;
	Parser ps;
	std::string input_buf;
	token_list tokens;

public:
	Interpreter();
	void scan();
	void parse();
};

#endif