#include <iostream>
#include <string>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		string equation = "x+5-3+x=6+x-2";
		cout << solveEquation(equation) << endl;
	}
private:
	string solveEquation(string equation) {
		bool sign = false;

		for (int i = 0; i<equation.size(); i++)
		{
			if (equation[i] == '=')
			{
				if (equation[i + 1] == '-')
					equation.erase(i, 1);
				else
					equation[i] = '+';
				sign = true;
			}
			if (sign)
			{
				if (equation[i] == '+')
					equation[i] = '-';
				else if (equation[i] == '-')
					equation[i] = '+';
			}
		}
		if (equation[0] != '-')
			equation = "+" + equation;
		return process(equation);
	}
	string process(const string & equation)
	{
		int coefficient = 0;
		int constant = 0;

		for (int i = 0; i<equation.size();)
		{
			int temp = extract(equation, i);
			if (equation[i - 1] == 'x')
				coefficient += temp;
			else
				constant += temp;
		}
		if (coefficient == 0)
		{
			if (constant == 0)
				return "Infinite solutions";
			return "No solution";
		}
		return to_string(-1*constant / coefficient);
	}
	int extract(const string & equation, int & start)
	{
		int num = 0;
		bool sign = true;
		if (equation[start] == '-')
			sign = false;
		if (equation[start + 1] == 'x')
		{
			start += 2;
			return sign ? 1 : -1;
		}
		start++;

		for (; start < equation.size(); start++)
		{
			if (equation[start] == 'x')
			{
				start++;
				break;
			}
			else if (equation[start] == '-' || equation[start] == '+')
				break;
			num *= 10;
			num += equation[start] - '0';
		}
		return sign ? num : 0 - num;
	}
};