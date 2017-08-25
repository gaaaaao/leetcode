#include <iostream>
#include <string>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		detectCapitalUse("FlaG");
	}
private:
	bool detectCapitalUse(string word) {
		if (word.length() <= 1)
			return true;
		if (word[0] < 'A' || (word[0] >= 'A' && word[1]<'A'))
		{
			for (int i = 1; i<word.length(); i++)
			{
				if (word[i] > 'z')
					return false;
			}
		}
		else
		{
			for (int i = 1; i<word.length(); i++)
			{
				if (word[i] < 'A')
					return false;
			}
		}
		return true;
	}
};