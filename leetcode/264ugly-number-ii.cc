#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
/*
Runtime: 16 ms, faster than 50.75% of C++ online submissions for Ugly Number II.
Memory Usage: 7.7 MB, less than 70.86% of C++ online submissions for Ugly Number II.
*/
class Solution {
  public:
    int nthUglyNumber(int n) {
        if (n <= 0) return -1;
        if (n == 1) return 1;
        int c2, c3, c5 = 0;
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 1; i < n; ++i) {
            dp[i] = min(dp[c2] * 2, min(dp[c3]*3, dp[c5]*5));
            if (dp[i] == dp[c2]*2) ++c2;
            if (dp[i] == dp[c3]*3) ++c3;
            if (dp[i] == dp[c5]*5) ++c5;            
        }
        return dp[n - 1];
    }

  private:
};


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
	// vector<vector<int>> grid{{1,3,1},{1,5,1},{4,2,1}};
	//二叉树输入
	//TreeNode* root = stringToTreeNode("[3,9,20,null,null,15,7]")
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}