#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int a): val(a), next(NULL){}
};
class solution
{
public:
	void adaptor()
	{
		ListNode* head = new ListNode(1);
		int num = 2;
		ListNode* temp = head;
		while (num != 6)
		{
			temp->next = new ListNode(num++);
			temp = temp->next;
		}
		rotateRight(head, 2);
	}
private:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL)
			return head;
		vector<int> nums;
		ListNode* temp = head;
		int len = 0;
		while (temp != NULL)
		{
			len++;
			nums.push_back(temp->val);
			temp = temp->next;
		}
		k = k%len;
		nums.insert(nums.begin(), nums.end() - k, nums.end());
		nums.erase(nums.end() - k, nums.end());
		temp = head;
		for (int i = 0; i<nums.size(); i++)
		{
			temp->val = nums[i];
			temp = temp->next;
		}
		return head;
	}
};