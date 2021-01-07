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


// Definition for a binary tree node.
// struct TreeNode {
// 	int val;
// 	TreeNode *left;
// 	TreeNode *right;
// 	TreeNode() : val(0), left(nullptr), right(nullptr) {}
// 	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// 	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };



/*
BFS used two vectors
Runtime: 4 ms, faster than 82.39% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
Memory Usage: 11.9 MB, less than 100.00% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
 */
class Solution1 {
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


/*
Runtime: 4 ms, faster than 73.92% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
Memory Usage: 12.7 MB, less than 26.70% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
		vector<vector<int>> ans;
		vector<int> tmp;
		int depth = 0;
		queue<TreeNode*> q1;
		queue<TreeNode*> q2;
		q1.push(root);
		while(!q1.empty() || !q2.empty()){		
			TreeNode* cur = q1.front();						
			if(cur->left) {
				q2.push(cur->left);
			}
			if(cur->right) {
				q2.push(cur->right);
			}
			//必须先遍历后面然后出队，然后再插入到最终的返回数组中。
			q1.pop();
			tmp.push_back(cur->val);				
			if(q1.empty()){
				if(depth % 2 != 0){
					reverse(tmp.begin(), tmp.end());
				}
				ans.push_back(tmp);
				++depth;
				swap(q1, q2);
				tmp.clear();
			}						
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
	// vector<int> v = {1, 2, 3, 4};
	// cout_vector(v);
	// v.clear();
	// v.push_back(7);
	// cout_vector(v);
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
	TreeNode* root = stringToTreeNode("[3,9,20,null,null,15,7]");
	vector<vector<int>> ans = sol.zigzagLevelOrder(root);
	for(auto i : ans){
		cout_vector(i);
	}
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}