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
Runtime: 4 ms, faster than 83.01% of C++ online submissions for Remove Nth Node From End of List.
Memory Usage: 10.7 MB, less than 5.27% of C++ online submissions for Remove Nth Node From End of List.
 */
class Solution1 {
  public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* cur = head;
		vector<ListNode*> nodes;
		while (cur) {
			nodes.push_back(cur);
			cur = cur->next;
		}
		int len = nodes.size();
		if (len == 1) {
			delete head;
			return NULL;
		}
		int pos = len - n ;
		if (pos == len - 1) nodes[pos - 1] ->next = NULL;
		else if (pos == 0) {
			delete head;
			return nodes[pos + 1];
		} else {
			nodes[pos - 1]->next = nodes[pos + 1];
		}
		delete nodes[pos];
		return head;
	}

  private:
};

/*
Runtime: 4 ms, faster than 83.01% of C++ online submissions for Remove Nth Node From End of List.
Memory Usage: 10.4 MB, less than 72.66% of C++ online submissions for Remove Nth Node From End of List.
卡尺的概念，构建两个指针，快指针与慢指针差n个。
 */
class Solution {
  public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head) return nullptr;
		ListNode newHead(-1);
		newHead.next = head;
		ListNode* fast = &newHead; //指向head无法删除head
		ListNode* slow = &newHead;
		for (int i = 0; i < n; ++i) {//快指针移动n步，与慢指针相差n个节点
			fast = fast->next;
		}
		while (fast->next) { //需要指向待删除节点的上一个
			fast = fast->next;
			slow = slow->next;
		}
		ListNode* toDelete =  slow->next;
		slow->next = slow->next->next;
		delete toDelete;//传入指针 防止内存泄漏
		return newHead.next;
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