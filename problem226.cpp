#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Invert_Binary_Tree
{
public:
	void adaptor();
private:
	TreeNode* invertTree(TreeNode* root);
	void iter(TreeNode *root);
};

void Invert_Binary_Tree::adaptor()
{
}

TreeNode * Invert_Binary_Tree::invertTree(TreeNode * root)
{
	iter(root);
	return root;
}

void Invert_Binary_Tree::iter(TreeNode * root)
{
	if (root == NULL)
		return;
	TreeNode *temp = root->left;
	root->left = root->right;
	root->right = temp;
	iter(root->left);
	iter(root->right);
}
