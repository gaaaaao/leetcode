#include <iostream>
#include <vector>

using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class solution
{
public:
	void adaptor()
	{
		TreeLinkNode * root = new TreeLinkNode(1);
		root->left = new TreeLinkNode(2);
		root->right = new TreeLinkNode(3);
		root->left->left = new TreeLinkNode(4);
		root->left->right = new TreeLinkNode(5);
		root->right->right = new TreeLinkNode(7);
		connect(root);
	}
private:
	void connect(TreeLinkNode *root) {
		if (root == NULL)
			return;
		vector<TreeLinkNode*> layers;
		layers.push_back(root);
		while (!layers.empty())
		{
			int len = layers.size();
			for (int i = 0; i<len; i++)
			{
				if (i + 1 < len)
					layers[i]->next = layers[i + 1];
				if (layers[i]->left != NULL)
					layers.push_back(layers[i]->left);
				if (layers[i]->right != NULL)
					layers.push_back(layers[i]->right);
			}
			layers.erase(layers.begin(), layers.begin()+len);
		}
	}
};