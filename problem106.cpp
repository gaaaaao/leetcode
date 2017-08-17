#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val = 0;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class solution
{
public:
	void adaptor() 
	{
		vector<int> inorder = { 7,9,6,5,8,10,4 };
		vector<int> postorder = {7,6,9,8,4,10,5};
		buildTree(inorder, postorder);
	}
private:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.empty() || postorder.empty())
			return NULL;
		int root_index = postorder.size() - 1;
		return createBST(inorder, postorder, 0, root_index, root_index);
	}
	TreeNode* createBST(vector<int>& inorder, vector<int>& postorder, int start, int end, int& index) {
		int v = postorder[index];
		int i = end;
		for (i; i >= start; i--)
			if (inorder[i] == v)
				break;
		TreeNode* root = new TreeNode(v);
		if (end >= i + 1)
			root->right = createBST(inorder, postorder, i + 1, end, --index);
		if (i - 1 >= start)
			root->left = createBST(inorder, postorder, start, i - 1, --index);

		return root;
	}
};