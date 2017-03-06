#include <iostream>

using namespace std;

struct RandomListNode
{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL){}
};

class Copy_List_with_Random_Pointer
{
public:
	void adaptor();
private:
	RandomListNode *copyRandomList(RandomListNode *head);
	int printfuc(RandomListNode *head);
};

inline void Copy_List_with_Random_Pointer::adaptor()
{
	RandomListNode *head = new RandomListNode(1);
	RandomListNode *temp = head;
	temp->next = new RandomListNode('#');
	printfuc(head);
	
	/*temp = head;
	temp->random = temp->next;
	temp = temp->next;
	temp->random = head;
	temp = temp->next;*/
	

	printfuc(copyRandomList(head));

}

inline RandomListNode * Copy_List_with_Random_Pointer::copyRandomList(RandomListNode * head)
{
	if (!head)
		return head;
	RandomListNode *temp1, *temp2, *view, *copyhead, *view2;
	view = head;
	while (view->next)
	{
		temp1 = view->next;
		view->next = new RandomListNode(view->label);
		view->next->next = temp1;
		view = view->next->next;
	}
	view->next = new RandomListNode(view->label);

	view = head;
	while(view->next->next)
	{
		if (view->random)
		{
			view->next->random = view->random->next;
		}
			view = view->next->next;
	}
	if(view->random)
		view->next->random = view->random->next;

	copyhead = head->next;
	view2 = head;
	temp1 = copyhead;
	temp2 = copyhead;
	view = head;
	while (temp1->next)
	{
		temp2 = temp1->next->next;
		view2 = view->next->next;
		temp1->next = temp2;
		view->next = view2;
		temp1 = temp2;
		view = view2;
	}
	view->next = NULL;
	return copyhead;
}

inline int Copy_List_with_Random_Pointer::printfuc(RandomListNode * head)
{
	RandomListNode *temp = head;
	while (temp->next)
	{
		cout << temp->label << " -> ";
		temp = temp->next;
	}
	cout << temp->label << endl;
	return 0;
}
