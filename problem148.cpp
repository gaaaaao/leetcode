#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int a): val(a),next(NULL){}
};
class solution
{
public:
	void adaptor()
	{
		ListNode* head = new ListNode(7);
		int val = 2;
		auto temp = head;
		while (val != 6)
		{
			temp->next = new ListNode(val++);
			temp = temp->next;
		}
		sortList(head);
		if (0 < 2)
			cout << "wrong" << endl;
		cout << "aa" << endl;
	}
private:
	ListNode* sortList(ListNode*& head) {
		ListNode* temp = head;
		mergesort(head);
		return head;
	}
	void mergesort(ListNode*& head)
	{
		if (head == NULL || head->next == NULL)
			return;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast->next != NULL)
		{
			fast = fast->next;
			if (fast->next == NULL)
				break;
			fast = fast->next;
			slow = slow->next;
			
		}
		fast = slow->next;
		slow->next = NULL;
		mergesort(head);
		mergesort(fast);
		slow = head;
		if (slow->val < fast->val)
		{
			head = slow;
			slow = slow->next;
		}
		else
		{
			head = fast;
			fast = fast->next;
		}
		ListNode* temp = head;

		while (slow != NULL || fast != NULL)
		{
			if (slow == NULL)
			{
				temp->next = fast;
				fast = fast->next;
				temp = temp->next;
				continue;
			}
			if (fast == NULL)
			{
				temp->next = slow;
				slow = slow->next;
				temp = temp->next;
				continue;
			}
			if (slow->val > fast->val)
			{
				temp->next = fast;
				fast = fast->next;
			}
			else
			{
				temp->next = slow;
				slow = slow->next;
			}
			temp = temp->next;
		}

	}
};