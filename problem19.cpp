#include <iostream>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Remove_Nth_Node_From_End_of_List
{
public:
	void adaptor();
private:
	ListNode* removeNthFromEnd(ListNode* head, int n);
};

inline void Remove_Nth_Node_From_End_of_List::adaptor()
{
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	removeNthFromEnd(head, 5);
	
	ListNode *temp = head;
	while (temp != NULL)
	{
		cout << temp->val << "\t";
		temp = temp->next;
	}
	cout << endl;
}

inline ListNode * Remove_Nth_Node_From_End_of_List::removeNthFromEnd(ListNode * head, int n)
{
	/*int nodes = 0;
	ListNode *temp = head;
	while (temp != NULL)
	{
		temp = temp->next;
		nodes++;
	}
	if (nodes <= n)
	{
		head = head->next;
		return head;
	}
	temp = head;
	for (int i = 0; i < nodes - n - 1; i++)
		temp = temp->next;
	temp->next = temp->next->next;

	return head;*/
	ListNode *t = head;
	for (int i = 0; i < n + 1; i++)
	{
		if (t == NULL)
		{
			return head->next;
		}

		t = t->next;
	}
	ListNode *p = head;
	while (t != NULL)
	{
		t = t->next;
		p =  p->next;
	}
	p->next = p->next->next;
	return head;
}
