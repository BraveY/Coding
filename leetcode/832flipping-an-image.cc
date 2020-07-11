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
Runtime: 8 ms, faster than 84.72% of C++ online submissions for Flipping an Image.
Memory Usage: 8.8 MB, less than 68.47% of C++ online submissions for Flipping an Image.
 */
class Solution {
  public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		int m = A.size();
		int n = A[0].size();
		vector<vector<int>> ans(m, vector<int>(n));
		for (int i = 0; i < m ; i++) {
			for (int j = 0; j < n; j++) {
				ans[i][n - 1 - j] = !A[i][j];
			}
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
	vector<vector<int>> grid = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
	sol.flipAndInvertImage(grid);
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