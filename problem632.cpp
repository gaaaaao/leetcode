#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

class solution
{
	struct Node
	{
		int ind;
		int val;
		Node(int i, int v): ind(i), val(v){}
	};
	struct cmp
	{
		bool operator()(const Node & a, const Node & b)
		{
			return a.val > b.val;
		}
	};
public:
	void adaptor()
	{
		vector<vector<int>> nums = { {4, 10, 15, 24, 26},{0, 9, 12, 20},{5, 18, 22, 30} };
		smallestRange(nums);
	}
private:
	vector<int> smallestRange(vector<vector<int>>& nums) {
		vector<int> cur(nums.size(), 0);
		vector<int> res(2, 0);
		priority_queue<Node, vector<Node>, cmp> min;
		int minval = 2147483647;
		int maxval = -2147483648;
		for (int i = 0; i<cur.size(); i++)
		{
			if (nums[i][cur[i]] > maxval)
				maxval = nums[i][cur[i]];
			min.push(Node(i,nums[i][cur[i]]));
		}
		while (1)
		{
			Node temp = min.top();
			int ind = temp.ind; 
			min.pop();
			if (maxval - nums[ind][cur[ind]] < minval)
			{
				minval = maxval - nums[ind][cur[ind]];
				res[0] = nums[ind][cur[ind]];
				res[1] = maxval;
			}
			if (cur[ind] == nums[ind].size() - 1)
				return res;

			if (cur[ind] + 1 < nums[ind].size())
			{
				cur[ind]++;
				min.push(Node(ind, nums[ind][cur[ind]]));
			}
			if (nums[ind][cur[ind]] > maxval)
				maxval = nums[ind][cur[ind]];
		}
	}
	int minindex(vector<vector<int>> & nums, vector<int> & cur)
	{
		int ind = 0;
		for (int i = 0; i<cur.size(); i++)
		{
			if (nums[i][cur[i]] < nums[ind][cur[ind]])
			{
				ind = i;
			}
		}
		return ind;
	}
};