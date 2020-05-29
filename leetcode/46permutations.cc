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
Runtime: 4 ms, faster than 92.44% of C++ online submissions for Permutations.
Memory Usage: 7.9 MB, less than 100.00% of C++ online submissions for Permutations.
 */
class Solution {
  public:
	vector<vector<int>> permute(vector<int>& nums) {
		int len = nums.size();
		vector<vector<int>> ans;
		if (len == 0) return ans;
		vector<int> path;
		vector<bool> used(len);
		backtrack(nums, len, 0, path, used, ans);
		return ans;
	}

  private:
	void backtrack(vector<int>& nums, int len, int depth,
	               vector<int>& path, vector<bool>& used, vector<vector<int>>& ans) {
		if (depth == len) {
			ans.push_back(path);
			return;
		}
		for (int i = 0; i < len; i++) {
			if (used[i]) continue;
			used[i] = true;
			path.push_back(nums[i]);
			backtrack(nums, len, depth + 1, path, used, ans);
			path.pop_back();
			used[i] = false;
		}
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