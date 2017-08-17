#include <iostream>
#include <vector>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> nums = { 1,2,3 };
		permute(nums);
	}
private:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		dfs(nums, res, 0);
		return res;
	}
	void dfs(vector<int> & nums, vector<vector<int>> & res, int cur)
	{
		if (cur == nums.size())
		{
			res.push_back(nums);
			return;
		}
		for (int i = cur; i<nums.size(); i++)
		{
			swap(nums[cur], nums[i]);
			dfs(nums, res, cur+1);
			swap(nums[cur], nums[i]);
		}
	}
};