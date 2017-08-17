#include <iostream>
#include <vector>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> temp = { 1,2,3 };
		temp.resize(5, 0);
		for (vector<int>::iterator iter = temp.begin(); iter != temp.end(); iter++)
		{
			cout << *iter << "\t";
		}
		cout << endl;
		/*vector<vector<int>> matrix = { {-10,-10},{-9,-9},{-8,-6},{-4,-2},{0,1},{3,3},{5,5},{6,8} };
		cout << searchMatrix(matrix, 0) << endl;*/
	}
private:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0)
			return false;
		if (matrix[0].size() == 0)
			return false;
		if (target > matrix[matrix.size() - 1][matrix[matrix.size() - 1].size() - 1])
			return false;
		if (target < matrix[0][0])
			return false;
		int row = binarysearch(matrix, target, 0, matrix.size() - 1);
		if (row == -1)
			return false;
		return binsearch(matrix[row], target, 0, matrix[row].size() - 1);
	}
	bool binsearch(vector<int> row, int target, int start, int end)
	{
		if (start > end)
			return false;
		int mid = (start + end) / 2;
		if (row[mid] == target)
			return true;
		else if (row[mid] < target)
			return binsearch(row, target, mid + 1, end);
		else if (row[mid] > target)
			return binsearch(row, target, start, mid - 1);
	}
	int binarysearch(vector<vector<int>> &matrix, int target, int start, int end)
	{
		if (start > end)
			return -1;
		int mid = (start + end) / 2;
		if (mid + 1 < matrix.size() && matrix[mid][0] <= target && matrix[mid + 1][0] > target)
			return mid;
		if (mid + 1 < matrix.size() && matrix[mid + 1][0] <= target)
			return binarysearch(matrix, target, mid + 1, end);
		if (matrix[mid][0] > target)
			return binarysearch(matrix, target, start, mid);
		if (matrix[matrix.size() - 1][0] <= target)
			return matrix.size() - 1;
		return -1;
	}
};