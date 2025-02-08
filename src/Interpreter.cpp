#include "Interpreter.hpp"



Interpreter::Interpreter(){

	std::cout << "Enter arithmetic expression: ";
	std::getline(std::cin, input_buf);
	std::cout << "Entered: " << input_buf << std::endl;

	sc.clear_whitespaces(input_buf);

	sc.gen_expressions_list(input_buf, tokens);

	ps.build_tree(tokens);	

	std::cout << tokens.front()->interpret() << std::endl;
};

void Interpreter::print_tokens()
{
	for(auto i : tokens)
		i->print();

};