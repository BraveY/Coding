#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <stack>

using namespace std;

/*
Runtime: 24 ms, faster than 79.92% of C++ online submissions for Evaluate Reverse Polish Notation.
Memory Usage: 12 MB, less than 72.32% of C++ online submissions for Evaluate Reverse Polish Notation.
 */
class Solution {
  public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;
		int pos = 0;
		int n = tokens.size();
		while (pos < n) {
			string op = tokens[pos];
			if (op != "+" && op != "-"
			        && op != "*" && op != "/") {
				s.push(atoi(op.c_str()));
			} else {
				int num2 = s.top();
				s.pop();
				int num1 = s.top();
				s.pop();
				int result = 0;
				if (op == "+") {
					result = num1 + num2;
				} else if (op == "-") {
					result = num1 - num2;
				} else if (op == "*") {
					result = num1 * num2;
				} else {
					result = num1 / num2;
				}
				s.push(result);
			}
			++pos;
		}
		return s.top();
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