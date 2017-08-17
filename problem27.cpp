#include <iostream>
#include <vector>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> nums = { 3,1,2,3 };
		int nlen = removeElement(nums, 3);
		for (int i = 0; i < nlen; i++)
		{
			cout << nums[i] << "\t";
		}
		cout << endl;
	}
private:
	int removeElement(vector<int>& nums, int val)
	{
		int len = nums.size();
		for (int i = 0; i<len; i++)
		{
			if (nums[i] == val)
			{
				nums.erase(nums.begin() + i);
				len--;
				
			}
		}
		return len;
	}
};