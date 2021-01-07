#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include <stack>

using namespace std;

/*
TLE
O(2^n)
*/
class Solution1 {
  public:
    int findTargetSumWays(vector<int>& nums, int S) {
		DFS(0, 0, nums, S);
		return ans;
    }

  private:
	void DFS(int sum, int depth, vector<int>& nums, int S) {
		if (depth == nums.size()){ // 到达 末尾
			if (sum == S) ans++;
			return;
		}
		int val = nums[depth];
		DFS(sum + val, depth + 1, nums, S);
		DFS(sum - val, depth + 1, nums, S);
	}
	int ans = 0;

};
/*
Runtime: 116 ms, faster than 51.19% of C++ online submissions for Target Sum.
Memory Usage: 14.1 MB, less than 40.17% of C++ online submissions for Target Sum.
T(n) = O(n*2001)
O(n) = O(2 * 2001)
*/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
		if ( S > 1000 || S < -1000 ) return 0;
		if(!n) return 0;
		vector<vector<int>> dp(2, vector<int>(2001, 0));
		dp[0][0 + 1000] = 1;
		for(int i = 1; i < n + 1; ++i){
			for(int j = 0; j < 2001; ++j){	
				int add = 0;
				int sub = 0;
				if (j - nums[i - 1] >= 0 ) add = dp[0][j - nums[i - 1]];
				if (j + nums[i - 1] < 2001 ) sub = dp[0][j + nums[i - 1]];
				dp[1][j] = add + sub;
			}
			dp[0] = dp[1];
		}
		return dp[1][S + 1000];
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        if ( S > 1000 || S < -1000 ) return 0;
		if(!n) return 0;
		vector<vector<int>> dp(n + 1, vector<int>(2001, 0));
		dp[0][0 + 1000] = 1;
		for(int i = 1; i < n + 1; ++i){
			for(int j = 0; j < 2001; ++j){	
				int add = 0;
				int sub = 0;
				if (j - nums[i - 1] >= 0 ) add = dp[i - 1][j - nums[i - 1]];
				if (j + nums[i - 1] < 2001 ) sub = dp[i - 1][j + nums[i - 1]];
				dp[i][j] = add + sub;
			}
		}
		return dp[n][S + 1000];
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
	vector<int> nums1 = {1, 1, 1};
	// vector<int> nums2;
	// int i;
	// while (cin >> i) {
	// 	nums2.push_back(i);
	// }
	cout << sol.findTargetSumWays(nums1, 1) << endl;

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