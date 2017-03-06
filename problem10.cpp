#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Regular_Expression_Matching {
public:
	void adaptor();
private:
	bool isMatch(string s, string p);
	string LCS(string s, string p);
};

inline void Regular_Expression_Matching::adaptor()
{
	cout << isMatch("aa", ".a") << endl;
}

inline bool Regular_Expression_Matching::isMatch(string s, string p)
{
	if (p.empty()) return s.empty();
	if (p.size() == 1) {
		return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
	}
	if (p[1] != '*') {
		if (s.empty()) return false;
		return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1));
	}
	while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
		if (isMatch(s, p.substr(2))) return true;
		s = s.substr(1);
	}
	return isMatch(s, p.substr(2));
}

inline string Regular_Expression_Matching::LCS(string s, string p)
{
	vector<char> ss(s.length()+1);
	vector<char> pp(p.length()+1);
	vector<vector<int> > LCS(s.length()+1, vector<int>(p.length()+1));
	vector<int> rec(ss.size());
	int count = 0;
	string result;
	string temp;

	for (int i = 0; i < ss.size(); i++)
	{
		rec[i] = -1;
	}

	for (int i = 1; i <= s.length(); i++)
	{
		ss[i] = s[i-1];
	}

	for (int i = 1; i <= p.length(); i++)
	{
		pp[i] = p[i-1];
	}

	for (int i = 1; i < LCS.size(); i++)
	{
		for (int j = 1; j < LCS[i].size(); j++)
		{
			if (ss[i] == pp[j])
			{
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			}
			else
			{
				LCS[i][j] = LCS[i - 1][j] > LCS[i][j - 1] ? LCS[i - 1][j] : LCS[i][j - 1];
			}
		}
	}
	
	for (int i = 0; i < LCS.size(); i++)
	{
		for (int j = 0; j < LCS[i].size(); j++)
		{
			cout << LCS[i][j] << "\t";
		}
		cout << endl;
	}

	int m = ss.size()-1;
	int n = pp.size()-1;
	
	while(m != 0 && m != 0)
	{
		if (ss[m] == pp[n])
		{
			result = ss[m] + temp;
			temp = result;
			m--;
			n--;
		}
		else
		{
			if (LCS[m - 1][n] != LCS[m][n - 1])
			{
				LCS[m - 1][n] > LCS[m][n - 1] ? m-- : n--;
			}
			else
			{
				n--;
			}
		}
	}

	return result;
}
