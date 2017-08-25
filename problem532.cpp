#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> nums = { 1,1,3,4,5 };
		cout << findPairs(nums, 2) << endl;
	}
private:
	int findPairs(vector<int>& nums, int k)
	{
		int len = nums.size();
		sort(nums.begin(), nums.end());
		set<int> sset;
		int res = 0;
		for (int i = 0; i < len; i++)
		{
			if (sset.find(nums[i]-k) != sset.end())
				res++;
			sset.insert(nums[i]);
		}
		return res;
	}

};