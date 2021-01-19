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
O(N^2)
Time Limit Exceeded
*/
class Solution1 {
  public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < i; ++j) {
                if (nums[j] >= i - j) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];
    }

  private:
};

/*
Runtime: 8 ms, faster than 99.94% of C++ online submissions for Jump Game II.
Memory Usage: 15.3 MB, less than 99.91% of C++ online submissions for Jump Game II.
*/
class Solution {
  public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        int end = 0, farthest = 0, steps = 0;
        for (int i = 0; i <= end; ++i) {
            if (i == n - 1) break;
            farthest = max(farthest, i + nums[i]);
            if (i == end) {
                ++steps;
                end = farthest;
            }
        }
        return steps;
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