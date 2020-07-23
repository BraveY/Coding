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
 */
class Solution {
  public:
	bool isPalindrome(ListNode* head) {
		if (!head) return true;
		ListNode* slow = head;
		ListNode* fast = head->next;
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

	//一维数组的输入
	// vector<int> nums1 = {1, 2, 3, 0, 0, 0};
	// vector<int> nums2;
	// int i;
	// while (cin >> i) {
	// 	nums2.push_back(i);
	// }
	// cout << sol.solution(nums2) << endl;

	//二维数组的输入
	//int m, n;
	// while (cin >> m >> n) {
	// 	vector<vector<int>> grid(m, vector<int>(n));
	// 	for (int i = 0; i < m; i++) {
	// 		for (int j = 0; j < n; j++ ) {
	// 			cin >> grid[i][j];
	// 		}
	// 	}
	// 	int ans = sol.solution(grid);
	// 	cout << ans << endl;
	// }
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}