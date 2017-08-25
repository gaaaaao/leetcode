#include <iostream>
#include <vector>
#include <map>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		/*vector<int> nums = { 0,2,1 };
		cout << arrayNesting(nums) << endl;*/
		int a[4] = { 1,2,3,4 };
		int i, j, k;
		int t = 1 << 4;
		for (int i = 0; i < t; i++)
		{
			j = i;
			k = 0;
			cout << "{";
			while (j)
			{
				if (j & 1)
					cout << a[k];
				j >>= 1;
				++k;
			}
			cout << "}" << endl;
		}
	}
private:
	int arrayNesting(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		int res = 0;
		map<int, bool> find;
		for (int i = 0; i<len; i++)
		{
			int index = i;
			int temp = 0;
			while (find[index] == 0)
			{
				temp++;
				find[index] = 1;
				index = nums[index];

			}
			if (temp > res)
				res = temp;
		}
		return res;
	}
};