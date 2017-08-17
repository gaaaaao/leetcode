#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	
};

class Merge_k_Sorted_Lists
{
public:
	void adpator();
private:
	ListNode* mergeKLists(vector<ListNode*>& lists);
	int min(vector<ListNode *> ind);
};

inline void Merge_k_Sorted_Lists::adpator()
{
	vector<ListNode *> heads;
	ListNode *head = new ListNode(1);
	heads.push_back(head);

	mergeKLists(heads);
}

inline ListNode * Merge_k_Sorted_Lists::mergeKLists(vector<ListNode*>& lists)
{
	int len = lists.size();
	if (len == 0)
		return NULL;
	vector<ListNode *> ind;
	ListNode *res = NULL;
	int minind = 0;
	ListNode *temp;
	for (vector<ListNode *>::iterator iter = ind.begin(); iter != ind.end(); iter++)
	{
		if (*iter == NULL)
			continue;
		ind.push_back(*iter);
	}
	for (int i = 0;i<len;i++)
	{
		if (lists[i] == NULL)
			continue;
		ind.push_back(lists[i]);
	}
	if (ind.empty())
		return NULL;
	minind = min(ind);
	res = ind[minind];
	temp = res;
	if (ind[minind]->next == NULL)
		ind.erase(ind.begin() + minind);
	else
		ind[minind] = ind[minind]->next;

	while (!ind.empty())
	{
		minind = min(ind);
		temp->next = new ListNode(ind[minind]->val);
		temp = temp->next;
		if (ind[minind]->next == NULL)
			ind.erase(ind.begin()+minind);
		else
			ind[minind] = ind[minind]->next;
	}
	return res;
}

inline int Merge_k_Sorted_Lists::min(vector<ListNode *> ind)
{
	int len = ind.size();
	int min = 10000;
	int res = -1;
	for (int i = 0; i < len; i++)
	{
		if (ind[i]->val < min)
		{
			res = i;
			min = ind[i]->val;
		}
	}
	return res;
}


