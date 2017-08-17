#include <iostream>
#include <vector>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> nums = { 8,8,8,8,8 };
		vector<int> res = searchRange(nums, 8);
		cout << res[0] << "\t" << res[1] << endl;
	}
private:
	vector<int> searchRange(vector<int>& nums, int target) 
	{
		if (nums.size() == 0)
			return vector<int>();
		vector<int> res(2, -1);
		binarysearch(nums, target, 0, nums.size() - 1, res);
		return res;
	}
	void binarysearch(vector<int> &nums, int target, int start, int end, vector<int> &res)
	{
		if (start > end)
			return;
		else if (nums[start] > target)
			return;
		else if (nums[end] < target)
			return;
		else
		{
			int mid = (start + end) / 2;
			if (nums[mid] < target)
			{
				binarysearch(nums, target, mid + 1, end, res);
			}
			else if (nums[mid] > target)
			{
				binarysearch(nums, target, start, mid - 1, res);
			}
			else
			{
				if (res[0] == -1 && res[1] == -1)
				{
					res[0] = mid;
					res[1] = mid;
					binarysearch(nums, target, start, mid - 1, res);
					binarysearch(nums, target, mid + 1, end, res);
				}
				else if (mid < res[0])
				{
					res[0] = mid;
					binarysearch(nums, target, start, mid - 1, res);
				}
				else if (mid > res[1])
				{
					res[1] = mid;
					binarysearch(nums, target, mid + 1, end, res);
				}
			}
		}
	}
};