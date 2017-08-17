#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class solution
{
	struct coordinate
	{
		int x;
		int y;
		coordinate(int a, int b) { x = a; y = b; }
		bool operator == (const coordinate &coor) const
		{
			if (this->x == coor.x && this->y == coor.y)
				return true;
			return false;
		}
	};
public:
	deque<coordinate> coordinates;
	void adaptor()
	{
		vector<vector<int>> grid = { {1,1},{1,1} };
		cout << islandPerimeter(grid) << endl;
	}
private:
	int islandPerimeter(vector<vector<int>>& grid) {
		int column;
		int row;
		for (int i = 0; i<grid.size(); i++)
		{
			for (int j = 0; j<grid[i].size(); j++)
			{
				if (grid[i][j] == 1)
				{
					column = i;
					row = j;
					goto label;
				}

			}
		}
	label:
		return iter(grid, column, row, 0);
	}
	int iter(vector<vector<int>> &grid, int x, int y, int sum)
	{
		int incl = 0;
		coordinates.push_back(coordinate(x, y));
		if (find(coordinates.begin(), coordinates.end(), coordinate(x - 1, y)) != coordinates.end())
			incl++;
		if (find(coordinates.begin(), coordinates.end(), coordinate(x, y - 1)) != coordinates.end())
			incl++;
		if (find(coordinates.begin(), coordinates.end(), coordinate(x + 1, y)) != coordinates.end())
			incl++;
		if (find(coordinates.begin(), coordinates.end(), coordinate(x, y + 1)) != coordinates.end())
			incl++;
		if (x - 1 >= 0 && grid[x - 1].size() >= grid[x].size() && grid[x - 1][y] != 0 && find(coordinates.begin(), coordinates.end(), coordinate(x - 1, y)) == coordinates.end())
			sum = iter(grid, x - 1, y, sum);
		if (y - 1 >= 0 && grid[x][y - 1] != 0 && find(coordinates.begin(), coordinates.end(), coordinate(x, y - 1)) == coordinates.end())
			sum = iter(grid, x, y - 1, sum);
		if (x + 1 < grid.size() && grid[x + 1].size() >= grid[x].size() && grid[x + 1][y] != 0 && find(coordinates.begin(), coordinates.end(), coordinate(x + 1, y)) == coordinates.end())
			sum = iter(grid, x + 1, y, sum);
		if (y + 1 < grid[x].size() && grid[x][y + 1] != 0 && find(coordinates.begin(), coordinates.end(), coordinate(x, y + 1)) == coordinates.end())
			sum = iter(grid, x, y + 1, sum);
		return sum - incl + 4 - incl;
	}
};