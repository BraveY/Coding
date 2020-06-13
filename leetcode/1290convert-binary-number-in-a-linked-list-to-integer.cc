#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include "../mylist.h"
#include <stack>

using namespace std;

/*
Runtime: 4 ms, faster than 37.20% of C++ online submissions for Convert Binary Number in a Linked List to Integer.
Memory Usage: 8.4 MB, less than 23.65% of C++ online submissions for Convert Binary Number in a Linked List to Integer.
 */
class Solution {
  public:
	int getDecimalValue(ListNode* head) {
		int ans = 0;
		stack<int> s;
		while (head) {
			s.push(head->val);
			head = head->next;
		}
		int digit = 0;
		while (!s.empty()) {
			ans += s.top() << digit;
			digit++;
			s.pop();
		}
		return ans;
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