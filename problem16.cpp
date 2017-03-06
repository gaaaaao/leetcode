#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Three_Sum_Closest
{
public:
	void adaptor();
private:
	int threeSumClosest(vector<int>& nums, int target);
};

inline void Three_Sum_Closest::adaptor()
{
	int a[3] = { 0,1,2 };
	int length = sizeof(a) / sizeof(a[0]);
	vector<int> nums;
	for (int i = 0; i < length; i++)
	{
		nums.push_back(a[i]);
	}

	cout << threeSumClosest(nums, 3) << endl;

}

inline int Three_Sum_Closest::threeSumClosest(vector<int>& nums, int target)
{
	int len = nums.size();
	int sign = 0;
	int left = 1;
	int right = 0;
	int min = 100000;
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (nums[j] > nums[j + 1])
				swap(nums[j], nums[j + 1]);
		}
	}

	for (int i = 0; i < len - 2; i++)
	{
		sign = target - nums[i];
		left = i + 1;
		right = len - 1;
		while (left<right)
		{
			if (abs(target - nums[i] - nums[left] - nums[right]) < min)
			{
				min = abs(target - nums[i] - nums[left] - nums[right]);
				sum = nums[i] + nums[left] + nums[right];
			}
			if (nums[i] + nums[left] + nums[right] < target)
				left++;
			else if (nums[i] + nums[left] + nums[right] > target)
				right--;
			else
				return sum;
		}
	}

	return sum;
}
