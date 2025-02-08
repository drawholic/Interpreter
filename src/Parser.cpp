#include "Parser.hpp"

Parser::Parser()
{

};

void Parser::build_tree(token_list& tokens)
{
	parse_mul_div(tokens);
	parse_add_sub(tokens);
};

void Parser::parse_add_sub(token_list& tokens)
{
	NonTerminal* elem;
	exp_iter left;
	exp_iter right;

	exp_iter it = tokens.begin();
	exp_iter pend = tokens.end();

	while(it != pend)
	{
		it = std::find_if(it, pend, is_add_sub);
		
		if(it == pend)
			return;

		elem = dynamic_cast<NonTerminal*>(*it);
		
		left = std::next(it, -1);
		right = std::next(it, 1);

		elem->set_left(*left);
		elem->set_right(*right);

		it = tokens.erase(left, std::next(right, 1));
		 
		tokens.insert(it, elem); 
	}
};

void Parser::parse_mul_div(token_list& tokens)
{
	NonTerminal* elem;
	exp_iter left;
	exp_iter right;

	exp_iter it = tokens.begin();
	exp_iter pend = tokens.end();

	while(it != pend)
	{
		it = std::find_if(it, pend, is_mul_div);
		
		if(it == pend)
			return;

		elem = dynamic_cast<NonTerminal*>(*it);
		
		left = std::next(it, -1);
		right = std::next(it, 1);

		elem->set_left(*left);
		elem->set_right(*right);

		it = tokens.erase(left, std::next(right, 1));
		 
		tokens.insert(it, elem); 
	}
};

void Parser::parse_parentheses(token_list&)
{

};

bool Parser::is_add_sub(AbstractExpression* exp)
{
	bool res = false;
	if(!exp->is_term())
	{	
		NonTerminal* non_term = dynamic_cast<NonTerminal*>(exp);
		Operator op = non_term->get_op();
		res =  non_term->empty() && (op == ADD || SUB == op);
	}	
	return res;

};

bool Parser::is_mul_div(AbstractExpression* exp)
{
	bool res = false;
	if(!exp->is_term())
	{	
		NonTerminal* non_term = dynamic_cast<NonTerminal*>(exp);
		Operator op = non_term->get_op();
		res =  non_term->empty() && (op == MUL || DIV == op);
	}	
	return res;

};


