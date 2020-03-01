#include "ExpressionManager.h"

ExpressionManager::ExpressionManager()
{}
	

ExpressionManager::~ExpressionManager()
{
}

bool ExpressionManager::isBalanced(string expression)
{
	stack<char> s;
	bool balance = true;
	string::const_iterator it = expression.begin();
	while (balance && (it != expression.end()))
	{
		char next_c = *it;
		if (is_open(next_c))
		{
			s.push(next_c);
		}
		else if (is_close(next_c))
		{
			if (s.empty())
			{
				balance = false;
			}
			else {
				char top_c = s.top();
				s.pop();
				balance =
					OPEN.find(top_c) == CLOSE.find(next_c);
			}
		}
		++it;
	}
	return balance && s.empty();
}

string ExpressionManager::postfixToInfix(string postfixExpression)
{
	infixExpression = "";
	
	while (!opand_stack.empty())
	{
		opand_stack.pop();
	}

	stringstream inputs(postfixExpression);
	string next_c;
	while (inputs >> next_c)
	{
		if (isdigit(next_c[0]))
		{
			int i = stoi(next_c);
			string digit = to_string(i);
			if (next_c == digit)
			{
				opand_stack.push(next_c);
			}
			else if (next_c != digit)
			{
				return "invalid";
			}
		}
		else if (is_op(next_c[0]) && !opand_stack.empty())
		{
			string rh = opand_stack.top();
			opand_stack.pop();
			if (opand_stack.empty())
			{
				return "invalid";
			}
			else if (!opand_stack.empty())
			{
				string lh = opand_stack.top();
				opand_stack.pop();
				stringstream ss;
				ss << "(" << " " << lh << " " << next_c << " " << rh << " " << ")";
				string new_result = ss.str();
				opand_stack.push(new_result);
			}
		}
		else if (next_c[0] == '.')
		{
			return "invalid";
		}
		else {
			return "invalid";
		}
	}
	if (!opand_stack.empty())
	{
		infixExpression = opand_stack.top();
		opand_stack.pop();
		if (opand_stack.empty())
		{
			return infixExpression;
		}
		else {
			return "invalid";
		}
	}
	else {
		return "invalid";
	}
}

string ExpressionManager::postfixEvaluate(string postfixExpression)
{
	while (!operand_stack.empty())
	{
		operand_stack.pop();
	}

	istringstream tokens(postfixExpression);
	char next_c;
	while (tokens >> next_c)
	{
		if (isdigit(next_c))
		{
			tokens.putback(next_c);
			int value;
			tokens >> value;
			operand_stack.push(value);
		}
		else if (is_op(next_c) && !operand_stack.empty())
		{
			int result = eval_op(next_c);

			if (result == -999)
			{
				return "invalid";
			}
			else if (result != -999)
			{
				operand_stack.push(result);
			}
		}
		else {
			return "invalid";
		}
	}
	if (!operand_stack.empty())
	{
		int answer = operand_stack.top();
		operand_stack.pop();
		if (operand_stack.empty())
		{
			return to_string(answer);
		}
	}
}

string ExpressionManager::infixToPostfix(string infixExpression)
{
	postfixExpression = "";
	while (!operator_stack.empty())
	{
		operator_stack.pop();
	}
	istringstream infix_tokens(infixExpression);
	string next_token;
	int d = 0;
	int o = 0;
	while (infix_tokens >> next_token)
	{
		if (isdigit(next_token[0]))
		{
			int i = stoi(next_token);
			string digit = to_string(i);
			if (next_token == digit)
			{
				postfixExpression += next_token;
				postfixExpression += " ";
			}
			else if (next_token != digit)
			{
				return "invalid";
			}
		}
		else if (is_op(next_token[0]))
		{
			process_operator(next_token[0]);
		}
		else {
			return "invalid";
		}
	}
	while (!operator_stack.empty())
	{
		char op = operator_stack.top();
		operator_stack.pop();
		if (op == '(')
		{
			return "invalid";
		}
		postfixExpression += op;
		postfixExpression += " ";
	}
	postfixExpression = postfixExpression.substr(0, postfixExpression.size()-1);

	stringstream sst(postfixExpression);
	string post_ch;
	while (sst >> post_ch)
	{
		if (isdigit(post_ch[0]))
		{
			d++;
		}
		else if (is_op(post_ch[0]))
		{
			o++;
		}
	}

	if (d > o)
	{
		return postfixExpression;
	}
	else if (d <= o)
	{
		return "invalid";
	}
}

bool ExpressionManager::is_open(char c)
{
	return OPEN.find(c) != string::npos;
}

bool ExpressionManager::is_close(char c)
{
	return CLOSE.find(c) != string::npos;
}

bool ExpressionManager::is_op(char c) const
{
	return OPERATORS.find(c) != string::npos;
}

int ExpressionManager::eval_op(char op)
{
	int rhs = operand_stack.top();
	operand_stack.pop();
	int lhs = operand_stack.top();
	operand_stack.pop();
	int result = 0;

	if (op == '+')
	{
		result = lhs + rhs;
		return result;
	}
	else if (op == '-')
	{
		result = lhs - rhs;
		return result;
	}
	else if (op == '*')
	{
		result = lhs * rhs;
		return result;
	}
	else if (op == '/')
	{
		if (rhs == 0)
		{
			result = -999;
			return result;
		}
		else
		{
			result = lhs / rhs;
			return result;
		}
	}
	else if (op == '%')
	{
		if (rhs == 0)
		{
			result = -999;
			return result;
		}
		else
		{
			result = lhs % rhs;
			return result;
		}
	}
}

void ExpressionManager::process_operator(char op)
{
	if (operator_stack.empty() || (op == '('))
	{
		if (op == ')')
		{
			cout << "invalid";
		}
		operator_stack.push(op);
	}
	else
	{
		if (precedence(op) > precedence(operator_stack.top()))
		{
			operator_stack.push(op);
		}
		else
		{
			while (!operator_stack.empty() && (operator_stack.top() != '(') && (precedence(op) <= precedence(operator_stack.top())))
			{
				postfixExpression += operator_stack.top();
				postfixExpression += " ";
				operator_stack.pop();
			}
			if (op == ')')
			{
				if (!operator_stack.empty() && (operator_stack.top() == '('))
				{
					operator_stack.pop();
				}
				else
				{
					cout << "invalid";
				}
			}
			else
			{
				operator_stack.push(op);
			}
		}
	}
}

int ExpressionManager::precedence(char op) const
{
	return PRECEDENCE[OPERATORS.find(op)];
}

