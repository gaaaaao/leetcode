#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int a): val(a),next(NULL){}
};
class solution
{
public:
	void adaptor()
	{
		ListNode* head = new ListNode(4);
		ListNode* temp = head;
		temp->next = new ListNode(1);
		temp = temp->next;
		temp->next = new ListNode(2);
		temp = temp->next;
		temp->next = new ListNode(3);
		temp = temp->next;
		temp->next = new ListNode(5);
		temp = temp->next;
		insertionSortList(head);
		if (0 < 3)
			cout << "asdfa";
	}
private:
	ListNode* insertionSortList(ListNode* head) {
		ListNode* temp = head->next;
		ListNode* newnode = head;
		head->next = NULL;
		while (temp != NULL)
		{
			ListNode *insertnode = temp;
			temp = temp->next;
			insertnode->next = NULL;
			if (insertnode->val <= head->val)
			{
				insertnode->next = head;
				head = insertnode;
			}
			else
			{
				newnode = head;
				while (!(newnode->next != NULL || newnode->next->val > insertnode->val))
				{
					newnode = newnode->next;
				}
				insertnode->next = newnode->next;
				newnode->next = insertnode;
			}
		}
		return head;
	}
};