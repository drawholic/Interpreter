#include "Parser.hpp"

Parser::Parser()
{

};

void Parser::build_tree(token_list& tokens)
{
	parse_parentheses(tokens);
	parse_power(tokens);
	parse_unary(tokens);

	parse_mul_div(tokens);
	parse_add_sub(tokens);
};

void Parser::parse_unary(token_list& tokens)
{
	NonTerminal* elem;
	exp_iter left;
	exp_iter right;

	exp_iter it = tokens.begin();
	exp_iter pend = tokens.end();

	while(it != pend)
	{
		it = std::find_if(it, pend, is_unary);
		
		if(it == pend)
			return;

		elem = dynamic_cast<NonTerminal*>(*it);
		
		right = std::next(it, 1);

		elem->set_right(*right);

		it = tokens.erase(it, std::next(right, 1));
		 
		tokens.emplace(it, elem); 
	}
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

void Parser::parse_power(token_list& tokens)
{
	NonTerminal* elem;
	exp_iter left;
	exp_iter right;

	exp_iter it = tokens.begin();
	exp_iter pend = tokens.end();

	while(it != pend)
	{
		it = std::find_if(it, pend, is_power);
		
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

 
void Parser::parse_parentheses(token_list& tokens)
{
    exp_iter lp = tokens.begin();
    exp_iter rp;
    exp_iter pend = tokens.end();
    
    while (lp != pend) {
        lp = std::find_if(lp, pend, is_left_parenthesis);
        if (lp == pend)
            break;

        unsigned counter = 1;
        exp_iter it = std::next(lp);
        exp_iter match = lp;

        while (it != pend) {
            if (is_left_parenthesis(*it)) {
                counter++;
            } else if (is_right_parenthesis(*it)) {
                counter--;
                if (counter == 0) {
                    match = it;
                    break;
                }
            }
            ++it;
        }

        if (counter != 0)
            return;  

        token_list sub_list(std::next(lp), match);
        parse_parentheses(sub_list);
        parse_unary(sub_list);
        parse_power(sub_list);
        parse_mul_div(sub_list);
        parse_add_sub(sub_list);

        tokens.splice(lp, sub_list);
        lp = tokens.erase(lp, std::next(match, 1));  
    }
}


bool Parser::is_left_parenthesis(AbstractExpression* exp){
	bool res = false;

	if(!exp->is_term())
	{
		NonTerminal* non_term = dynamic_cast<NonTerminal*>(exp);
		Operator op = non_term->get_op();
		res =  non_term->empty() && op == LP;
	};
	return res;
};
bool Parser::is_right_parenthesis(AbstractExpression* exp){
	bool res = false;

	if(!exp->is_term())
	{
		NonTerminal* non_term = dynamic_cast<NonTerminal*>(exp);
		Operator op = non_term->get_op();
		res =  non_term->empty() && op == RP;
	};
	return res;
};
bool Parser::is_parenthesis(AbstractExpression* exp){
	bool res = false;

	if(!exp->is_term())
	{
		NonTerminal* non_term = dynamic_cast<NonTerminal*>(exp);
		Operator op = non_term->get_op();
		res =  non_term->empty() && (op == LP || op == RP);
	};
	return res;
};

bool Parser::is_power(AbstractExpression* exp){
	bool res = false;

	if(!exp->is_term())
	{
		NonTerminal* non_term = dynamic_cast<NonTerminal*>(exp);
		Operator op = non_term->get_op();
		res =  non_term->empty() && op == POW ;
	};
	return res;
};

bool Parser::is_add_sub(AbstractExpression* exp){
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

bool Parser::is_unary(AbstractExpression* exp)
{
	bool res = false;
	if(!exp->is_term())
	{
		NonTerminal* non_term = dynamic_cast<NonTerminal*>(exp);
		Operator op = non_term->get_op();
		res = non_term->empty() && op == NEG;
	};
	return res;
};
