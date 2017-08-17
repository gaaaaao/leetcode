#include <iostream>
#include <vector>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> nums = { 1,1,7,4,9,2,5 };
		wiggleMaxLength(nums);
	}
private:
	int wiggleMaxLength(vector<int>& nums) {
		if (nums.size() <= 1)
			return nums.size();
		vector<int> wig(nums.size(), 2);
		wig[0] = 1;
		wig[1] = nums[1] == nums[0] ? 1 : 2;
		int temp = nums[1] - nums[0];
		for (int i = 2; i<nums.size(); i++)
		{
			if (temp == 0 || ((nums[i] - nums[i - 1]) ^ temp) >> 31)
			{
				wig[i] = wig[i - 1] + 1;
				temp = nums[i] - nums[i - 1];
			}
			else
				wig[i] = wig[i - 1];
		}
		return wig[nums.size() - 1];
	}
};