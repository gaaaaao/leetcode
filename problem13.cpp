#include <iostream>

using namespace std;

class Roman_to_Integer
{
public:
	void adaptor();
private:
	int romanToInt(string s);
};

inline void Roman_to_Integer::adaptor()
{
	cout << romanToInt("MMMCMXCIX") << endl;
	cout << romanToInt("I") << endl;
	cout << romanToInt("IV") << endl;
	cout << romanToInt("M") << endl;

}

inline int Roman_to_Integer::romanToInt(string s)
{
	s = '#' + s + '#';
	int result = 0;
	for (int i = s.length(); i > 0; i--)
	{
		if (s[i] == 'I')
			result++;
		else if (s[i] == 'V')
		{
			if (s[i - 1] != 'I')
				result += 5;
			else
			{
				result += 4;
				i--;
			}
		}
		else if (s[i] == 'X')
		{
			if (s[i - 1] != 'I')
				result += 10;
			else
			{
				result += 9;
				i--;
			}
		}
		else if (s[i] == 'L')
		{
			if (s[i - 1] != 'X')
				result += 50;
			else
			{
				result += 40;
				i--;
			}
		}
		else if (s[i] == 'C')
		{
			if (s[i - 1] != 'X')
				result += 100;
			else
			{
				result += 90;
				i--;
			}
		}
		else if (s[i] == 'D')
		{
			if (s[i - 1] != 'C')
				result += 500;
			else
			{
				result += 400;
				i--;
			}
		}
		else if (s[i] == 'M')
		{
			if (s[i - 1] != 'C')
				result += 1000;
			else
			{
				result += 900;
				i--;
			}
		}
	}
	return result;
}
