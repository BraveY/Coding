#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
/*
Runtime: 504 ms, faster than 5.40% of C++ online submissions for Permutations II.
Memory Usage: 70.5 MB, less than 5.01% of C++ online submissions for Permutations II
*/
class Solution1 {
  public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int depth = 0;
        used = vector<bool> (nums.size(), false);
        vector<int> path;
        backtrack(nums, depth, path);
        return ans;
    }
  private:
    vector<bool> used;
    unordered_map<string, bool> memo;
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, int depth, vector<int> path){
        if (depth == nums.size()) {
            string str;
            for(int i = 0; i < depth; ++i) {
                str += to_string(path[i]);
            }
            if(memo.count(str)) return;
            ans.push_back(path);
            memo[str] = true;
            return;
        } 
        for(int i = 0; i < used.size(); ++i){
            if (used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, depth + 1, path);
            path.pop_back();
            used[i] = false;
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