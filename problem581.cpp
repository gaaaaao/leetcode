#include <iostream>
#include <vector>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> nums = { 1,2,4,5,3 };
		cout << findUnsortedSubarray(nums) << endl;
	}
private:
	int findUnsortedSubarray(vector<int>& nums) {
		int len = nums.size();
		int start = 0, end = 0;
		vector<int> min = nums;
		vector<int> max = nums;
		for (int i = len - 2; i >= 0; i--)
		{
			if (nums[i]<nums[i + 1])
				min[i] = nums[i];
			else
				min[i] = min[i + 1];
		}
		for (int i = 1; i<len; i++)
		{
			if (nums[i]>nums[i - 1])
				max[i] = nums[i];
			else
				max[i] = max[i - 1];
		}
		for (int i = 0; i<len; i++)
		{
			if (nums[i] != min[i])
			{
				start = i;
				break;
			}
		}
		for (int i = len - 1; i >= 0; i--)
		{
			if (nums[i] != max[i])
			{
				end = i;
				break;
			}
		}
		return end > start ? (end - start + 1) : 0;
	}
};