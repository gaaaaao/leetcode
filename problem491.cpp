#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> nums = { 4,6,7,7 };
		findSubsequences(nums);
	}
private:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		vector<int> path;
		dfs(nums, path, res, 0);
		return res;
	}
	void dfs(vector<int> & nums, vector<int> & path, vector<vector<int>> & res, int cur)
	{
		if (cur == nums.size())
			return;
		if (path.size() >= 2)
			res.push_back(path);
		for (int i = cur; i<nums.size(); i++)
		{
			if (i != cur && nums[i] != nums[i - 1])
			{
				path.push_back(nums[i]);
				dfs(nums, path, res, i);
				path.pop_back();
			}
		}
	}
};