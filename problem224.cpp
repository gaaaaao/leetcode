#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Basic_Calculator
{
public:
	void adpator()
	{
		string s = "3-(5+2)-(3-6)";
		cout << calculate(s) << endl;
	}
private:
	int calculate(string s) {
		s = init(s);

		int len = s.length();
		vector<int> opnums;
		get(s, opnums);
		long sum = opnums[0];
		stack<int> res;
		for (int i = 0; i < opnums.size(); i++)
		{
			if (opnums[i] >= 0)
				res.push(opnums[i]);
			else
			{
				int temp = res.top();
				res.pop();
				if (opnums[i] == -45)
				{
					res.top() = res.top() - temp;
				}
				else if (opnums[i] == -43)
				{
					res.top() = res.top() + temp;
				}
			}
		}
		return res.top();
	}
	string init(string s)
	{
		int len = s.length();

		for (int i = 0; i<len; i++)
		{
			if (s[i] == ' ')
			{
				s.erase(i, 1);
				len--;
				i--;
			}

		}
		return s;
	}
	
	void get(string &s, vector<int> &nums)
	{
		stack<char> op;
		
		int len = s.length();
		
		for (int i = 0; i < len;)
		{
			if (s[i] > 47 && s[i] < 58)
			{
				int temp = 0;
				while (s[i] > 47 && s[i] < 58)
				{
					temp = temp * 10 + s[i] - 48;
					i++;
				}
				nums.push_back(temp);
			}
			else if (s[i] == '(')
			{
				op.push(s[i]);
				i++;
			}
			else if(s[i] == ')')
			{
				while (op.top() != '(')
				{
					nums.push_back(-1 * op.top());
					op.pop();
				}
				op.pop();
				i++;
			}
			else
			{
				while (!op.empty() && op.top() != '(')
				{
					nums.push_back(-1 * op.top());
					op.pop();
				}
				op.push(s[i]);
				i++;
			}
			
		}
		while (!op.empty())
		{
			if (op.top() == '(')
				throw '(';
			nums.push_back(-1 * op.top());
			op.pop();
		}

	}
};