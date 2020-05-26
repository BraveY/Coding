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
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage: 8.6 MB, less than 100.00% of C++ online submissions for Binary Tree Inorder Traversal.
 */
class Solution {
  public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		inorderTraversal(root, ans);
		return ans;
	}

  private:
	void inorderTraversal(TreeNode* root, vector<int>& ans) {
		if (!root) return;
		inorderTraversal(root->left, ans);
		ans.push_back(root->val);
		inorderTraversal(root->right, ans);
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