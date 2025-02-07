#include "Interpreter.hpp"



Interpreter::Interpreter(){

	std::cout << "Enter arithmetic expression: ";
	std::getline(std::cin, input_buf);
	std::cout << "Entered: " << input_buf << std::endl;
};