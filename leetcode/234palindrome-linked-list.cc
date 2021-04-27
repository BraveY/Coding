/*
 * @Author: your name
 * @Date: 2020-07-22 08:33:55
 * @LastEditTime: 2021-04-26 09:19:39
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode\234palindrome-linked-list.cc
 */
#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include "../mylist.h"

using namespace std;

/*
Runtime: 32 ms, faster than 66.66% of C++ online submissions for Palindrome Linked List.
Memory Usage: 14.1 MB, less than 67.52% of C++ online submissions for Palindrome Linked List.
如果节点为偶数，则左右两个一人一半，如果为奇数则左边多一个，但按照右边的个数来循环比较就可以了。
 */
class Solution {
  public:
	bool isPalindrome(ListNode* head) {
		if (!head) return true;
		ListNode* slow = head;
		ListNode* fast = head->next;// 考虑两个节点的情况
		while (fast && fast->next) {
			slow = slow ->next;
			fast = fast->next->next;
		}
		ListNode* right = slow->next;
		if (!right) return true;
		ListNode* cur = right->next;
		ListNode* curLast = right;
		slow->next = NULL;
		curLast->next = NULL;
		ListNode* left = head;
		while (cur) {
			ListNode* tmpNext = cur->next;
			cur->next = curLast;
			curLast = cur;
			cur = tmpNext;
		}
		right = curLast;
		while (right) {
			if (right->val != left->val) return false;
			right = right->next;
			left = left->next;
		}
		return true;
	}

  private:
};

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}

void debug() {
	Solution sol;
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}