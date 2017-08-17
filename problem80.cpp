#include <iostream>
#include <vector>
#include <map>
using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> nums = { 1,2,2 };
		cout << removeDuplicates(nums) << endl;
	}
private:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		int count = 0;
		int res = 1;
		for (int i = 1; i<len; i++)
		{
			if (nums[res] != nums[res - 1])
				count = 0;
			else
				count++;
			if (nums[i] == nums[res] && count > 1)
				continue;
			swap(nums[res], nums[i]);
			res++;
			
		}
		return res;
	}
};