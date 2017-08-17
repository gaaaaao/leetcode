#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> nums = { 1,2,4,8,11 };
		largestDivisibleSubset(nums);
	}
private:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return vector<int>();
		sort(nums.begin(), nums.end());
		vector<int> path(nums.size(), 0);
		for (int i = 0; i<nums.size(); i++)
		{
			int temp = 0;
			for (int j = i - 1; j >= 0; j--)
			{
				if (nums[i] % nums[j] != 0)
					continue;
				if (path[j] + 1 > path[i])
				{
					path[i] = path[j] + 1;
				}
			}
		}
		int max = 0;
		for (int i = 0; i<path.size(); i++)
		{
			if (path[i]>path[max])
				max = i;
		}
		vector<int> res;
		for (int i = 0; i<max; i++)
		{
			if (res.size() == 0)
			{
				if (nums[max] % nums[i] == 0)
					res.push_back(nums[i]);
			}
			else
			{
				if (nums[max] % nums[i] == 0 && nums[i] % res[res.size() - 1] == 0)
					res.push_back(nums[i]);
			}
		}
		res.push_back(nums[max]);
		return res;
	}
};