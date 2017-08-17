#include <iostream>
#include <string>
#include <unordered_map>
using  namespace std;

class solution
{
public:
	void adaptor()
	{
		reverseVowels("hello");
	}
private:
	string reverseVowels(string s) {
		unordered_map<char, bool> vowels;
		vowels['a'] = 1;
		vowels['e'] = 1;
		vowels['i'] = 1;
		vowels['o'] = 1;
		vowels['u'] = 1;
		int i = 0;
		int j = s.length() - 1;
		while (i < j)
		{
			while (vowels[s[i]] == 0) i++;
			while (vowels[s[j]] == 0) j--;
			swap(s[i], s[j]);
			i++;
			j--;
		}
		return s;
	}
};