#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Keyboard_Row
{
public:
	void adpator();
private:
	vector<string> findWords(vector<string>& words);
};

inline void Keyboard_Row::adpator()
{
	vector<string> words = { "Hello","Alaska","Dad","Peace" };
	vector<string> res = findWords(words);
	
	for (vector<string>::iterator iter = res.begin(); iter != res.end(); iter++)
	{
		cout << *iter << "\t";
	}
	cout << endl;

}

inline vector<string> Keyboard_Row::findWords(vector<string>& words)
{
	vector<char> first = { 'q','w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p',
		'Q','W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P' };
	vector<char> second = { 'a','s', 'd', 'f', 'g', 'h', 'j', 'k', 'l',
		'A','S', 'D', 'F', 'G', 'H', 'J', 'K', 'L' };
	vector<char> third = { 'z','x', 'c', 'v', 'b', 'n', 'm',
		'Z','X', 'C', 'V', 'B', 'N', 'M' };
	vector<string> res;
	map<char, int> w;
	for (vector<char>::iterator iter = first.begin(); iter != first.end(); iter++)
		w[*iter] = 1;
	for (vector<char>::iterator iter = second.begin(); iter != second.end(); iter++)
		w[*iter] = 2;
	for (vector<char>::iterator iter = third.begin(); iter != third.end(); iter++)
		w[*iter] = 3;

	for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++)
	{
		string word = *iter;
		int len = word.length();
		int sign = w[word[0]];
		for (int i = 1; i < len; i++)
		{
			if (w[word[i]] != sign)
				goto label;
		}
		res.push_back(word);
	label:;
	}
	return res;
}
