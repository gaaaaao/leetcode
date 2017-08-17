#include <iostream>
#include <vector>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<vector<int>> matrix = { {1,2,3,4,5,0},{1,2,3,4,5,6} };
		setZeroes(matrix);
	}
private:
	void setZeroes(vector<vector<int>>& matrix) {
		int row = matrix.size();
		if (row == 0)
			return;
		int column = matrix[0].size();
		if (column == 0)
			return;
		bool rowzero = 1;
		bool columnzero = 1;
		for (int i = 0; i<row; i++)
			if (matrix[i][0] == 0)
				columnzero = 0;
		for (int i = 0; i<column; i++)
			if (matrix[0][i] == 0)
				rowzero = 0;
		for (int i = 1; i<row; i++)
		{
			for (int j = 1; j<column; j++)
			{
				if (matrix[i][j] == 0)
				{
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		for (int i = 1; i<row; i++)
		{
			if (matrix[i][0] == 0)
				matrix[i].assign(column, 0);
		}
		for (int i = 1; i<column; i++)
		{
			if (matrix[0][i] == 0)
			{
				for (int j = 0; j<row; j++)
				{
					matrix[j][i] = 0;
				}
			}
		}
		if (!columnzero)
		{
			for (int i = 0; i<row; i++)
			{
				matrix[i][0] = 0;
			}
		}
		if (!rowzero)
			matrix[0].assign(column, 0);

	}
};