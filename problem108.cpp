#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int a) : val(a), left(NULL), right(NULL) {}
};
class solution
{
public:
	void adaptor() 
	{
		vector<int> a = {  };
		sortedArrayToBST(a);
	}
private:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)
			return NULL;
		TreeNode *head = new TreeNode(0);
		TreeNode *temp = head;
		insertNode(nums, 0, nums.size() - 1, temp);
		return head;
	}

	void insertNode(vector<int> &nums, int start, int end, TreeNode *&current)
	{
		if (start > end)
		{
			current = NULL;
			return;
		}
		if (start == end)
		{
			current->val = nums[(start + end) / 2];
			return;
		}
		else
		{
			int temp = ceil(((double)start+end)/2);
			current->val = nums[temp];
			current->left = new TreeNode(0);
			insertNode(nums, start, temp - 1, current->left);
			current->right = new TreeNode(0);
			insertNode(nums, temp + 1, end, current->right);
		}
	}
};