#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Palindromic_Substring
{
private:
	string longestPalindrome(string s);
public:
	void adaptor();
};

inline string Palindromic_Substring::longestPalindrome(string s)
{
	string ss = "$" + s + "&";
	vector<char> op_s;
	vector<int> p(3000, 1);
	int center = 0;
	int lright_edge = 0;
	int max_center = 0;
	vector<char> result;

	//preprocessing string
	for (int i = 0; i < ss.length(); i++)
	{
		op_s.push_back(ss[i]);
		if (ss[i] != '&')
			op_s.push_back('#');
	}

	for (int i = 1; i < op_s.size() - 1; i++)
	{
		p[i] = (lright_edge - i > 0) ? (p[2 * center - i] > (lright_edge - i) ? (lright_edge - i) : p[2 * center - i]) : 1;
		//当前右侧回文最长是否包含当前节点，如果包含，看对应位置回文长度是否大于回文右边最远节点的左侧，如果大于，则p[i]节点
		//回文长度从回文右侧最远点开始计算，如果不大于，则从对应节点回文长度开始计算。如果不包含，则从1开始计算。
		while (op_s[i + p[i]] == op_s[i - p[i]]) p[i]++;
		if (p[i] + i > lright_edge)
		{
			if (p[i] > p[max_center])
				max_center = i;//回文最长的中心
			center = i;//回文右边最远的中心
			lright_edge = i + p[i] - 1;

		}
	}

	if (op_s[max_center] == '#')
	{
		for (int i = (max_center-p[max_center]+2)/2-1; i <= (max_center + p[max_center] - 2) / 2 - 1; i++)
		{
			result.push_back(s[i]);
		}

	}
	else
	{
		for (int i = 0; i <= max_center / 2 - 1 + (p[max_center] / 2 - 1) - (max_center / 2 - 1 - (p[max_center] / 2 - 1)); i++)
		{
			result.push_back(s[i + max_center / 2 - 1 - (p[max_center] / 2 - 1)]);
		}
	}
	ss = "";
	for (int i = 0; i < result.size(); i++)
	{
		ss += result[i];
	}

	return ss;
}

inline void Palindromic_Substring::adaptor()
{
	cout << longestPalindrome("a") << endl;
}