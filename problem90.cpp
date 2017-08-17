#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
	void adaptor() 
	{
		vector<int> nums = { 1,2,2 };
		subsetsWithDup(nums);
	}
private:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		int len = nums.size();
		int subs = 1 << len;
		int i, j, k = 0;
		vector<vector<int>> res;
		for (i = 0; i<subs; i++)
		{
			vector<int> temp;
			j = i;
			k = 0;
			while (j)
			{
				if (j & 1)
				{
					temp.push_back(nums[k]);
				}
				j >>= 1;
				k++;
			}
			sort(temp.begin(), temp.end());
			if (find(res.begin(), res.end(), temp) == res.end())
				res.push_back(temp);
		}
		return res;
	}
};