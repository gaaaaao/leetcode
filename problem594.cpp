#include <iostream>
#include <vector>
#include <map>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> nums = { 1,3,2,2,5,2,3,7 };
		cout << findLHS(nums) << endl;
	}
private:
	int findLHS(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		map<int, int> hash;
		int res = 0;
		for (int i = 0; i<len; i++)
		{
			hash[nums[i]]++;
		}
		for (map<int, int>::iterator iter = hash.begin(); iter != hash.end(); iter++)
		{
			map<int, int>::iterator i1 = hash.find(iter->first - 1);
			map<int, int>::iterator i2 = hash.find(iter->first + 1);
			int temp = 0;
			if (i1 != hash.end() && i2 != hash.end())
			{
				temp = i1->second > i2->second ? (i1->second + iter->second) : (i2->second + iter->second);
			}
			else if (i1 != hash.end() && i2 == hash.end())
				temp = i1->second + iter->second;
			else if (i1 == hash.end() && i2 != hash.end())
				temp = i2->second + iter->second;
			if (temp > res)
			res = temp;
		}
		return res;
	}
};