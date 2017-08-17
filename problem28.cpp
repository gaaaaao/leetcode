#include <iostream>
#include <vector>

using namespace std;

class ImplementstrStr
{
public:
	void adaptor();
private:
	int strStr(string haystack, string needle);
	vector<int> GetNext(const string &T);
};

inline void ImplementstrStr::adaptor()
{
	cout << strStr("abcdefghijklmnopqrstuvwxyz", "aabbaa") << endl;
}

inline int ImplementstrStr::strStr(string haystack, string needle)
{
	//vector<int> ind = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101 };
	int m = haystack.size();
	int n = needle.size();
	if (n == 0)
		return 0;

	vector<int> next = GetNext(needle);
	for (int i = 0, j = 0; i < m;) {
		if (haystack[i] == needle[j]) {
			i++;
			j++;
		}
		if (j == n)
			return i - n;
		if (i < m && haystack[i] != needle[j]) {
			if (j)
				j = next[j - 1];
			else
				i++;
		}
	}
	return -1;
}

inline vector<int> ImplementstrStr::GetNext(const string &T)
{
	int len = T.size();
	vector<int> next(len, 0);
	for (int i = 1, k = 0; i < len;) {
		if (T[i] == T[k])
			next[i++] = ++k;
		else if (k)
			k = next[k - 1];
		else
			next[i++] = 0;
	}
	return next;
}
