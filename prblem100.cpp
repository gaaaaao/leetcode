#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
class Same_Tree
{
public:
	void adpator();
private:
	bool sign = true;
	bool isSameTree(TreeNode* p, TreeNode* q);
	void iter(TreeNode *p, TreeNode *q);
};

void Same_Tree::adpator()
{
}

bool Same_Tree::isSameTree(TreeNode * p, TreeNode * q)
{
	iter(p, q);
	return sign;
}

void Same_Tree::iter(TreeNode * p, TreeNode * q)
{
	if (sign == false)
		return;
	if (p != NULL && q != NULL)
	{
		iter(p->left, q->left);
		iter(p->right, q->right);
		if (p->val != q->val)
			sign = false;
	}
	else if (p != NULL ^ q != NULL)
	{
		sign = false;
	}
	
}
