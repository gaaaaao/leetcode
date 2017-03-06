#include <iostream>
#include <deque>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Symmetric_Tree
{
public:
	void adaptor();
private:
	bool isSymmetric(TreeNode* root);
};

void Symmetric_Tree::adaptor()
{
}

bool Symmetric_Tree::isSymmetric(TreeNode * root)
{
	if (root == NULL)
		return false;
	TreeNode *temp = root;
	deque<TreeNode *> dq;
	dq.push_back(root->right);
	dq.push_front(root->left);
	TreeNode *front;
	TreeNode *end;

	while (!dq.empty())
	{
		front = dq.front();
		end = dq.back();
		dq.pop_back();
		dq.pop_front();

		if (front == NULL ^ end == NULL)
			return false;
		if (front != NULL && front->val != end->val)
			return false;
		if (front != NULL)
		{
			dq.push_front(front->right);
			dq.push_front(front->left);
			dq.push_back(end->left);
			dq.push_back(end->right);
		}
	}
	return true;
}
