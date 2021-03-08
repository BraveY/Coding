/*
 * @Author: your name
 * @Date: 2020-05-27 10:13:46
 * @LastEditTime: 2021-03-08 15:27:40
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode\236owest-common-ancestor-of-a-binary-tree.cc
 */
#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include "../binarytree.h"

using namespace std;

/*
Runtime: 24 ms, faster than 53.86% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
Memory Usage: 17.3 MB, less than 36.36% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
保存根节点到目标节点的路径，两条路径的公共部分就是共同的祖先。最后面的就是最低的祖先
 */
class Solution {
  public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> p_path;
		vector<TreeNode*> q_path;
		dfsFind(root, p, p_path);
		dfsFind(root, q, q_path);
		if (!root) return nullptr;
		if (p_path.size() > q_path.size())
			swap(p_path, q_path);
		int i = 0;
		for (; i < p_path.size(); i++) { 
			if (p_path[i] != q_path[i])
				break;
		}
		if (i < 0) return nullptr;
		return p_path[i - 1];
	}

  private:
	bool dfsFind(TreeNode* root, TreeNode* target, vector<TreeNode*>& path) {
		path.push_back(root);
		if (!root) {
			path.pop_back();
			return false;
		}
		if (root == target) return true;
		if (dfsFind(root->left, target, path) || dfsFind(root->right, target, path)) {
			return true;
		}
		path.pop_back();
		return false;
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