#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> nums = { 2,4,3,1 };
		nextPermutation(nums);
		for (int i = 0; i < nums.size(); i++)
		{
			cout << nums[i] << "\t";
		}
		cout << endl;
	}
private:
	void nextPermutation(vector<int>& nums) {
		int len = nums.size();
		int i = 0;
		for (i = len - 2; i >= 0; i--)
		{
			if (nums[i + 1]>nums[i])
				break;
		}
		if (i == 0)
			// sort(nums,0,len-1);
			sort(nums.begin(), nums.end());
		else
		{
			if (nums[len - 1] <= nums[i + 1])
			{
				swap(nums[i], nums[i + 1]);
				// sort(nums, i+1,nums[len-1]);
				sort(nums.begin() + i + 1, nums.end());
			}
			else
			{
				swap(nums[len - 1], nums[i]);
				// sort(nums, i+1,nums[len-1]);
				sort(nums.begin() + i + 1, nums.end());
			}
		}
	}
};