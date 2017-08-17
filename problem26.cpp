#include <iostream>
#include <vector>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> nums = { 1,2,2 };
		int undu = removeDuplicates(nums);
		for (int i = 0; i < undu; i++)
		{
			cout << nums[i] << "\t";
		}
		cout << endl;
	}
private:
	int removeDuplicates(vector<int>& nums)
	{
		int len = nums.size();
		if (len == 0)
			return 0;
		int pos = 0;

		for (int i = 1; i<len; i++)
		{
			if (nums[i] == nums[pos])
				continue;
			else
			{
				pos++;
				swap(nums[pos], nums[i]);
				
			}
		}

		return pos+1;
	}
};