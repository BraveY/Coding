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
Runtime: 16 ms, faster than 70.05% of C++ online submissions for Validate Binary Search Tree.
Memory Usage: 21.6 MB, less than 5.21% of C++ online submissions for Validate Binary Search Tree.
 */
class Solution1 {
  public:
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, LLONG_MIN, LLONG_MAX);
	}

  private:
	bool isValidBST(TreeNode* root, long min_limit, long max_limit) {
		if (!root) return true;
		if (root->val <= min_limit || root->val >= max_limit)
			return false;
		return isValidBST(root->left, min_limit, root->val) &&
		       isValidBST(root->right, root->val, max_limit);
	}
};

/*
Runtime: 24 ms, faster than 19.28% of C++ online submissions for Validate Binary Search Tree.
Memory Usage: 21.6 MB, less than 5.21% of C++ online submissions for Validate Binary Search Tree.
 */
class Solution {
  public:
	bool isValidBST(TreeNode* root) {
		prev = nullptr;
		return inOrder(root);
	}

  private:
	TreeNode* prev;
	bool inOrder(TreeNode* root) {
		if (!root) return true;
		if (!inOrder(root->left)) return false;
		if (prev && root->val <= prev->val) return false;
		prev = root;
		return inOrder(root->right);
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