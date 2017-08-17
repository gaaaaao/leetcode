#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class solution
{
public:
	void adaptor()
	{
		string beginWord = "hit";
		string endWord = "cog";
		vector<string> wordList = { "hot","dot","dog","lot","log","cog" };
		ladderLength(beginWord, endWord, wordList);
	}
private:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if (beginWord.size() != endWord.size())
			return 0;
		if (beginWord.empty() || endWord.empty())
			return 1;
		if (wordList.size() == 0)
			return 0;
		int dis = 1;
		queue<string> q;
		q.push(beginWord);
		int count = q.size()-1;
		while (!q.empty())
		{
			string temp = q.front();
			q.pop();
			if (temp == endWord)
				return dis;
			for (auto i = wordList.begin(); i != wordList.end();)
			{
				if (cmp(temp, *i))
				{
					q.push(*i);
					i = wordList.erase(i);
				}
				else
					i++;
			}
			if (count == 0)
			{
				count = q.size()-1;
				dis++;
			}
			else
				count--;
		}
		return 0;
	}
	bool cmp(string a, string b)
	{
		int diff = 0;
		for (int i = 0; i<a.size(); i++)
		{
			if (a[i] != b[i])
				diff++;
		}
		return diff == 1 ? true : false;
	}
};