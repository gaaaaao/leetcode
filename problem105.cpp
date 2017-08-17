#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal
{
public:
	void adpator();
private:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
	TreeNode * iter(vector<int> &inorder, vector<int> &preorder, int li, int ri, int lp, int rp);
};

void Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal::adpator()
{
}

TreeNode * Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal::buildTree(vector<int>& preorder, vector<int>& inorder)
{
	return iter(inorder, preorder, 0, inorder.size() - 1, 0, preorder.size() - 1);
}

TreeNode * iter(vector<int> &inorder, vector<int> &preorder, int li, int ri, int lp, int rp)
{
	if (lp > rp)
		return NULL;

	TreeNode *root = new TreeNode(preorder[lp]);

	for (int i = li; i <= ri; i++)
	{
		if (inorder[i] == root->val)
		{
			root->left = iter(inorder, preorder, li, i - 1, lp + 1, lp + (i - li));
			root->right = iter(inorder, preorder, i + 1, ri, lp + (i - li) + 1, rp);
		}
	}
	return root;
}