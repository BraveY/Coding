#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include "../binarytree.h"

using namespace std;

/*
Runtime: 28 ms, faster than 96.56% of C++ online submissions for Binary Tree Maximum Path Sum.
Memory Usage: 28.4 MB, less than 6.06% of C++ online submissions for Binary Tree Maximum Path Sum.
 */
class Solution {
  public:
	int maxPathSum(TreeNode* root) {
		if (!root) return 0;
		dfs(root);
		return maxSum;
	}

  private:
	int maxSum = INT_MIN;//在遍历过程中来找到最大值。
	int dfs(TreeNode* root) { // 返回经过root的最大sum
		if (!root) return 0;
		int leftMax = dfs(root->left);
		int rightMax = dfs(root->right);
		int singleMax = max(root->val + leftMax, root->val + rightMax);//左右两边的最大值
		int bothSum = leftMax + rightMax + root->val; //左右两边都经过的情况，有可能最大
		maxSum = max(maxSum, singleMax); //只走一条边
		maxSum = max(maxSum, bothSum);//走两条边
		maxSum = max(maxSum, root->val);//两条边都不走
		return max(singleMax, root->val);//考虑两条边都不走的情况。
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