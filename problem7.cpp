#include<iostream>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

class Reverse_Integer
{
public:
	void adaptor();
private:
	int reverse(int x);
};

inline void Reverse_Integer::adaptor()
{
	cout << reverse(1534236469) << endl;
}

inline int Reverse_Integer::reverse(int x)
{
	vector<int> num;
	int sign = 1;
	string numx = to_string(x);
	long long result=0;

	for (int i = 0; i < numx.length(); i++)
	{
		if (numx[i] != '-')
			num.push_back(numx[i]-'0');
		else
			sign = 0;
	}

	for (int i = num.size()-1; i >= 0; i--)
	{
		result += pow(10,i) * num.at(i);
	}

	if (sign == 0)
		result *= -1;

	if (result > 2147483647 || result < -2147483648)
		return 0;

	return result;
}
