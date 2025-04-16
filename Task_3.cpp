#include "Stack.h"
#include <Windows.h>
#include <string>

int precedence(char op)
{
	if (op == '(' || op == ')' || op == '{' || op == '}' || op == '[' || op == ']')
		return 3;
	else if (op == '*' || op == '/' || op == '%')
		return 2;
	else if (op == '+' || op == '-')
		return 1;
	return 0;
}

string infixtoprefix(string exp)
{
	stack<char> s(100);
	string processedSignal = "";
	char temp{};

	reverse(exp.begin(), exp.end());
	for (int i = 0; exp[i] != '\0'; i++)
	{
		if (precedence(exp[i]) == 3 && (exp[i] == '(' || exp[i] == '[' || exp[i] == '{'))
		{
			for (temp = s.pop(); temp != ')' && temp != ']' && temp != '}'; temp = s.pop())
				processedSignal += temp;
		}
		else if (precedence(exp[i]) == 3)
			s.push(exp[i]);
		else if (precedence(exp[i]) == 2)
		{
			if (precedence(temp = s.pop()) == 2)
				processedSignal += temp;
			else
				s.push(temp);
			s.push(exp[i]);
		}
		else if (precedence(exp[i]) == 1)
		{
			if (!s.isempty())
			{
				for (temp = s.pop(); precedence(temp) == 2 || precedence(temp) == 1; temp = s.pop())
					processedSignal += temp;
				s.push(temp);
			}
			s.push(exp[i]);
		}
		else
			processedSignal += exp[i];
	}

	while (temp = s.pop())
		processedSignal += temp;

	reverse(processedSignal.begin(), processedSignal.end());

	return processedSignal;
}

int main()
{
	string exp = "((a+b)*(c%d)-(e/f+g))+(h*(i-j/k))";
	
	cout << "Input  :: " << exp << endl;
	cout << "Output :: " << infixtoprefix(exp) << endl;
	return 0;
}
