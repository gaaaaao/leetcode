#include <iostream>
#include <algorithm>

#define MIN -10000

using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Binary_Tree_Maximum_Path_Sum {
public:
	void adaptor();
private:
	int maxPathSum(TreeNode* root);
	int countmax(TreeNode *root, int &maxx);
};

inline void Binary_Tree_Maximum_Path_Sum::adaptor()
{
	TreeNode *head = new TreeNode(1);
	TreeNode *temp = head;
	head->left = new TreeNode(2);
	head->right = new TreeNode(8);
	temp = head->left;
	temp->left = new TreeNode(4);
	temp->right = new TreeNode(5);
	temp = head->right;
	temp->left = new TreeNode(9);
	temp->right = new TreeNode(10);
	

	cout << maxPathSum(head) << endl;
}

inline int Binary_Tree_Maximum_Path_Sum::maxPathSum(TreeNode * root)
{
	if (root == NULL)
		return 0;
	int maxx = MIN;
	countmax(root, maxx);
	return maxx;
}

inline int Binary_Tree_Maximum_Path_Sum::countmax(TreeNode * root, int &maxx)
{
	if (root == NULL)
		return 0;
	int l = countmax(root->left, maxx);
	int r = countmax(root->right, maxx);
	maxx = max(maxx, max(l,0) + max(r,0) + root->val);

	return max(max(l, r),0) + root->val;
}
