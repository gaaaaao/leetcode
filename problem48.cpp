#include <iostream>
#include <vector>

using namespace std;

class Rotate_Image {
public:
	void adaptor()
	{
		vector<vector<int>> a(4,vector<int>(4));
		int k = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				a[i][j] = k++;
			}
		}
		rotate(a);

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << a[i][j] << "\t";
			}
			cout << endl;
		}
	}
private:
	void rotate(vector<vector<int>>& matrix) {
		int temp = 0;
		int inter= 0;
		int x = 0;
		int y = 0;
		int i = 0;
		int j = 0;
		int k = 0;
		int len = matrix.size();
		int cir = 0;
		while (cir<(len + 1) / 2)
		{
			for (j = i; j<len - cir-1; j++)
			{
				x = i;
				y = j;
				temp = matrix[x][y];
				for (k = 0; k < 4; k++)
				{
					inter = matrix[y][len - x - 1];
					matrix[y][len - x - 1] = temp;
					temp = inter;
					inter = x;
					x = y;
					y = len - inter - 1;
				}
			}
			cir ++;
			i = i + 1;
		}
	}
};