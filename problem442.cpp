#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> nums = { 4,3,2,7,8,2,3,1 };
		vector<int> res = findDuplicates(nums);
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i] << "\t";
		}
		cout << endl;
	}
private:
	vector<int> findDuplicates(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return vector<int>();
		vector<int>::iterator starter = nums.begin();
		vector<int>::iterator iter = nums.begin();
		vector<int>::iterator temp = nums.begin();
		vector<int> res;
		while (iter != nums.end())
		{
			if (*iter < 0)
			{
				res.push_back(*iter);

				while (starter != nums.end() && *starter>0)
				{
					starter++;
				}
				iter = starter;
			}
			else
			{
				temp = nums.begin() + *iter - 1;
				*iter = 0 - (*iter);
				iter = temp;
			}

		}
		return res;
	}
};