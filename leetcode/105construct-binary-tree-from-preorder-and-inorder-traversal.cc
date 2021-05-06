


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
Runtime: 20 ms, faster than 61.73% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
Memory Usage: 74 MB, less than 11.56% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
根据先序确定root节点位置，然后根据中序来划分左右节点的中序序列，然后根据左右节点的序列长度来划分先序的左右序列
递归构建，每次构建root节点。
重点在于切分左右序列
 */
class Solution {
 public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty()) return nullptr;
		TreeNode* root = new TreeNode(preorder[0]);
		if (preorder.size() == 1) return root;
		vector<int>::iterator rootP = find(inorder.begin(), inorder.end(), root->val);		
		vector<int> left_inorder(inorder.begin(), rootP);//不包含rootp
		vector<int> right_inorder(rootP + 1, inorder.end());
		vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + left_inorder.size());
		vector<int> right_preorder(preorder.begin() + 1 + left_inorder.size(), preorder.end());
		root->left = buildTree(left_preorder, left_inorder);
		root->right = buildTree(right_preorder, right_inorder);
		return root;
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
	// vector<int> nums1 = {3, 9, 20, 15, 7};
	// vector<int> nums2 = {3, 9, 15, 20, 7};
	vector<int> nums1 = {1, 3};
	vector<int> nums2 = {3, 1};
	TreeNode* ret = sol.buildTree(nums1, nums2);
	// string out = boolToString(ret);
	// cout << out << endl;
	// int i;
	// while (cin >> i) {
	// 	nums2.push_back(i);
	// }
	// cout << sol.solution(nums2) << endl;

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