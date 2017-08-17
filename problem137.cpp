#include <iostream>
#include <vector>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> nums = { -2,-2,1,1,-3,1,-3,-3,-4,-2 };
		singleNumber(nums);
	}
private:
	int singleNumber(vector<int>& nums) {
		vector<int> bits(32, 0);
		int res = 0;
		for (int i = 0; i<nums.size(); i++)
		{
			for (int j = 0; j<32; j++)
			{
				bits[j] += nums[i] & 1;
				nums[i] >>= 1;
				if (bits[j] == 3)
					bits[j] = 0;
			}
		}
		for (int i = 31; i>=0; i--)
		{
			res <<= 1;
			res += bits[i];
		}
		return res;
	}
};