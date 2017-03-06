#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Validate_Binary_Search_Tree
{
public:
	void adaptor();
private:
	bool isValidBST(TreeNode* root);
	bool iter(TreeNode *root, long min, long max);
};

void Validate_Binary_Search_Tree::adaptor()
{
}

bool Validate_Binary_Search_Tree::isValidBST(TreeNode * root)
{
	long min = -21474836480;
	long max = 21474836470;
	return iter(root, min, max);
}

bool Validate_Binary_Search_Tree::iter(TreeNode * root, long min, long max)
{
	if (root == NULL)
	{
		return true;
	}
	if (root->val > min && root->val < max)
	{
		return iter(root->left, min, root->val) &&
			iter(root->right, root->val, max);
	}
	else
	{
		return false;
	}
}
