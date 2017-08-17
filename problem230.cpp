#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Kth_Smallest_Element_in_a_BST
{
public:
	void adpator();
private:
	int res = 0;
	int count = 0;
	int kthSmallest(TreeNode* root, int k) {
		inorder(root, k);
		if (count == -1)
			return res;
		else
		{
			return -1;
		}
	}
	void inorder(TreeNode *root, int k)
	{
		if (root != NULL)
		{
			inorder(root->left, k);
			if (count == -1)
				return;
			else
				count++;
			if (count == k)
			{
				res = root->val;
				count = -1;
			}
			inorder(root->right, k);
		}
	}
};

inline void Kth_Smallest_Element_in_a_BST::adpator()
{
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right = new TreeNode(6);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(7);
	cout << kthSmallest(root, 2) << endl;
}


