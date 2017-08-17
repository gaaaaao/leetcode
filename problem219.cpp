#include <iostream>
#include <vector>
#include <map>
using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> a = { 1,2,1 };
		cout << containsNearbyDuplicate(a, 2) << endl;
	}
private:
	bool containsNearbyDuplicate(vector<int>& nums, int k)
	{
		int len = nums.size();
		if (!len)
			return false;
		map<int, int> du;
		for (int i = 0; i<len; i++)
		{
			if (du.find(nums[i]) == du.end())
			{
				du[nums[i]] = i;
			}
			else
			{
				if (i - du[nums[i]] <= k)
					return true;
				else
				{
					du[nums[i]] = i;
				}
			}
		}
		return false;
	}
};