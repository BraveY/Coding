#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <stack>
#include <numeric>
#include "../binarytree.h"

using namespace std;

/*
Runtime: 4 ms, faster than 99.07% of C++ online submissions for Path Sum II.
Memory Usage: 21.9 MB, less than 47.06% of C++ online submissions for Path Sum II.
*/
class Solution {
  public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        expect = sum;
        DFS(root, 0);
        return ans;
    }


  private:
    stack<int> path;
    vector<vector<int>> ans;
    int expect = 0;

    void DFS(TreeNode* root, int sum){
        if(!root) return;
        path.push(root->val);
        sum += root->val;
        if(!root->left && !root->right && sum == expect) {
            insert2ans(path);
        }        
        DFS(root->left, sum);
        DFS(root->right, sum);
        path.pop();
    }
    void insert2ans(stack<int> path){
        vector<int> tmp(path.size());
        for(int i = path.size() - 1; i >= 0; i--) {
            tmp[i] = path.top();
            path.pop();
        }
        ans.push_back(tmp);
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