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
Runtime: 28 ms, faster than 81.85% of C++ online submissions for Subtree of Another Tree.
Memory Usage: 29.4 MB, less than 83.33% of C++ online submissions for Subtree of Another Tree.
DFS
*/
class Solution {
  public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        bool c = isEqual(s, t);
        bool l = isSubtree(s->left, t);
        bool r = isSubtree(s->right, t);
        return l || r || c;
    }

    bool isEqual(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        else if (s && t) {
            if (s->val == t->val) {
                bool l = isEqual(s->left, t->left);
                bool r = isEqual(s->right, t->right);
                return l & r;
            }else return false;
        }else return false;  
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