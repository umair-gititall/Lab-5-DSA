#include "Stack.h"
#include <string>

bool test(string val)
{
	if (strlen(val.c_str()) == 0)
		return false;

	for (int i = 0; val[i] != '\0'; i++)
		if (!(val[i] >= '0' && val[i] <= '9'))
			return false;
	return true;
}
int evaluatepost(string exp)
{
	stack <string>s(100);
	string temp = "";

	for (int i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == ' ')
		{
			if (test(temp))
				s.push(temp);
			temp = "";
		}
		else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '*' || exp[i] == '%')
		{
			int val2 = stoi(s.pop());
			int val1 = stoi(s.pop());

			if (exp[i] == '+')
				s.push(to_string(val1 + val2));
			else if (exp[i] == '-')
				s.push(to_string(val1 - val2));
			else if (exp[i] == '/')
				s.push(to_string(val1 / val2));
			else if (exp[i] == '*')
				s.push(to_string(val1 * val2));
			else if (exp[i] == '%')
				s.push(to_string(val1 % val2));
		}
		else if (exp[i] >= '0' && exp[i] <= '9')
			temp += exp[i];
	}
	return stoi(s.pop());
}

int main()
{
	string exp = " 6 3 + 2 *";

	cout << "result :: " << evaluatepost(exp);
	return 0;
}