#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Longest_Common_Prefix
{
public:
	void adaptor();
private:
	string longestCommonPrefix(vector<string>& strs);
};

inline void Longest_Common_Prefix::adaptor()
{
	vector<string> strs;
	strs.push_back("asdf");
	cout << longestCommonPrefix(strs) << endl;
}

inline string Longest_Common_Prefix::longestCommonPrefix(vector<string>& strs)
{
	if (strs.size() == 0)
		return "";
	if (strs.size() == 1)
		return strs[0];

	int str_num = strs.size();
	bool sign= false;
	int j = 0;

	for (int i = 0; i < strs.size(); i++)
	{
		char s = i;
		strs[i] = '&' + strs[i] + s;
		
	}

	while (1)
	{
		for (int i = 0; i < str_num-1; i++)
		{
			if (strs[i].at(j) != strs[i + 1].at(j))
			{
				sign = true;
				break;
			}

		}
		if (sign == true)
			break;
		j++;
	}

	return strs[0].substr(1,j-1);
}
