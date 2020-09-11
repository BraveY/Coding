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
Runtime: 20 ms, faster than 24.69% of C++ online submissions for Odd Even Linked List.
Memory Usage: 10.9 MB, less than 5.04% of C++ online submissions for Odd Even Linked List.
 */
class Solution {
  public:
	ListNode* oddEvenList(ListNode* head) {
		if (!head) return nullptr;
		ListNode* oddHead = nullptr;
		ListNode* oddTail = nullptr;
		ListNode* evenHead = nullptr;
		ListNode* evenTail = nullptr;
		ListNode* cur = head;
		int num = 1;
		while (cur) {
			if ((num & 1) == 0) {
				if (!evenHead) {
					evenHead = cur;
					evenTail = cur;
				} else {
					evenTail->next = cur;
					evenTail = cur;
				}
			} else {
				if (!oddHead) {
					oddHead = cur;
					oddTail = cur;
				} else {
					oddTail->next = cur;
					oddTail = cur;
				}
			}
			cur = cur->next;
			++num;
		}

		head = oddHead;
		oddTail->next = evenHead;
		if (evenTail) evenTail->next = nullptr;

		return head;
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

	vector<int> nums = {1, 2, 3, 4, 5, 6};
	ListNode* dummy = createList(nums);
	coutList(sol.oddEvenList(dummy));
	coutList(dummy);
	deleteList(dummy);

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