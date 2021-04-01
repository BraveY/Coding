/*
 * @Author: your name
 * @Date: 2021-03-21 21:08:26
 * @LastEditTime: 2021-03-21 22:30:48
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\exps\TencentJumpStairs.cc
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
class Solution {
  public:
	int solution(int n, int u, int v, int s, int t, int m) {
        vector<vector<int>> oneStepSum(n + 1, vector<int>(m + 1, 0)); // 记录每个选择的走一步的和
        vector<vector<int>> dp(n+1, vector<int>(m+1,INT_MAX));
        for (int j = 1; j <= m; ++j){
            int x = 1;
            int y = 0;
            if (j - x*s - t*y*y >= 0) {
                dp[1][j] = u*x + v*y;
                oneStepSum[1][j] = 1;
            }
        }
        for (int j = 1; j <= m; ++j) {
            int x, y;
            int oneStepCost = INT_MAX;
            int twoStepCost = INT_MAX;
            // 走一步
            x = 2;
            y = 0;
            if (j - x*s - t*y*y >= 0) {
                oneStepCost = x*s + t*y*y;
            }
            // 走两步
            x = 0;
            y = 1;
            if (j - x*s - t*y*y >= 0) {
                twoStepCost = x*s + t*y*y;
            }   
            if (oneStepCost <= twoStepCost) {
                x = 2;
                y = 0;
                oneStepSum[2][j] = oneStepSum[1][j-x*s-t*y*y] + 1;
                dp[2][j] = oneStepCost;
            }else {
                oneStepSum[2][j] = 0;
                dp[2][j] = twoStepCost;
            }

        }
        for (int i = 2; i <=n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int x = 0;
                int y = 0;
                // 走一步
                dp[i - 1][j - ]
                // 走两步
            }
        }
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
	//链表输入使用lclist.h
    //ListNode* head = stringToListNode("[1,3,2]");
	// prettyPrintLinkedList(head);
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}