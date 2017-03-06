#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

class ThreeSum
{
public:
	void adaptor();
private:
	vector<vector<int> > threeSum(vector<int>& nums);
};

inline void ThreeSum::adaptor()
{
	int a[16] = { -4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0 };
	int length = sizeof(a) / sizeof(a[0]);
	vector<int> nums;
	for (int i = 0; i < length;i++)
	{
		nums.push_back(a[i]);  
	}
	
	vector<vector<int> > result = threeSum(nums);

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i][0] << "\t" << result[i][1] << "\t" << result[i][2] << endl;
	}
}

inline vector<vector<int> > ThreeSum::threeSum(vector<int>& nums)
{
	int i, j;
	int len = nums.size();
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if (nums[j] > nums[j + 1])
				swap(nums[j], nums[j + 1]);
		}	
	}
		

	vector<vector<int> > result;
	vector<int> result_index;
	int index = 0;
	int left = 0;
	int right = 0;
	int product = 0;
	bool sign = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		index = 0 - nums[i];
		left = i + 1;
		right = nums.size() - 1;

		while (left < right)
		{
			if ((nums[left] + nums[right]) == index)
			{
				product = pow((nums[i] * 13 + 17), 3) + pow((nums[left] * 13 + 17), 3) + pow((nums[right] * 13 + 17), 3);
				for (int j = 0; j < result_index.size(); j++)
				{
					if (product == result_index[j])
					{
						sign = 1;
						break;
					}
				}
				if (sign == 0)
				{
					result_index.push_back(product);

					vector<int> result_node;
					result_node.push_back(nums[i]);
					result_node.push_back(nums[left]);
					result_node.push_back(nums[right]);

					result.push_back(result_node);
				}
				left++;
				right--;
			}
			else if ((nums[left] + nums[right]) < index)
				left++;
			else if ((nums[left] + nums[right]) > index)
				right--;
			sign = 0;
		}
			
	}

	return result;
}
