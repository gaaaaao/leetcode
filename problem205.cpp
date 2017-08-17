#include <iostream>
#include <map>
#include <string>
using namespace std;

class solution
{
public:
	void adaptor()
	{
		cout << isIsomorphic("ab", "aa") << endl;
	}
private:
	bool isIsomorphic(string s, string t)
	{
		map<char, char> ss;
		map<char, char> tt;
		
		int lens = s.length();
		int lent = t.length();

		if (lens != lent)
			return false;
		else if (lens == 0)
			return true;

		for (int i = 0; i < lens; i++)
		{
			
			if (ss.find(s[i]) == ss.end() && tt.find(t[i]) == tt.end())
			{
				ss[s[i]] = t[i];
				tt[t[i]] = s[i];
			}
			else if (ss.find(s[i]) != ss.end() && tt.find(t[i]) != tt.end())
			{
				if (ss[s[i]] == t[i] && tt[t[i]] == s[i])
					continue;
				else
					return false;
			}
			else
				return false;
				
		}
		return true;
	}
};