#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix.
Memory Usage: 6.8 MB, less than 90.86% of C++ online submissions for Spiral Matrix.
 */
class Solution {
  public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (!m) return {};
		int n = matrix[0].size();
		if (!n) return {};
		vector<int> ans;
		int top = 0, down = m - 1;
		int left = 0, right = n - 1;
		while (top <= down || left <= right) {
			if (ans.size() == m * n) break;
			for (int i = left; i < right; ++i) {
				ans.push_back(matrix[top][i]);
			}
			if (top == down) { // one row
				ans.push_back(matrix[top][right]);
				break;
			} else {
				for (int i = top; i < down; ++i) {
					ans.push_back(matrix[i][right]);
				}
				if (right == left) { // one col
					ans.push_back(matrix[down][right]);
					break;
				} else {
					for (int i = right; i > left; --i) {
						ans.push_back(matrix[down][i]);
					}

					for (int i = down; i > top; --i) {
						ans.push_back(matrix[i][left]);
					}
				}
			}
			++top;
			--right;
			--down;
			++left;
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