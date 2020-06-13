#include <iostream>
#include <vector>


using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* createList(vector<int>& nums) {
	ListNode* head = new ListNode(nums[0]);
	if (!head) {
		cout << "head is null" << endl;
		return NULL;
	}
	ListNode* tail = head;
	for (int i = 1; i < nums.size(); i++) {
		ListNode* item = new ListNode(nums[i]); //new 返回的是地址
		tail->next = item;
		tail = tail->next;
	}
	return head;
}

void deleteList(ListNode* head) {
	while (head) {
		ListNode* cur = head;
		head = head->next;
		delete cur;
	}
}

void coutList(ListNode* head) {
	while (head) {
		cout << head->val << ' ';
		head = head->next;
	}
	cout << endl;
}

void list_debug() {
	vector<int> nums = {1, 2, 3, 4, 5, 6};
	ListNode* dummy = createList(nums);

	coutList(dummy);
	deleteList(dummy);
}
