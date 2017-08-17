#include <iostream>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int a) : val(a), left(NULL), right(NULL) {};
};
class solution
{
public:
	void adaptor()
	{
		TreeNode * root = new TreeNode(1);
		TreeNode * temp = root;
		temp->left = new TreeNode(2);
		temp->left->left = new TreeNode(3);
		temp->left->right = new TreeNode(4);
		temp->right = new TreeNode(5);
		temp->right->right = new TreeNode(6);
		flatten(root);
	}
private:
	void flatten(TreeNode* root) {
		dfs(root);
	}
	TreeNode* dfs(TreeNode *& root)
	{
		if (root->right == NULL && root->left == NULL)
			return root;
		if (root->left == NULL)
		{
			return dfs(root->right);
		}
		if (root->right == NULL)
		{
			root->right = root->left;
			return dfs(root->right);
		}
		TreeNode * right = root->right;
		root->right = root->left;
		TreeNode * last = dfs(root->right);
		last->right = right;
		return dfs(right);
	}
};