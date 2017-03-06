#include <iostream>
#include <vector>

using namespace std;

class Maximal_Square
{
public:
	void adaptor();
private:
	int maximalSquare(vector<vector<char>>& matrix);
	int maximalSquare2(vector<vector<char>>& matrix);
	int sum(vector<vector<char>> &matrix, int templen, int i, int j);
};

inline void Maximal_Square::adaptor()
{
	int arr[5][4] = {
		{'0','0','0','1'},
		{ '1','1','0','1' },
		{ '1','1','1','1' },
		{ '0','1','1','1' },
		{ '0','1','1','1' }
	};
	vector<vector<char>> matrix(5, vector<char>(4));
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			matrix[i][j] = arr[i][j];
		}
	}


	cout << maximalSquare(matrix) << endl;
}

inline int Maximal_Square::maximalSquare(vector<vector<char>>& matrix)
{
	int len = matrix.size();
	if (len == 0)
		return 0;
	int wei = matrix[0].size();
	int templen = 0;
	int tempmax = 0;
	int max = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < wei; j++)
		{
			while ((j + templen)<wei && (i + templen)<len &&  matrix[i][j + templen] == '1')
			{
				if (((templen + 1) * (templen + 1) == sum(matrix, templen + 1, i, j)))
					tempmax = templen + 1;
				else
					break;
				templen++;
			}
			if (tempmax > max)
				max = tempmax;
			templen = 0;
			tempmax = 0;
		}
	}
	return max*max;
}

int Maximal_Square::maximalSquare2(vector<vector<char>>& matrix)
{
	int len = matrix.size();
	if (len == 0)
		return 0;
	int wei = matrix[0].size();
	int max = 0;
	vector<vector<int>> matrixindex(len, vector<int>(wei, 0));

	for (int i = 0; i < len; i++)
	{
		matrixindex[i][0] = matrix[i][0] - 48;
		if (matrix[i][0] == '1')
			max = 1;
	}
	for (int i = 0; i < wei; i++)
	{
		matrixindex[0][i] = matrix[0][i] - 48;
		if (matrix[0][i] == '1')
			max = 1;
	}
	for (int i = 1; i < len; i++)
	{
		for (int j = 1; j < wei; j++)
		{
			if (matrix[i][j] == '1' && !((matrixindex[i][j - 1] ^ matrixindex[i - 1][j]) || (matrixindex[i - 1][j] ^ matrixindex[i - 1][j - 1]) || (matrixindex[i][j - 1] ^ matrixindex[i - 1][j - 1])))
				matrixindex[i][j] = matrixindex[i - 1][j] + 1;
			else if (matrix[i][j] == '0')
				matrixindex[i][j] = 0;
			else if ((matrixindex[i][j - 1] ^ matrixindex[i - 1][j]) || (matrixindex[i - 1][j] ^ matrixindex[i - 1][j - 1]) || (matrixindex[i][j - 1] ^ matrixindex[i - 1][j - 1]))
				matrixindex[i][j] = (matrixindex[i][j - 1] < matrixindex[i - 1][j] ? (matrixindex[i][j - 1] < matrixindex[i - 1][j - 1] ? matrixindex[i][j - 1] : matrixindex[i - 1][j - 1]) : (matrixindex[i - 1][j] < matrixindex[i - 1][j - 1] ? matrixindex[i - 1][j] : matrixindex[i - 1][j - 1])) + 1;
			max = max > matrixindex[i][j] ? max : matrixindex[i][j];
		}
	}
	return max * max;
}

inline int Maximal_Square::sum(vector<vector<char>>& matrix, int len, int i, int j)
{
	int sum = 0;
	for (int ti = 0; ti < len; ti++)
	{
		for (int tj = 0; tj < len; tj++)
		{
			sum += matrix[ti + i][tj + j]-48;
		}
	}
	return sum;
}
