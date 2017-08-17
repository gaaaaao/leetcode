#include <iostream>
#include <string>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		multiply("123", "456");
	}
private:
	string multiply(string num1, string num2) {
		int carry = 0;
		string res;
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		for (int i = 0; i < num1.length(); i++)
		{
			int p = i;
			for (int j = 0; j <num2.length(); j++)
			{
				int temp = (num1[i] - '0')*(num2[j] - '0') + carry;
				if (p < res.length())
				{
					temp = temp + (res[p] - '0');
					res[p] = (char)temp % 10+'0';
				}
				else
				{
					res += (char)(temp % 10 + '0');
				}
				carry = temp / 10;
				p++;
			}
			if (carry > 0)
				res += (char)(carry + '0');
			carry = 0;
		}
		reverse(res.begin(),res.end());
		return res;
	}
};