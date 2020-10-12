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
Runtime: 12 ms, faster than 51.92% of C++ online submissions for Increasing Triplet Subsequence.
Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Increasing Triplet Subsequence.
 */
class Solution {
  public:
	bool increasingTriplet(vector<int>& nums) {
		int n = nums.size();
		int c1 = INT_MAX, c2 = INT_MAX;
		for (int i = 0; i < n; ++i) {
			if (nums[i] <= c1) c1 = nums[i];
			else if (nums[i] <= c2) c2 = nums[i];
			else {
				return true;
			}
		}
		return false;
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