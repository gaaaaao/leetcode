#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Integer_to_Roman
{
private:
	string intToRoman(int num);
public:
	void adaptor();
};

inline string Integer_to_Roman::intToRoman(int num)
{
	if (num == 0)
		return "";
	string result;
	stack<int> digit;
	char Inter[4] = { 'I', 'X','C','M' };
	char Hal[3] = { 'V','L','D' };

	{
		int currentdigit = 0;
		while (num != 0)
		{
			currentdigit = num % 10;
			digit.push(currentdigit);
			num /= 10;
		}

	}

	while (!digit.empty())
	{
		if (digit.top() < 4)
		{
			for (int i = 0; i < digit.top(); i++)
			{
				result += Inter[digit.size() - 1];
			}
		}
		else if (digit.top() == 4)
		{
			result = result + Inter[digit.size() - 1] + Hal[digit.size() - 1];
		}
		else if (digit.top() < 9 && digit.top() >= 5)
		{
			result += Hal[digit.size() - 1];
			for (int i = 5; i < digit.top(); i++)
			{
				result += Inter[digit.size() - 1];
			}
		}
		else if (digit.top() == 9)
		{
			result = result + Inter[digit.size() - 1] + Inter[digit.size()];
		}
		digit.pop();
	}
	
	return result;
}

inline void Integer_to_Roman::adaptor()
{
	cout << intToRoman(1843) << endl;
	cout << intToRoman(1) << endl;
	cout << intToRoman(0) << endl;
	cout << intToRoman(3999) << endl;
	cout << intToRoman(100) << endl;
	cout << intToRoman(1545) << endl;
}
