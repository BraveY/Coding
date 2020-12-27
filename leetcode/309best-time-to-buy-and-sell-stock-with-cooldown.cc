#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>

using namespace std;

/*
Runtime: 4 ms, faster than 87.34% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
Memory Usage: 11.4 MB, less than 85.47% of C++ online submissions for Best Time to Buy and Sell Stock with Cooldown.
*/
class Solution {
  public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n) return 0;
        vector<int> dp(n+2, 0);
        int min_diff = prices[0];
        for(int i = 1; i < n; ++i){
            int j = i + 2;
            dp[j] = max(dp[j - 1], prices[i] - min_diff);
            min_diff = min(min_diff, prices[i] - dp[j - 2]);
        }
        return dp[n + 1];
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
	// vector<vector<int>> grid{{1,3,1},{1,5,1},{4,2,1}};
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}