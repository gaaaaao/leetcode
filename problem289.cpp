#include <iostream>
#include <vector>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<vector<int>> board = { {0,1},{1,1} };
		gameOfLife(board);
	}
private:
	void gameOfLife(vector<vector<int>>& board) {
		int row = board.size();
		int column = board[0].size();
		for (int i = 0; i<row; i++)
			for (int j = 0; j<column; j++)
				board[i][j] <<= 1;

		for (int i = 0; i<row; i++)
		{
			for (int j = 0; j<column; j++)
			{
				//board[i][j] = countneighbor(board, i, j);
				 int neighbors = countneighbor(board, i, j);

				 if(neighbors < 2 || neighbors > 3)
				 {
				     board[i][j] = board[i][j]?2:0;
				 }
				 else
				     board[i][j] = board[i][j]?3:1;
			}
		}

		 for(int i = 0;i<row;i++)
		     for(int j = 0;j<column;j++)
		         board[i][j] %= 2;

	}
	int countneighbor(vector<vector<int>> &board, int x, int y)
	{
		int row = board.size();
		int column = board[0].size();
		int res = 0;
		for (int i = -1; i <= 1; i++)
		{
			if (x + i <0 || x + i >= row)
				continue;
			for (int j = -1; j <= 1; j++)
			{
				if (y + j < 0 || y + j >= column)
					continue;
				res += board[x + i][y + j] >> 1;
			}
		}
		return res - (board[x][y]>>1);
	}
};