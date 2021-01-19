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
Runtime: 20 ms, faster than 69.38% of C++ online submissions for Average of Levels in Binary Tree.
Memory Usage: 22.7 MB, less than 99.65% of C++ online submissions for Average of Levels in Binary Tree.
*/
class Solution {
  public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<TreeNode*>  cur;
		vector<TreeNode*>  next;
		vector<double> ans;
		cur.push_back(root);
		while(!cur.empty()){
			double sum = 0.0;
			for(int i = 0; i < cur.size(); ++i) {
				sum += cur[i]->val;
				if(cur[i]->left) next.push_back(cur[i]->left);
				if(cur[i]->right) next.push_back(cur[i]->right);				
			}
			ans.push_back( sum / cur.size());
			cur.clear();
			swap(cur, next);
		}
		return ans;
    }

  private:
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