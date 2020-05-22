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
Runtime: 80 ms, faster than 52.68% of C++ online submissions for Longest Increasing Path in a Matrix.
Memory Usage: 16.1 MB, less than 27.27% of C++ online submissions for Longest Increasing Path in a Matrix.
 */
class Solution {
  public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		m = matrix.size();
		if (!m) return 0;
		n = matrix[0].size();
		memo = vector<vector<int>> (m, vector<int>(n, -1)); // 初始为-1，表示没有被访问。
		int ans = INT_MIN;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				ans = max(dfs(matrix, i, j), ans);
			}
		}
		// for (int i = 0; i < m; i++) {
		// 	for (int j = 0; j < n; j++) {
		// 		cout << memo[i][j] << " " ;
		// 	}
		// 	cout << endl;
		// }
		return ans;
	}

  private:
	vector<vector<int>> memo;
	int m = 0;
	int n = 0;
	int dfs(vector<vector<int>>& matrix, int i, int j) {
		if (i < 0 || i >= m || j < 0 || j >= n )
			return -1;// out boarder
		if (memo[i][j] > 0) return memo[i][j]; // 正数表示已经访问过
		memo[i][j] = 0; // 表示此节点正在访问
		//因为有方向的访问，所以不用考虑访问父节点。
		if (i >= 1 && matrix[i][j] < matrix[i - 1][j])
			memo[i][j] = max(dfs(matrix, i - 1, j) + 1, memo[i][j]);

		if (i + 1 < m  && matrix[i][j] < matrix[i + 1][j])
			memo[i][j] = max(dfs(matrix, i + 1, j) + 1, memo[i][j]);

		if (j >= 1 && matrix[i][j] < matrix[i][j - 1])
			memo[i][j] = max(dfs(matrix, i, j - 1) + 1, memo[i][j]);

		if (j + 1 < n  && matrix[i][j] < matrix[i][j + 1] )
			memo[i][j] = max(dfs(matrix, i, j + 1) + 1, memo[i][j]);
		memo[i][j] = max(1, memo[i][j]);
		return memo[i][j];
	}
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
	int m, n;
	while (cin >> m >> n) {
		vector<vector<int>> grid(m, vector<int>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++ ) {
				cin >> grid[i][j];
			}
		}
		int ans = sol.longestIncreasingPath(grid);
		cout << ans << endl;
	}
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}