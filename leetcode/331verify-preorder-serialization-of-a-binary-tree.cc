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
Runtime: 4 ms, faster than 81.46% of C++ online submissions for Verify Preorder Serialization of a Binary Tree.
Memory Usage: 6.8 MB, less than 87.54% of C++ online submissions for Verify Preorder Serialization of a Binary Tree.
*/
class Solution {
  public:
    bool isValidSerialization(string preorder) {
        int pos = 0;
        return isValid(preorder, pos) && pos == preorder.size();
    }

  private:
    bool isValid(const string& s, int& pos){
        if(pos >= s.size()) return false;
        if(isdigit(s[pos])){
            while(isdigit(s[pos])) ++pos;
            return isValid(s, ++pos) && isValid(s, ++pos);
        }
        return s[pos++] == '#';
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