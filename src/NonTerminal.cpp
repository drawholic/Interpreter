#include "NonTerminal.hpp"

NonTerminal::NonTerminal()
{
	op = NONE;
	left = NULL;
	right = NULL;
};

bool NonTerminal::is_term()
{
	return false;
}

void NonTerminal::set_left(AbstractExpression* l ){
	left = l;
}

void NonTerminal::set_right(AbstractExpression* r){
	right = r;
}

Operator NonTerminal::get_op()
{
	return op;
};

NonTerminal::NonTerminal(
	AbstractExpression* _left,
	AbstractExpression* _right, 
	Operator _op)
{
	left = _left;
	right = _right;
	op = _op;
};

NonTerminal::NonTerminal(Operator _op){
	left = NULL;
	right = NULL;
	op = _op;
};

NonTerminal::NonTerminal(std::string& str)
{
	op = pick_op(str);
	left = NULL,
	right = NULL;
};

NonTerminal::NonTerminal(char& c)
{
	op = pick_op(c);
	left = NULL,
	right = NULL;
};


void NonTerminal::print()
{
	std::cout << "NonTerminal: left = ";
	
	if(left == NULL)
	{
		std::cout << "NULL";
	}else
	{
		std::cout << left->interpret();
	};

	std::cout << ", right = ";
	
	if(right == NULL)
	{
		std::cout << "NULL";
	}else
	{
		std::cout << right->interpret();
	};
	
	std::cout << ", op = ";
	
	print_operator();

	std::cout << std::endl;

};

void NonTerminal::print_operator()
	{
		switch(op)
		{
		case ADD: std::cout << "+"; break;
		case SUB: std::cout << "-"; break;
		case MUL: std::cout << "*"; break;
		case DIV: std::cout << "/"; break;
		case POW: std::cout << "^"; break;
		case LP: std::cout << "("; break;
		case RP: std::cout << ")"; break;
		case NEG: std::cout << "_"; break;

		case NONE: std::cout << "NONE"; break;
	}
};

value_type NonTerminal::interpret()
{
	value_type res;
	value_type left_res = left == NULL ? 0 : left->interpret();
	value_type right_res = right == NULL ? 0 : right->interpret();

	switch(op)
	{
	case ADD: res = left_res + right_res; break; 
	case SUB: res = left_res - right_res; break;

	case MUL: res = left_res * right_res; break;
	case DIV: res = left_res / right_res; break;

	case POW: res = std::pow(left_res, right_res); break;

	case NEG: res = -right_res;

	case LP: break;
	case RP: break;

	};

	return res;
};

Operator NonTerminal::pick_op(std::string& str_op)
{
	switch(str_op[0])
	{
		case '+': return ADD; break;
		case '-': return SUB; break;
		case '*': return MUL; break;
		case '/': return DIV; break;
		case '^': return POW; break;
		case '(': return LP; break;
		case ')': return RP; break;
		case '_': return NEG; break;
		default: return NONE; break;
	}
};

Operator NonTerminal::pick_op(char& char_op)
{
	switch(char_op)
	{
		case '+': return ADD; break;
		case '-': return SUB; break;
		case '*': return MUL; break;
		case '/': return DIV; break;
		case '^': return POW; break;
		case '(': return LP; break;
		case ')': return RP; break;
		case '_': return NEG; break;

		default: return NONE; break;
	}
};


NonTerminal::~NonTerminal()
{

};

bool NonTerminal::empty()
{
	return left == NULL && right == NULL;
};