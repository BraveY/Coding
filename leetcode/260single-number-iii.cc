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
Runtime: 8 ms, faster than 94.82% of C++ online submissions for Single Number III.
Memory Usage: 9.8 MB, less than 96.04% of C++ online submissions for Single Number III.
*/
class Solution {
  public:
    vector<int> singleNumber(vector<int>& nums) {
        long long diff = 0; // -2^31 溢出的问题
        for (int n : nums) {
            diff ^= n;
        }
        diff &= -diff; // last set bit  of a xor b
        vector<int> ans = {0, 0};
        for (int n : nums ) { // 根据最后不同的bit将a 和b 划分到两个组，每个组再进行累异或。
            if (n & diff) {
                ans[1] ^= n;
            }else {
                ans[0] ^= n;
            }
        }
        return ans;
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