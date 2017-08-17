#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int a) : val(a), next(NULL) {}
};

class solution
{
public:
	void adaptor()
	{
		ListNode* head = new ListNode(1);
		ListNode* temp = head;
		temp->next = new ListNode(2);
		temp = temp->next;
		temp->next = new ListNode(3);
		temp = temp->next;
		temp->next = new ListNode(3);
		temp = temp->next;
		temp->next = new ListNode(4);
		temp = temp->next;
		deleteDuplicates(head);
	}
private:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL)
			return head;
		ListNode* mock = new ListNode(head->val);
		mock->next = head;
		head = mock;
		ListNode* r = head;
		ListNode* t = head->next;
		while (t->next != NULL)
		{
			if (t->next->val != r->next->val)
			{
				r = r->next;
				t = t->next;
			}
			else
			{
				while (t->next != NULL)
				{
					t = t->next;
					if (t->next->val != r->next->val)
						break;
				}
				r->next = t->next;
				t = t->next;
			}
		}
		head = head->next;
		return head;
	}
};