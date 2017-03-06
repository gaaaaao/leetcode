#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Binary_Tree_Inorder_Traversal
{
public:
	void adaptor();
private:
	vector<int> res;
	vector<int> inorderTraversal(TreeNode* root);
	void iter(TreeNode *root);
};

inline void Binary_Tree_Inorder_Traversal::adaptor()
{
}

inline vector<int> Binary_Tree_Inorder_Traversal::inorderTraversal(TreeNode * root)
{
	iter(root);
	return res;
}

void Binary_Tree_Inorder_Traversal::iter(TreeNode * root)
{
	if (root->left != NULL)
	{
		iter(root->left);
	}
	res.push_back(root->val);

	if (root->right != NULL)
	{
		iter(root->left);
	}

}
