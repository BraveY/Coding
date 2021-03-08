/*
 * @Author: your name
 * @Date: 2021-03-08 14:58:18
 * @LastEditTime: 2021-03-08 16:10:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode\235lowest-common-ancestor-of-a-binary-search-tree.cc
 */
#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include "../binarytree.h"

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
/*
DFS
Runtime: 28 ms, faster than 85.27% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
Memory Usage: 23.3 MB, less than 65.71% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
*/
class Solution1 {
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

/*
利用搜索数的性质进行剪枝
Runtime: 24 ms, faster than 96.62% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
Memory Usage: 23.2 MB, less than 65.71% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
*/
class Solution2 {
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
        bool ret = false;
		path.push_back(root);
		if (!root) {
			path.pop_back();
			return false;
		}
		if (root == target) return true;
        if (root->val > target->val) {
            ret = dfsFind(root->left, target, path);
        } else {
            ret = dfsFind(root->right, target, path);
        }
        if (ret) {
            return true;
        }
		path.pop_back();
		return false;
	}
};


/*
Runtime: 24 ms, faster than 96.62% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
Memory Usage: 23.1 MB, less than 87.61% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
p q的分布只有三种情况：
1. 全部在左子树
2. 全部在右子树
3. 分别在左右子树 ：返回此时的根节点（递归退出条件）
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }else if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }else {
            return root;
        }
	}
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