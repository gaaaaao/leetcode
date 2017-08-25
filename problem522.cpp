#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Cmp
{
	bool operator()(const string & a, const string & b) const
	{
		if (a.length() == b.length())
			return a > b;
		return a.length() > b.length();
	}
};

class solution
{
	bool judge(string s1, vector<string> & exis)
	{
		if (exis.empty())
			return true;
		for (auto e : exis)
		{
			for (int i = 0, j = 0; i<s1.size(); i++)
			{
				while (j<e.size() && s1[i] != e[j])
					j++;
				if (j == e.size())
					return true;
				j++;
			}
		}
		return false;
	}

public:
	void adaptor()
	{
		vector<string> strs = { "aabbcc", "aabbcc","cb","abc" };
		cout << findLUSlength(strs) << endl;
	}
private:
	int findLUSlength(vector<string>& strs) {
		map<string, int, Cmp> words;
		vector<string> existed;
		for (auto s : strs)
		{
			words[s]++;
		}
		for(auto iter:words)
		{
			bool jud = judge(iter.first, existed);
			if (iter.second == 1 && jud)
				return iter.first.length();
			else if (!jud)
			{
				continue;
			}
			else
			{
				existed.push_back(iter.first);
			}
		}
		return -1;
	}
};