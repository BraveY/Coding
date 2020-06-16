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
Runtime: 32 ms, faster than 75.21% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
Memory Usage: 10.5 MB, less than 69.03% of C++ online submissions for Count Negative Numbers in a Sorted Matrix.
 */
class Solution {
  public:
	int countNegatives(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int count = 0;
		for ( int i = m - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				if (grid[i][j] >= 0) break;
				count++;
			}
		}
		return count;
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