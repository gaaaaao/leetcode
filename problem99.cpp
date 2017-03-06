#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Recover_Binary_Search_Tree
{
public:
	void adaptor();
private:
	TreeNode *first = NULL;
	TreeNode *second = NULL;
	TreeNode *last = NULL;
	void recoverTree(TreeNode *root);
	void in_order(TreeNode *root);
};

void Recover_Binary_Search_Tree::adaptor()
{
}

void Recover_Binary_Search_Tree::recoverTree(TreeNode * root)
{
	in_order(root);
	if (first != NULL)
	{
		if (second != NULL)
			first->val = second->val;
	}
}

void Recover_Binary_Search_Tree::in_order(TreeNode * root)
{
	if (root == NULL)
	{
		if(last == NULL)
			last = root;
		return;
	}
	in_order(root->left);
	if (last != NULL && last->val > root->val)
		if (first == NULL)
		{
			first = last;
			second = root;
		}
		else
			second = root;
	last = root;
	in_order(root->right);
}
