#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class solution
{
public:
	void adaptor()
	{
		TreeNode * t1 = new TreeNode(1);
		TreeNode * t2 = new TreeNode(2);
		TreeNode * temp = t1;
		temp->left = new TreeNode(3);
		temp->right = new TreeNode(2);
		temp = temp->left;
		temp->left = new TreeNode(5);
		temp = t2;
		temp->left = new TreeNode(1);
		temp->right = new TreeNode(3);
		temp = temp->left;
		temp->right = new TreeNode(4);
		temp = t2->right;
		temp->right = new TreeNode(7);
		mergeTrees(t1, t2);
	}
private:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		TreeNode *root = new TreeNode(0);
		TreeNode * temp = root;
		mergeTree(temp, t1, t2);
		return root;
	}
	void mergeTree(TreeNode *& merge, TreeNode *t1, TreeNode * t2)
	{
		if (t1 == NULL && t2 == NULL)
		{
			merge = NULL;
		}
		else if (t1 == NULL)
		{
			merge->val = t2->val;
			merge->left = new TreeNode(0);
			merge->right = new TreeNode(0);
			mergeTree(merge->left, t1, t2->left);
			mergeTree(merge->right, t1, t2->right);
		}
		else if (t2 == NULL)
		{
			merge->val = t1->val;
			merge->left = new TreeNode(0);
			merge->right = new TreeNode(0);
			mergeTree(merge->left, t1->left, t2);
			mergeTree(merge->right, t1->right, t2);
		}
		else
		{
			merge->val = t1->val + t2->val;
			merge->left = new TreeNode(0);
			merge->right = new TreeNode(0);
			mergeTree(merge->left, t1->left, t2->left);
			mergeTree(merge->right, t1->right, t2->right);
		}

	}
};