/*
 * @Author: your name
 * @Date: 2021-03-10 15:30:22
 * @LastEditTime: 2021-03-10 15:45:09
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode-cn\JZ05replaceSpace.cc
 */
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
执行用时：
4 ms
, 在所有 C++ 提交中击败了
30.40%
的用户
内存消耗：
6 MB
, 在所有 C++ 提交中击败了
87.90%
的用户

如果在原字符串上进行修改需要从后往前进行。
*/
class Solution {
  public:
	string replaceSpace(string s) {
        int len = s.size();
        string retStr;
        for (int i = 0; i < len; ++i) {
            if (s[i] != ' ') {
                retStr += s[i];
            }else {
                retStr += "%20";
            }
        }
        return retStr;
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