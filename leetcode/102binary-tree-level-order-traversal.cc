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
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Level Order Traversal.
Memory Usage: 12.4 MB, less than 100.00% of C++ online submissions for Binary Tree Level Order Traversal
 */
class Solution1 {
 public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (!root) return {};
		vector<vector<int>> ans;
		vector<TreeNode*> cur, next;
		cur.push_back(root);
		while (!cur.empty()) {
			ans.push_back({}); //直接用{}，就可以了，自动初试为空vector
			for (auto node : cur) {
				ans.back().push_back(node->val);//back()返回vector的最后一个元素，二维数组末尾的插入
				if (node->left) next.push_back(node->left);
				if (node->right) next.push_back(node->right);
			}
			swap(cur, next);
			next.clear();
		}
		return ans;
	}
};

class Solution {
 public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (!root) return {};
		ans.push_back({});
		DFS(root, 0);
		return ans;
	}
 private:
	vector<vector<int>> ans;
	void DFS(TreeNode* node, int depth) {
		if (!node) return;
		while (ans.size() <= depth ) {
			ans.back().push_back({});
		}
		ans[depth].push_back(node->val);
		DFS(node->left, depth + 1);
		DFS(node->right, depth + 1);
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