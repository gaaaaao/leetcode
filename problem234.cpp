#include <iostream>
#include <vector>
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
		vector<int> a = { 1,2,3,2,1 };
		int len = a.size();
		ListNode *head = new ListNode(1);
		ListNode *temp = head;
		
		for (int i = 1; i < len; i++)
		{
			temp->next = new ListNode(a[i]);
			temp = temp->next;
		}
		cout << isPalindrome(head) << endl;
	}
private:
	ListNode *front;
	bool isPalindrome(ListNode* head)
	{
		ListNode *back = head;
		ListNode *skip = head;
		return Pali(head, back, skip);
	}
	bool Pali(ListNode *root, ListNode *back, ListNode *skip)
	{
		bool temp;
		if (skip != NULL && skip->next != NULL)
		{
			temp = Pali(root, back->next, skip->next->next);
		}
		else
		{
			if (skip == NULL)
				front = back;
			else if (skip->next == NULL)
				front = back->next;
			return true;
		}
		if (!temp)
			return false;
		else
		{
			if (back->val == front->val)
			{
				front = front->next;
				return true;
			}
			else
				return false;
		}
	}
};