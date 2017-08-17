#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class solution
{
public:
	void adaptor()
	{
		vector<int> nums = {8, 2, 4, 4, 4, 9, 5, 2, 5, 8, 8, 0, 8, 6, 9, 1, 1, 6, 3, 5, 1, 2, 6, 6, 0, 4, 8, 6, 0, 3, 2, 8, 7, 6, 5, 1, 7, 0, 3, 4, 8, 3, 5, 9, 0, 4, 0, 1, 0, 5, 9, 2, 0, 7, 0, 2, 1, 0, 8, 2, 5, 1, 2, 3, 9, 7, 4, 7, 0, 0, 1, 8, 5, 6, 7, 5, 1, 9, 9, 3, 5, 0, 7, 5};
		cout << canJump(nums) << endl;
	}
private:
	bool canJump(vector<int>& nums) {
		if (nums.size() == 0)
			return false;
		int last = nums.size() - 1;
		if (last == 0)
			return true;
		queue<vector<int>::iterator> q;
		map<vector<int>::iterator, bool> hash;
		q.push(nums.begin());
		while (!q.empty())
		{
			
			vector<int>::iterator temp = q.front();
			q.pop();
			hash[temp] = 0;
			for (int i = 1; i <= *temp; i++)
			{
				if ((temp - nums.begin()) + i == last)
					return true;
				if (hash[temp + i])
					continue;
				q.push(temp + i);

			}
		}
		return false;
	}
};