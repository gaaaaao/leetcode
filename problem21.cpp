#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Merge_Two_Sorted_Lists {
public:
	void adaptor();
private:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};

inline void Merge_Two_Sorted_Lists::adaptor()
{
	ListNode *l1 = new ListNode(-2);
	ListNode *temp = l1;
	temp->next = new ListNode(-1);
	temp = temp->next;
	temp->next = new ListNode(0);
	temp = temp->next;
	temp->next = new ListNode(1);

	ListNode *l2 = new ListNode(-1);
	temp = l2;
	temp->next = new ListNode(-1);
	temp = temp->next;
	temp->next = new ListNode(0);
	temp = temp->next;
	temp->next = new ListNode(1);

	ListNode *res = mergeTwoLists(l1, l2);
	temp = res;
	while (temp != NULL)
	{
		cout << temp->val << "\t";
		temp = temp->next;
	}
	cout << endl;
}

inline ListNode * Merge_Two_Sorted_Lists::mergeTwoLists(ListNode * l1, ListNode * l2)
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;

	ListNode *res;
	ListNode *temp1 = l1->next;
	ListNode *pre1 = l1;
	ListNode *temp2 = l2->next;
	ListNode *pre2 = l2;
	int sign = 0;

	while (pre1 != NULL & pre2 != NULL)
	{
		if (pre1->val <= pre2->val && temp1 != NULL && temp1->val >= pre2->val)
		{
			pre1->next = pre2;
			pre1 = temp1;
			temp1 = temp1->next;
		}
		else if (pre1->val > pre2->val && temp2 != NULL && temp2->val > pre1->val)
		{
			pre2->next = pre1;
			pre2 = temp2;
			temp2 = temp2->next;
		}
		else if (pre1->val < pre2->val && temp1 != NULL && temp1->val < pre2->val)
		{
			pre1 = temp1;
			temp1 = temp1->next;
		}
		else if (pre1->val >= pre2->val && temp2 != NULL && temp2->val <= pre1->val)
		{
			pre2 = temp2;
			temp2 = temp2->next;
		}
		else if (pre1->val <pre2->val && temp1 == NULL)
		{
			pre1->next = pre2;
			pre1 = temp1;
		}
		else if (pre1->val >= pre2->val && temp2 == NULL)
		{
			pre2->next = pre1;
			pre2 = temp2;
		}
	}

	if (l1->val < l2->val)
		return l1;
	else
	{
		return l2;
	}
}
