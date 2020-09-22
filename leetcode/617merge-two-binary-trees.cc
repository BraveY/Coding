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
DFS
Runtime: 64 ms, faster than 29.79% of C++ online submissions for Merge Two Binary Trees.
Memory Usage: 34.1 MB, less than 6.04% of C++ online submissions for Merge Two Binary Trees.
 */
class Solution1 {
  public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == nullptr && t2 == nullptr) return nullptr;
		TreeNode* root = new TreeNode();
		if (t1 != nullptr && t2 != nullptr) {
			root->val = t1->val + t2->val;
			root->left = mergeTrees(t1->left, t2->left);
			root->right = mergeTrees(t1->right, t2->right);
		} else if (t1 != nullptr && t2 == nullptr) {
			root->val = t1->val;
			root->left = t1->left;
			root->right = t1->right;
		} else {
			root->val = t2->val;
			root->left = t2->left;
			root->right = t2->right;
		}

		return root;
	}

  private:
};

/*
DFS: no need to  new object in every times,
Runtime: 76 ms, faster than 12.46% of C++ online submissions for Merge Two Binary Trees.
Memory Usage: 33.7 MB, less than 11.63% of C++ online submissions for Merge Two Binary Trees.
 */
class Solution {
  public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t1 == nullptr && t2 == nullptr) return nullptr;
		if (!t1) return t2;
		if (!t2) return t1;
		TreeNode* root = new TreeNode();
		root->val = t1->val + t2->val;
		root->left = mergeTrees(t1->left, t2->left);
		root->right = mergeTrees(t1->right, t2->right);
		return root;
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