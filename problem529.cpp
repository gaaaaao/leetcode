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
		vector<vector<char>> board = 
		{{'E', 'E', 'E', 'E', 'E'},
		{'E', 'E', 'M', 'E', 'E'},
		{'E', 'E', 'E', 'E', 'E'},
		{'E', 'E', 'E', 'E', 'E'}};
		vector<int> click = { 3,0 };
		updateBoard(board, click);
	}
private:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
		queue<pair<int, int>> q;
		q.push(make_pair(click[0], click[1]));
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (board[x][y] == 'M')
			{
				board[x][y] = 'X';
				return board;
			}
			if (board[x][y] == 'E')
			{
				int mines = countmines(board, x, y);
				if (mines != 0)
				{
					board[x][y] = mines + '0';
					continue;
				}
				board[x][y] = 'B';
				for (int i = -1; i<2; i++)
				{
					if (x + i<0 || x + i >= board.size())
						continue;
					for (int j = -1; j<2; j++)
					{
						if (y + j<0 || y + j >= board[0].size()|| (i == 0 && j == 0))
							continue;
						if(board[x+i][y+j] == 'E')
							q.push(make_pair(x + i, y + j));
					}
				}
			}
		}
		return board;
	}
	int countmines(vector<vector<char>> &board, int x, int y)
	{
		int count = 0;
		for (int i = -1; i<2; i++)
		{
			if (x + i<0 || x + i >= board.size())
				continue;
			for (int j = -1; j<2; j++)
			{
				if (y + j < 0 || y + j >= board[0].size())
					continue;
				if (board[x+i][y+j] == 'M')
					count++;
			}
		}
		return count;
	}
};