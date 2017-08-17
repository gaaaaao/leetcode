#include <iostream>
#include <vector>

using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> nums1 = { 1,3,5,7 };
		vector<int> nums2 = { 2,4,6 };

		merge(nums1, 4, nums2, 3);
		for (vector<int>::iterator iter = nums1.begin(); iter != nums1.end(); iter++)
		{
			cout << *iter << "\t";
		}
		cout << endl;
	}
private:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		vector<int>::iterator i, j;
		//for (i = nums1.begin(), j = nums2.begin(); i != nums1.end() && j != nums2.end();)
		for(int i = 0,j = 0;;)
		{
			if (j == n)
				break;
			else if (i == m)
			{
				nums1.push_back(nums2[j]);
				m = nums1.size();
				j++;
			}
			else
			{
				if (nums1[i] > nums2[j])
				{
					nums1.insert(nums1.begin() + i, nums2[j]);
					m = nums1.size();
					i++;
					j++;
				}
				else if (nums1[i] <= nums2[j])
				{
					i++;
				}
			}
			
		}
	}
};