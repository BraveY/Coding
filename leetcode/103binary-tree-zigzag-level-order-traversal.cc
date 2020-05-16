#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <queue>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



/*
BFS used two vectors
Runtime: 4 ms, faster than 82.39% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
Memory Usage: 11.9 MB, less than 100.00% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
 */
class Solution {
 public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (!root) return {};
		int flag = 0;
		vector<TreeNode*> cur, next;
		vector<vector<int>> ans;
		cur.push_back(root);
		while (!cur.empty()) {
			ans.push_back({});
			for (TreeNode* node : cur) {
				if (node->left) next.push_back(node->left);
				if (node->right) next.push_back(node->right);
			}
			if (flag) { // right to left
				int len = cur.size();
				while (len--) {
					ans.back().push_back(cur[len]->val);
				}
			} else {
				for (TreeNode* node : cur) {
					ans.back().push_back(node->val);
				}
			}
			swap(cur, next);
			flag = !flag;
			next.clear();
		}
		return ans;
	}
};

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}

void debug() {
	vector<int> v = {1, 2, 3, 4};
	cout_vector(v);
	v.clear();
	v.push_back(7);
	cout_vector(v);
	Solution sol;

	//一维数组的输入
	// vector<int> nums1 = {1, 2, 3, 0, 0, 0};
	// vector<int> nums2;
	// int i;
	// while (cin >> i) {
	// 	nums2.push_back(i);
	// }
	// cout << sol.solution() << endl;

	//二维数组的输入
	//int m, n;
	// while (cin >> m >> n) {
	// 	vector<vector<char>> grid(m, vector<char>(n));
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