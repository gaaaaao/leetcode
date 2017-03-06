#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

class Generate_Parentheses
{
public:
	void adaptor();
private:
	vector<int> pt;
	vector<string> generateParenthesis(int n);
	void iter(vector<string>& res, string s, int n, int l, int r);
};

inline void Generate_Parentheses::adaptor()
{
	vector<string> res = generateParenthesis(4);

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << "\t";
	}
	cout << endl;
}

inline vector<string> Generate_Parentheses::generateParenthesis(int n)
{
	vector<string> res;
	iter(res, "", n, 0, 0);
	return res;
}

inline void Generate_Parentheses::iter(vector<string>& res, string s, int n, int l, int r)
{
	if (s.length() == 2 * n)
	{
		res.push_back(s);
		return;
	}
	if (l < n)
	{
		iter(res, s + "(", n, l + 1, r);
	}
	if (r+1 <= l)
		iter(res, s + ")", n, l, r + 1);
}

