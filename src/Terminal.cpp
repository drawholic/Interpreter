#include "Terminal.hpp"


Terminal::Terminal(value_type val)
{
	value = val;
};

value_type Terminal::interpret()
{
	return value;
};

void Terminal::print()
{
	std::cout << "Terminal " << value << std::endl;
};

bool Terminal::is_term()
{
	return true;
};