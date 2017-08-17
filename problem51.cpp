#include <iostream>
#include <vector>
#include <string>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		solveNQueens(4);
	}
private:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> res;
		vector<int> pos(n, -1);
		dfs(res, pos, 0);
		return res;
	}
	void dfs(vector<vector<string>> & res, vector<int> & pos, int cur)
	{
		if (cur == pos.size())
		{
			print(pos, res);
			return;
		}
		for (int i = 0; i<pos.size(); i++)
		{
			if (check(pos, cur, i))
			{
				pos[cur] = i;
				dfs(res, pos, cur + 1);
				pos[cur] = -1;
			}
		}
	}
	bool check(const vector<int> & pos, const int cur, const int column)
	{
		for (int i = 0; i <= cur; i++)
		{
			if (pos[cur - i] == column || (column - i >= 0 && pos[cur - i] == column - i) || (column + i<pos.size() && pos[cur - i] == column + i))
				return false;
		}
		return true;
	}
	void print(vector<int> & pos, vector<vector<string>> & res)
	{
		vector<string> temp(pos.size(), string(pos.size(), '.'));
		for (int i = 0; i<pos.size(); i++)
		{
			temp[i][pos[i]] = 'Q';
		}
		res.push_back(temp);
	}
};