#include <iostream>
#include <vector>

using namespace std;

class Find_Min_in_Rotated_S_Array
{
public:
	void adaptor();
private:
	int findMin(vector<int>& nums);
	int find(vector<int>& nums, int start, int end, int first);
};

void Find_Min_in_Rotated_S_Array::adaptor()
{
}

int Find_Min_in_Rotated_S_Array::findMin(vector<int>& nums)
{
	if (nums.empty())
		return NULL;
	return find(nums, 0, nums.size() - 1, nums[0]);
}

int Find_Min_in_Rotated_S_Array::find(vector<int>& nums, int start, int end, int first)
{
	if (start == end)
		return nums[start];
	if (nums[(end + start) / 2] > nums[(end + start) / 2 + 1])
		return nums[(end + start) / 2 + 1];
	else if (nums[(end + start) / 2] > first)
	{
		return find(nums, (end + start) / 2 + 1, end, first);
	}
	else
	{
		return find(nums, start, (end + start) / 2, first);
	}
	nums.back()
	return 0;
}
