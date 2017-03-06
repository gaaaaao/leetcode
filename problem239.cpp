#include <iostream>
#include <vector>

#define random(x) (rand()%x+1)

using namespace std;

class Sliding_Window_Maximum
{
public:
	void adaptor();
private:
	vector<int> maxSlidingWindow(vector<int>& nums, int k);
};

inline void Sliding_Window_Maximum::adaptor()
{
	int s[15] = { 9,8,7,6,5,4,3,2,1 };
	int len = sizeof(s) / (sizeof(s[0]));
	int k = 5;
	vector<int> a(len);
	for (int i = 0; i < len; i++)
	{
		a[i] = s[i];
	}
	
	vector<int> b = maxSlidingWindow(a, k);

	for (int j = 0; j < a.size()-k+1; j++)
	{
		cout << b[j] << "\t";
	}
	cout << endl;
}

inline vector<int> Sliding_Window_Maximum::maxSlidingWindow(vector<int>& nums, int k)
{
	if (!nums.size() || !k)
		return nums;
	if (nums.size() < k)
	{
		int max = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			max = nums[i] > max ? nums[i] : max;
		}
		return vector<int>(1, max);
	}
	
	int len = nums.size();
	int maxArrLen = len - k + 1;
	vector<int> maxArray(maxArrLen);
	int maxInd = -1;

	for (int i = 0; i < maxArrLen; i++)
	{
		if (maxInd == -1)
		{
			maxInd = 0;
			for (int t = 1; t < k; t++)
			{
				maxInd = nums[maxInd+i] > nums[t+i] ? maxInd : t;
			}
			maxInd -= 1;
			maxArray[i] = nums[maxInd + i + 1];
		}
		else
		{
			maxInd = (nums[maxInd + i] > nums[i + k - 1] ? maxInd : k - 1) - 1;
			maxArray[i] = nums[maxInd + i + 1];
		}
	}
	return maxArray;
}
