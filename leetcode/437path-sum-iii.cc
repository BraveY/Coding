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
Runtime: 24 ms, faster than 68.54% of C++ online submissions for Path Sum III.
Memory Usage: 16.7 MB, less than 54.51% of C++ online submissions for Path Sum III.
不要再DFS里面再次DFS，这样会重复很多次，递归的逻辑比较复杂。
*/
class Solution {
  public:
    int pathSum(TreeNode* root, int sum) {
        expect = sum;
        DFS_v(root, 0);
        for(int i = 1; i < nodes.size(); i++) {
            DFS(nodes[i], 0);
        }
        return ans;
    }

  private:
    void DFS_v(TreeNode* root, int sum){
        if(!root) return;
        nodes.push_back(root);
        sum += root->val;
        if(sum == expect){
            ans++;            
        }        
        DFS_v(root->left, sum);
        DFS_v(root->right, sum);
    }
    void DFS(TreeNode* root, int sum){
        if(!root) return;
        sum += root->val;
        if(sum == expect){
            ans++;            
        }        
        DFS(root->left, sum);
        DFS(root->right, sum);
    }    
    int ans = 0;
    int expect = 0;
    vector<TreeNode*> nodes;
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
    string str = "[1,null,2,null,3,null,4,null,5]";
    int sum = 3;
    TreeNode* root = stringToTreeNode(str);
    cout << sol.pathSum(root, sum) << endl;
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}