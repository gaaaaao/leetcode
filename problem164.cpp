#include <iostream>
#include <vector>
using namespace std;

class Maximum_Gap
{
public:
	void adaptor();
private:
	int maximumGap(vector<int>& nums);
	void quicksort(vector<int> &nums, int start, int end);
};

inline void Maximum_Gap::adaptor()
{
	//int a[39] = { 15252,16764,27963,7817,26155,20757,3478,22602,20404,6739,16790,10588,16521,6644,20880,15632,27078,25463,20124,15728,30042,16604,17223,4388,23646,32683,23688,12439,30630,3895,7926,22101,32406,21540,31799,3768,26679,21799,23740 };
	//vector<int> nums(a, a + 39);
	//cout << maximumGap(nums) << endl;

	int a[7] = { 1,29,27,2,3,28,4 };
	vector<int> nums(a, a + 7);
	cout << maximumGap(nums) << endl;

}

inline int Maximum_Gap::maximumGap(vector<int>& nums)
{
	quicksort(nums, 0, nums.size()-1);
	int maxgap = 0;
	int len = nums.size();
	int temp = 0;
	for (int i = 1; i < len; i++)
	{
		temp = nums[i] - nums[i - 1];
		if (maxgap < temp)
			maxgap = temp;
	}

	return maxgap;
}

inline void Maximum_Gap::quicksort(vector<int>& nums,int start, int end)
{
	if (start > end)
		return;
	int mid = nums[end];
	int left = start;
	int right = end - 1;

	while (left < right)
	{
		while (nums[left] < mid && left < right) left++;
		while (nums[right] >= mid && left < right) right--;

		swap(nums[left], nums[right]);
	}
	if (nums[left] >= mid)
		swap(nums[left], nums[end]);
	else
		left++;

	quicksort(nums, start, left - 1);
	quicksort(nums, left + 1, end);
}
