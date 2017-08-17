#include <iostream>
#include <string>
#include <vector>
using namespace std;

class solution
{
public:
	void adaptor()
	{
		string s = "abacababacab";
		cout << repeatedSubstringPattern(s) << endl;
	}
private:
	bool repeatedSubstringPattern(string s) {
		int len = s.length();
		vector<int> next(len, 0);
		for (int i = 1; i < len; i++)
		{
			int k = next[i - 1];
			while (s[i] != s[k] && k)
				k = next[k - 1];
			if (s[i] == s[k])
				next[i] = k + 1;
		}
		int p = next[len - 1];
		return (p > 0) && (len % (len - p) == 0);
	}
};