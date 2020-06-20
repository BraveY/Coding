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
Runtime: 4 ms, faster than 69.46% of C++ online submissions for Subsets.
Memory Usage: 7.3 MB, less than 46.40% of C++ online submissions for Subsets.
 */
class Solution {
  public:
	vector<vector<int>> subsets(vector<int>& nums) {
		ans.push_back({});
		backtrack(nums, 0);
		return ans;


	}
	void backtrack(vector<int>& nums, int index) {
		for (int i = index; i < nums.size(); i++) {
			path.push_back(nums[i]);
			ans.push_back(path);
			backtrack(nums, i + 1);
			path.pop_back();
		}
	}

  private:
	vector<int> path;
	vector<vector<int>> ans;
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