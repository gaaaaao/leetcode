#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Valid_Parentheses
{
public:
	void adaptor();
private:
	bool isValid(string s);
};

inline void Valid_Parentheses::adaptor()
{
	string s = "()";
	cout << isValid(s) << endl;
}

inline bool Valid_Parentheses::isValid(string s)
{
	int len = s.length();
	int i;
	stack<char> Pare;

	for (i = 0; i < len; i++)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			Pare.push(s[i]);
		else if (!Pare.empty())
		{
			if (s[i] == ')' && Pare.top() == '(')
				Pare.pop();
			else if(s[i] == ']' && Pare.top() == '[')
				Pare.pop();
			else if (s[i] == '}' && Pare.top() == '{')
				Pare.pop();
			else
				return false;
		}
		else
			return false;
	}
	
	if (!Pare.empty())
		return false;

	return true;
}
