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

class Solution {
  public:
    unordered_map<TreeNode*, int> memo;
    int rob(TreeNode* root) {
        if (!root) return 0;
        if(!memo.count(root)) memo[root] = 0;
        else{
            return memo[root];
        }
        if (!root->left && !root->right){
            memo[root] = root->val;
            return root->val;
        }            
        int left_grandson = 0;
        int right_grandson = 0;
        if(root->left){
            left_grandson =  rob(root->left->left) + rob(root->left->right);
        }
        if(root->right){
            right_grandson =  rob(root->right->left) + rob(root->right->right);
        }
        int rob_root = root->val + left_grandson + right_grandson;
        int not_rob_root = rob(root->left) + rob(root->right);\
        int ans = max(not_rob_root, rob_root);
        memo[root] = ans;
        return ans;
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
	// vector<vector<int>> grid{{1,3,1},{1,5,1},{4,2,1}};
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}