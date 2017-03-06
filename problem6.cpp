#include<iostream>
#include<string>

using namespace std;

class ZigZag
{
public:
	void adaptor();
private:
	string convert(string s, int numRows);
};

inline void ZigZag::adaptor()
{
	cout << convert("", 1);
}

inline string ZigZag::convert(string s, int numRows)
{
	int tail = 0;
	string result = "";
	int index = 0;

	if (numRows == 1)
	{
		return s;
	}
	else
	{
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < s.length() / (2 * numRows - 2) + 1; j++)
			{

				if (i == 0 || i == numRows - 1)
				{
					if (j*(2 * numRows - 2) + i < s.length())
						result += s[j*(2 * numRows - 2) + i];
				}
				else
				{
					if (j*(2 * numRows - 2) + i < s.length())
						result += s[j*(2 * numRows - 2) + i];
					if (j*(2 * numRows - 2) + 2 * numRows - i - 2 < s.length())
					{
						result += s[j*(2 * numRows - 2) + 2 * numRows - i - 2];
					}
				}


				index++;
			}
		}
		return result;
	}
	
}
