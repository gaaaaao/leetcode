#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class solution
{
public:
	void adaptor()
	{
		cout << wordPattern("abbc", "dog cat cat dog") << endl;
	}
private:
	bool wordPattern(string pattern, string str)
	{
		int lenstr = str.length();
		vector<string> t;
		t.push_back("");
		for (int i = 0; i<lenstr; i++)
		{
			if (str[i] != ' ')
			{
				t.back() += str[i];
			}
			else
			{
				t.push_back("");
			}
		}
		string s = pattern;
		map<char, string> ss;
		map<string, char> tt;

		int lens = s.length();
		int lent = t.size();

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