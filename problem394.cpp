#include <iostream>
#include <stack>
#include <string>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		string s = "2[abc]3[cd]ef";
		decodeString(s);
	}
private:
	string decodeString(string s) {
		stack<int> times;
		stack<string> sen;
		for (int i = 0; i<s.size(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
				times.push(getNum(s, i));
			else if (s[i] != ']')
			{
				sen.push(string(1,s[i]));
			}
			else
			{
				string ss = "";
				string r = "";
				while (sen.top() != "[")
				{
					ss = sen.top()+ss;
					sen.pop();
				}
				sen.pop();
				int t = times.top();
				times.pop();
				while (t>0)
				{
					r += ss;
					t--;
				}
				sen.push(r);
			}
		}
		string res = "";
		while (!sen.empty())
		{
			res = sen.top() + res;
			sen.pop();
		}
		return res;
	}
	int getNum(string s, int & pos)
	{
		int num = 0;
		while (pos < s.size() && s[pos] >= '0' && s[pos] <= '9')
		{
			num *= 10;
			num += s[pos] - '0';
			pos++;
		}
		pos--;
		return num;
	}
};