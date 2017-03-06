#include<iostream>
#include<string>
#include<vector>

#define MAX (2147483647)
#define MIN (-2147483648)

using namespace std;

class String_to_Integer
{
public:
	void adaptor();
private:
	int myAtoi(string str);
};

inline void String_to_Integer::adaptor()
{
	string s;
	//cin >> s;
	//while (s != "ss")
//	{
		cout << myAtoi("1234567890123456789012345678901234567890") << endl;
	//	cin >> s;
	//}
	
}

inline int String_to_Integer::myAtoi(string str)
{
	vector<int> value;
	int sign = 0;
	long long result1 = 0;
	long long result2 = 0;
	int signcou = 0;
	int signspa = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (signcou > 1)
		{
			value.clear();
			break;
		}

		if (str[i] >= '0' && str[i] <= '9')
		{
			value.push_back(str[i] - '0');
			signspa = 1;
		}
		else if (str[i] == '-')
		{
			signcou++;
			sign = sign ^ 1;
			signspa = 1;
		}
		else if (str[i] == '+')
		{
			signcou++;
			signspa = 1;
			continue;
		}
		else if (str[i] == ' ')
		{
			if (signspa == 0)
				continue;
			else
				break;
		}
		else
		{
			break;
		}
	}

	for (int i = 0; i < value.size(); i++)
	{
		if (i < 9)
			result1 += pow(10, i)*value.at(value.size() - 1 - i);
		else
			result2 += pow(10, i - 9)*value.at(value.size() - 1 - i);
		if (result2 > 10)
			break;
	}

	if (result2 <= 2)
	{
		if (sign == 1)
		{
			result1 *= -1;
			result2 *= -1;
		}

		if (result2 == 2 && result1 >= 147483647)
			result1 = 2147483647;
		else if (result2 == -2 && result1 <= -147483648)
			result1 = -2147483648;
		else
			result1 = result2 * 1000000000 + result1;
	}
	else
	{
		if (sign == 1)
			result1 = -2147483648;
		else
			result1 = 2147483647;
	}


	return result1;
}
