#pragma once
#include <sstream>
#include <cctype>
#include "ExpressionManagerInterface.h"
using namespace std;

const string OPEN = "([{";
const string CLOSE = ")]}";
const string OPERATORS = "+-*/%()";
const int PRECEDENCE[] = { 1, 1, 2, 2, 2, -1, -1 };

class ExpressionManager : public ExpressionManagerInterface
{
public:
	ExpressionManager();
	~ExpressionManager();

	bool isBalanced(string expression);
	string postfixToInfix(string postfixExpression);
	string postfixEvaluate(string postfixExpression);
	string infixToPostfix(string infixExpression);
	bool is_open(char c);
	bool is_close(char c);

protected:
	string expression;
	string postfixExpression;
	string infixExpression;
	char c;
	char op;
	bool is_op(char c) const;
	int precedence(char op) const;
	int eval_op(char op);
	void process_operator(char op);
	stack<string> opand_stack;
	stack<int> operand_stack;
	stack<char> operator_stack;
};


