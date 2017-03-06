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

class Binary_Tree_Level_Order_Traversal
{
public:
	void adaptor();
private:
	vector<vector<int>> levelOrder(TreeNode* root);
};

inline void Binary_Tree_Level_Order_Traversal::adaptor()
{
	TreeNode *t = new TreeNode(3);
	t->left = new TreeNode(9);
	t->right = new TreeNode(20);
	levelOrder(t);
}

inline vector<vector<int>> Binary_Tree_Level_Order_Traversal::levelOrder(TreeNode * root)
{
	vector<vector<int>> res;
	if (root == NULL)
		return res;
	queue<TreeNode *> q;
	q.push(root);
	while (!q.empty())
	{
		vector<TreeNode *> tmp;
		vector<int> tval;
		while (!q.empty())
		{
			if (q.front() == NULL)
				continue;
			tmp.push_back(q.front());
			tval.push_back(q.front()->val);
			q.pop();
		}
		if (tmp.size() == 0)
			continue;
		for (int i = 0; i < tmp.size(); i++)
		{
			if (tmp[i]->left != NULL)
				q.push(tmp[i]->left);
			if (tmp[i]->right != NULL)
				q.push(tmp[i]->right);
		}
		res.push_back(tval);
		
	}
	return res;
}
