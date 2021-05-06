#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
// #include <.h>
#include "../mylist.h"

using namespace std;

/*
Runtime: 40 ms, faster than 100.00% of C++ online submissions for Sort List.
Memory Usage: 12.8 MB, less than 25.00% of C++ online submissions for Sort List.
 */
class Solution {
 public:
	ListNode* sortList(ListNode* head) {
		if (!head || !head->next) return head; //递归必备的出口
		ListNode* slow = head;
		ListNode*	fast = head->next;
		// 寻找中间的节点
		while (fast && fast->next) {
			//fast 刚好到达末尾的时候 fast->next 为nullptr
			//或者刚好超过末尾1个，fast为nullptr
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* l2 = slow->next;
		slow->next = NULL;// 中间断开
		head = sortList(head);
		l2 = sortList(l2);
		head = merge(head, l2);//merge到前半部分上面
		return head;
	}

 private:
	ListNode* merge(ListNode* l1, ListNode* l2) {
		ListNode dummy(0);
		ListNode* tail = &dummy;
		while (l1 && l2) {
			if (l1->val > l2->val) swap(l1, l2);
			// swap 交换的是变量值，对链表而言，交换了整个链表。
			//始终让l1指向当前最小的头节点的链表，简洁些，不用if else
			tail->next = l1;
			l1 = l1->next;
			tail = tail->next;
		}
		tail->next = l1 ? l1 : l2;
		return dummy.next;
	}
};



// Author: Huahua
// Running time: 32 ms
class Solution2 {
 public:
	ListNode* sortList(ListNode* head) {
		// 0 or 1 element, we are done.
		if (!head || !head->next) return head;

		int len = 1;
		ListNode* cur = head;
		while (cur = cur->next) ++len;

		ListNode dummy(0);// 存储在栈区，因为head不停在变化所以需要
		dummy.next = head;
		ListNode* l;
		ListNode* r;
		ListNode* tail;//代表已经合并好的链表末尾
		for (int n = 1; n < len; n <<= 1) {//自下而上构建 
			cur = dummy.next; // partial sorted head 待排序与合并的链表
			tail = &dummy;
			while (cur) {//划分成长度为n的小块然后合并
				l = cur;
				r = split(l, n);
				cur = split(r, n);
				auto merged = merge(l, r);
				tail->next = merged.first;  // 合并list的head 让前面合并后末尾指向新合并的头
				tail = merged.second; // 合并list的tail ，然后重新指向新合并的末尾 pair 有成员first，和second 不是函数
			}
		}
		return dummy.next;
	}
 private:
	// Splits the list into two parts, first n element and the rest.
	// Returns the head of the rest.
	ListNode* split(ListNode* head, int n) { //包含head节点，长度为n
		while (--n && head) // 分割的长度可能超过head 的长度 ，比如需要分割2个，但是只有1个剩余的节点
			head = head->next;
		ListNode* rest = head ? head->next : nullptr;
		if (head) head->next = nullptr; // 如果有连接 就断开
		return rest;
	}

	// Merges two lists, returns the head and tail of the merged list.
	pair<ListNode*, ListNode*> merge(ListNode* l1, ListNode* l2) {
		ListNode dummy(0);
		ListNode* tail = &dummy;
		while (l1 && l2) {
			if (l1->val > l2->val) swap(l1, l2);
			tail->next = l1;
			l1 = l1->next;
			tail = tail->next;
		}
		tail->next = l1 ? l1 : l2; // 剩下的连上
		while (tail->next) tail = tail->next; //找到末尾， 方便后续的接
		return {dummy.next, tail};
	}
};

void debug() {
	vector<int> nums = { 4, 5, 6, 1, 2, 3};
	vector<int> nums1 = { 7, 8, 9};

	ListNode* dummy = createList(nums);
	ListNode* dummy1 = createList(nums1);
	coutList(dummy);
	swap(dummy, dummy1);
	// Solution sol;
	coutList(dummy);
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	Solution sol;
	vector<int> nums = {1, 2, 3, 4, 5, 6};
	debug();
	// cout << sol.solution() << endl;
	system("pause");
	return 0;
}