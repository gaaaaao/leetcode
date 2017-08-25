#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> nums = { 1,0,1,1,0,1,0,1,1,0,0,0,1,1,1 };
		findMaxLength(nums);
	}
private:
	int findMaxLength(vector<int>& nums) {
		nums.insert(nums.begin(), 0);
		vector<int> aid(nums.size(), 0);
		unordered_map<int, int> hash;
		int res = 0;

		for (int i = 1; i<nums.size(); i++)
		{
			aid[i] = nums[i] ? (aid[i - 1] + 1) : (aid[i - 1] - 1);
		}
		for (int i = 0; i<aid.size(); i++)
		{
			if (hash.find(aid[i]) == hash.end())
			{
				hash[aid[i]] = i;
				continue;
			}
			res = max(res, i - hash[aid[i]]);
		}
		return res;
	}
};