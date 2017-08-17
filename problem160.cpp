#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class solution
{
public:
	void adaptor()
	{
		ListNode *a = new ListNode(2);
		a->next = new ListNode(4);
		ListNode *b = new ListNode(1);
		b->next = new ListNode(3);
		b->next->next = new ListNode(5);
		a->next->next = new ListNode(6);
		b->next->next->next = a->next->next;
		ListNode *c = getIntersectionNode(a, b);
		cout << c->val << endl;
	}
private:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		ListNode *a = headA;
		ListNode *b = headB;
		while (a != NULL && b != NULL)
		{
			if (a == b)
				return a;
			if (a == NULL)
				a = headB;
			if (b == NULL)
				b = headA;
			a = a->next;
			b = b->next;
		}
		return a;
	}
};