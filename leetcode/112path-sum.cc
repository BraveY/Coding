#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include "../binarytree.h"

using namespace std;

/*
Runtime: 12 ms, faster than 84.95% of C++ online submissions for Path Sum.
Memory Usage: 21.7 MB, less than 43.21% of C++ online submissions for Path Sum.
*/
class Solution {
  public:
    bool hasPathSum(TreeNode* root, int sum) {
        expect = sum;
        DFS(root, 0);
        return flag;
    }

  private:
    int DFS(TreeNode* root, int sum){
        if(!root) return sum;
        sum += root->val;
        if(!root->left && !root->right && sum == expect){
            flag = true;
        }        
        int l = DFS(root->left, sum);
        int r = DFS(root->right, sum);
        return sum;
    }
    bool flag = false;
    int expect = 0;
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