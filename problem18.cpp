#include <iostream>
#include <vector>
using namespace std;

class FourSum
{
public:
	void adaptor();
private:
	vector<vector<int>> fourSum(vector<int>& nums, int target);
	void quicksort(vector<int>& nums, int start, int end);
};

inline void FourSum::adaptor()
{
	vector<int> test = { -1,0,1,2,-1,-4 };
	vector<vector<int>> res = fourSum(test, -1);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << "\t";
		cout << endl;
	}

}

inline vector<vector<int>> FourSum::fourSum(vector<int>& nums, int target)
{
	
	int len = nums.size();
	quicksort(nums, 0, len - 1);
	vector<vector<int>> res;
	if (len < 4)
		return res;
	if ((nums[len - 1] + nums[len - 2] + nums[len - 3] + nums[len - 4]) < target)
		return res;
	if (len == 4)
	{
		if ((nums[len - 1] + nums[len - 2] + nums[len - 3] + nums[len - 4]) == target)
			res.push_back(nums);
		return res;
	}
	for (int first = 0; first < len - 3; first++)
	{
		if ((nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3]) > target)
			break;
		for (int second = first + 1; second < len - 2; second++)
		{
			int third = second + 1;
			int fourth = len - 1;
			while (third < fourth)
			{
				int temp = nums[first] + nums[second] + nums[third] + nums[fourth];
				if (temp == target)
				{
					bool sign = true;
					vector<int> t = { nums[first],nums[second],nums[third],nums[fourth] };
					for (int i = 0; i < res.size(); i++)
					{
						if (t == res[i])
						{
							sign = false;
							break;
						}
					}
					if(sign)
						res.push_back(t);
					third++;
					fourth--;
				}
				else if (temp < target)
					third++;
				else if (temp > target)
					fourth--;
			}
		}
	}
	return res;
}

inline void FourSum::quicksort(vector<int>& nums, int start, int end)
{
	if (start >= end)
		return;
	int mid = nums[end];
	int left = start;
	int right = end - 1;
	while (left < right)
	{
		while (nums[left] < mid && left < right) left++;
		while (nums[right] >= mid && left < right) right--;
		swap(nums[right], nums[left]);
	}
	if (nums[left] >= mid)
		swap(nums[left], nums[end]);
	else
		left++;
	quicksort(nums, start, left - 1);
	quicksort(nums, left + 1, end);
}
