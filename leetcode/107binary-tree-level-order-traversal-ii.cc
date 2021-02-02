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
Runtime: 4 ms, faster than 83.45% of C++ online submissions for Binary Tree Level Order Traversal II.
Memory Usage: 13.7 MB, less than 19.38% of C++ online submissions for Binary Tree Level Order Traversal II.
*/
class Solution {
  public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        DFS(root, 1);
        vector<vector<int>> rtn;
        for(int i = ans.size() - 1; i >= 0; --i) {
            rtn.push_back(ans[i]);
        }
        return rtn;
    }
  private:
  vector<vector<int>> ans;
  void DFS(TreeNode* root, int depth){
      if (!root) return;
      while(ans.size() < depth) {
          ans.push_back({});
      }
      ans[depth - 1].push_back(root->val);
      DFS(root->left, depth + 1);
      DFS(root->right, depth + 1);
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