#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct treeNode
{
	string name;
	map<string, string> files;
	vector<treeNode*> children;
	treeNode() {}
	treeNode(string n, map<string, string> &hash) : files(hash),name(n) {}
};

class solution
{
public:
	void adaptor()
	{
		string a;
		a = 12;
		cout << a;
	}
private:

	vector<vector<string>> findDuplicate(vector<string>& paths) {
		int len = paths.size();
		if (len == 0)
			return vector<vector<string>>();
		treeNode* root = new treeNode();
		for (int i = 0; i<len; i++)
		{

		}
	}
};