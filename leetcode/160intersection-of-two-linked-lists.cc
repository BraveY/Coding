#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include "../mylist.h"
#include <unordered_set>

using namespace std;

/*
Runtime: 84 ms, faster than 24.50% of C++ online submissions for Intersection of Two Linked Lists.
Memory Usage: 17.6 MB, less than 15.39% of C++ online submissions for Intersection of Two Linked Lists.
 */
class Solution1 {
  public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		unordered_set<ListNode*> memo;
		ListNode* curA = headA;
		while (curA) {
			memo.insert(curA);
			curA = curA->next;
		}
		ListNode* curB = headB;
		while (curB) {
			if (memo.count(curB)) return curB;
			curB = curB->next;
		}
		return NULL;
	}

  private:
};
/*
two pointer,先到末尾的就是二者差值
到了相交节点的时候二者走过的路程都是B+C+A，刚好二者都相交。
Runtime: 52 ms, faster than 74.38% of C++ online submissions for Intersection of Two Linked Lists.
Memory Usage: 14.9 MB, less than 26.36% of C++ online submissions for Intersection of Two Linked Lists.
 */
class Solution {
  public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL) return NULL;
		ListNode* curA = headA;
		ListNode* curB = headB;
		while (curA != curB) {
			curA = curA == NULL ? headB : curA->next;
			curB = curB == NULL ? headA : curB->next;
		}
		return curA;
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