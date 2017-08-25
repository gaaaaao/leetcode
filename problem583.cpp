#include <iostream>
#include <vector>
#include <string>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		string word1 = "failing";
		string word2 = "sailn";
		minDistance(word1, word2);
	}
private:
	int minDistance(string word1, string word2) {
		vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));
		for (int i = 0; i<word1.length() + 1; i++)
		{
			dp[i][0] = i;
		}
		for (int i = 0; i<word2.length() + 1; i++)
		{
			dp[0][i] = i;
		}
		for (int i = 1; i<word1.length() + 1; i++)
		{
			for (int j = 1; j<word2.length() + 1; j++)
			{
				dp[i][j] = minn(dp[i][j - 1] + 1, dp[i - 1][j] + 1, dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1));
			}
		}
		return dp[word1.length()][word2.length()];
	}
	int minn(int a, int b, int c)
	{
		int x = a<b ? (a<c ? a : c) : (b<c ? b : c);
		return x;
	}
};