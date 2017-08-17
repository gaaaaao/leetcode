#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class Swap_Nodes_in_Pairs
{
public:
	void adaptor();
private:
	ListNode* swapPairs(ListNode* head);
};

inline void Swap_Nodes_in_Pairs::adaptor()
{
	ListNode *head = new ListNode(0);
	ListNode *temp = head;

	for (int i = 1; i < 11; i++)
	{
		temp->next = new ListNode(i);
		temp = temp->next;
	}
	swapPairs(head);
	temp = head;
	while(temp != NULL)
	{
		cout << temp->val << "\t";
		temp = temp->next;
	}
	cout << endl;
}

inline ListNode * Swap_Nodes_in_Pairs::swapPairs(ListNode * head)
{
	if (head == NULL)
		return NULL;
	ListNode *n = head;
	ListNode *p = n;
	ListNode *nn = n;
	ListNode *pp = n;
	
	n = p->next;
	if (n == NULL)
		return head;
	
	nn = n->next;
	head = n;
	head->next = p;
	p->next = nn;
	if (nn == NULL || nn->next == NULL)
		return head;
	
	pp = p;
	p = nn;
	n = p->next;
	nn = n->next;

	
	while (nn != NULL && nn->next != NULL)
	{
		pp->next = n;
		n->next = p;
		p->next = nn;

		pp = p;
		p = nn;
		n = p->next;
		nn = n->next;
		
	}
	pp->next = n;
	n->next = p;
	p->next = nn;
	return head;
}
