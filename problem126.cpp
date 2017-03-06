#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class Word_Ladder_II {
public:
	void adaptor();
private:
	int wordLen;//the word length
	int listLen;//the word list length
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList);
	bool comparetwoword(string word1, string word2);
};

inline void Word_Ladder_II::adaptor()
{
	string a[7] = { "hot","dot","dog","lot","log","cog", "cot" };
	vector<string> wordList(a, a + 7);
	vector<vector<string>> out = findLadders("hit", "cog", wordList);
	for (int i = 0;i<out.size();i++)
	{
		for (int j = 0; j < out[i].size(); j++)
		{
			cout << out[i][j] << "\t";
		}
		cout << endl;
	}
}

inline vector<vector<string>> Word_Ladder_II::findLadders(string beginWord, string endWord, vector<string>& wordList)
{
	
	queue<vector<string>> q;
	vector<string> find;
	vector<vector<string>> findLadders;
	int shortestlen = 10000;
	string penult = "";
	
	wordLen = beginWord.length();
	listLen = wordList.size();
	int i = 0;
	for (i = 0; i < listLen; i++)
	{
		if (endWord==wordList[i])
			break;
	}
	if (i == wordLen)
		return findLadders;

	find.push_back(beginWord);
	q.push(find);
	while (!q.empty())
	{
		find = q.front();
		q.pop();
		string lastWord = find.back();

		if (find.size() > shortestlen)
			continue;
		if (comparetwoword(lastWord, endWord))
		{
			shortestlen = find.size();
			find.push_back(endWord);
			findLadders.push_back(find);
			continue;
		}

		penult = "";
		if (find.size() > 1)
			penult = find[find.size() - 2];

		for (int i = 0; i < listLen; i++)
		{
			if (comparetwoword(lastWord, wordList[i]))
			{
				if (wordList[i] != penult && !comparetwoword(penult, wordList[i]))
				{
					vector<string> tmp = find;
					tmp.push_back(wordList[i]);
					q.push(tmp);
				}
				
			}
		}
	}

	return findLadders;
}

inline bool Word_Ladder_II::comparetwoword(string word1, string word2)
{
	if (word1.length() != word2.length())
		return false;
	int sign = 0;
	for (int i = 0; i < wordLen; i++)
	{
		if (word1[i] != word2[i])
		{
			sign++;
		}
	}
	if (sign == 1)
		return true;
	return false;
}
