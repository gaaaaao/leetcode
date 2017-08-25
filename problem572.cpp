#include <iostream>

using namespace std;

struct TreeNode {
    int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class solution
{
public:
	void adaptor()
	{
		
	}
private:
	TreeNode * temp;
	bool isSubtree(TreeNode* s, TreeNode* t) {
		temp = t;
		return tree(s, t);
	}
	bool tree(TreeNode *s, TreeNode *t)
	{
		if (s == NULL && t == NULL)
			return true;
		else if (s != NULL && t != NULL)
		{
			if (s->val == t->val && tree(s->right, t->right) && tree(s->left, t->left))
				return true;
			return tree(s->left, temp) || tree(s->right, temp);
		}
		return false;
	}
};