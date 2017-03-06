#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

class Unique_Binary_Search_Trees_II
{
public:
	void adpator();
private:
	vector<TreeNode *> res;
	vector<TreeNode*> generateTrees(int n);
	vector<TreeNode *> iter(int start, int end);
};

void Unique_Binary_Search_Trees_II::adpator()
{
}

vector<TreeNode*> Unique_Binary_Search_Trees_II::generateTrees(int n)
{

	return iter(1,n);
}

inline vector<TreeNode *> Unique_Binary_Search_Trees_II::iter(int start, int end)
{
	vector<TreeNode *> res;
	if (start > end)
	{
		res.push_back(NULL);
		return res;
	}
	for (int i = start; i <= end; i++)
	{
		vector<TreeNode *> left = iter(start, i - 1);
		vector<TreeNode *> right = iter(i + 1, end);
		for (TreeNode * l : left)
		{
			for (TreeNode * r : right)
			{
				TreeNode *root = new TreeNode(i);
				root->left = l;
				root->right = r;
				res.push_back(root);
			}
		}
	}
	return res;
	
}
