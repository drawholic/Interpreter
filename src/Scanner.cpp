#include "Scanner.hpp"


Scanner::Scanner(){};

void Scanner::clear_whitespaces(std::string& input)
{
	str_iter pend = std::remove_if(input.begin(), input.end(), isspace);
	input.assign(input.begin(), pend);
};

bool Scanner::isspace(char c)
{
	return std::isspace(c);
};

void Scanner::gen_expressions_list(std::string& input, token_list& tokens)
{	
	char temp_c;
	std::string temp_num;
	str_iter past_number;

	NonTerminal* non_term;
	Terminal* term;
	str_iter start = input.begin();
	str_iter pend = input.end();
	str_iter it = start;

	while(it != pend)
	{
		temp_c = *it;
		if(std::isdigit(temp_c))
		{
			past_number = find_past_number(it, pend);
			temp_num.assign(it, past_number);
			term = new Terminal(std::stoi(temp_num));
			tokens.push_back(term);
			it = past_number;
		}else{
			if(is_unary_add(it, start))
			{
				it++;
				continue;
			}
			if(is_negate(it, start))
			{
				non_term = new NonTerminal(NEG);
			}else{
				non_term = new NonTerminal(temp_c);
			};
			tokens.push_back(non_term);
			it++;
		}
	};
};

bool Scanner::is_unary_add(str_iter iter, str_iter start)
{
	return *iter == '+' && (iter == start || *std::next(iter, -1) == '(' || *std::next(iter, 1) == ')');
};

bool Scanner::is_negate(str_iter iter, str_iter start)
{
	return *iter == '-' && (iter == start || *std::next(iter, -1) == '(' );
}

str_iter Scanner::find_past_number(str_iter num_p, str_iter pend)
{
	str_iter start = num_p;
	char c = *start;

	while(start != pend && std::isdigit(c))
	{
		start++;
		c = *start;
	};

	return start;
};