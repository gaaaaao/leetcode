#include <iostream>
#include <vector>
#include <string>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		string expression = "-4/1";
		fractionAddition(expression);
	}
private:
	string fractionAddition(string expression) {
		vector<int> denominator;
		vector<int> numerator;
		string res;
		if (expression[0] != '-')
			expression = "+" + expression;
		int i = 0;
		while (i<expression.length())
		{
			int simbol = 1;
			int temp = 0;
			if (expression[i] == '-')
				simbol = -1;
			i++;
			while (expression[i] != '/')
			{
				temp *= 10;
				temp += expression[i] - '0';
				i++;
			}
			temp = temp*simbol;
			numerator.push_back(temp);
			i++;
			temp = 0;
			while (i < expression.length() && expression[i] != '-' && expression[i] != '+')
			{
				temp *= 10;
				temp += expression[i] - '0';
				i++;
			}
			denominator.push_back(temp);
		}
		int L = lcm(denominator);
		int sum = 0;
		for (int i = 0; i < numerator.size(); i++)
		{
			sum += numerator[i] * (L / denominator[i]);
		}
		if (sum%L == 0)
		{
			if (sum < 0)
			{
				res += '-';
				sum = 0 - sum;
			}
			int ret = sum / L;
			if (ret == 0)
				res += '0';
			else
			{
				while (ret)
				{
					res += (char)((ret % 10) + '0');
					ret /= 10;
				}
			}
			res += "/1";
		}
		else
		{
			if (sum < 0)
			{
				res += '-';
				sum = 0 - sum;
			}
			int g = gcd(sum, L);
			sum = sum / g;
			L = L / g;
			string rn;
			while (sum)
			{
				rn = (char)((sum % 10) + '0') + rn;
				sum /= 10;
			}
			res += rn+"/";
			string rd;
			while (L)
			{
				rd = (char)((L % 10) + '0') + rd;
				L /= 10;
			}
			res += rd;
		}
		return res;
	}
	int lcm(vector<int> denominator)
	{
		int temp = denominator[0];
		for (int i = 1; i<denominator.size(); i++)
		{
			int a = temp;
			int b = denominator[i];
			if (b > a)
				swap(a, b);
			while (b)
			{
				int t = 0;
				t = b;
				b = a%b;
				a = t;
			}
			temp = temp*denominator[i] / a;
		}
		return temp;
	}
	int gcd(int a, int b)
	{
		if (b > a)
			swap(b, a);
		while (b) 
		{
			int t = 0;
			t = b;
			b = a%b;
			a = t;
		}
		return a;
	}
};