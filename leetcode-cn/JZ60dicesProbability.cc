/*
 * @Author: your name
 * @Date: 2021-04-06 21:30:29
 * @LastEditTime: 2021-04-06 22:31:48
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode-cn\JZ60dicesProbability.cc
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
#include <math>

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}

/*
TLE
*/
class Solution1 {
  public:
    vector<double> dicesProbability(int n) {
        if (n == 0) return {};
        double base = 1 / (double) pow(6, n);
        vector<double> prob(5*n + 1, 0.0);
        backtrack(prob, 0, 0, n);
        for (int i = 0; i < prob.size(); ++i) {
            prob[i] *= base;
        }
        return prob;
    }

  private:
    void backtrack(vector<double>& prob, int sum ,int cur, int n) {
        if ( cur == n) {
            prob[sum - n]++;
            return;
        }
        for (int i = 1; i <= 6; i++) {
            sum += i;
            backtrack(prob, sum, cur + 1, n);
            sum -= i;
        }
    }
};

/*
滚动数组
利用上一个的结果来更新，类似与动态规划
执行用时：
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗：
6.4 MB
, 在所有 C++ 提交中击败了
30.96%
的用户
*/
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> rtn;
        int maxNum = 6;
        vector<vector<int>> probs(2, vector<int>(6*n + 1, 0));
        int flag = 0;
        for (int i = 1; i <= maxNum; ++i){
            probs[flag][i] = 1;
        }
        // 1 - flag 表示需要填充的数组
        // flag 表示完成填充的数组，也就是上一步的
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) { // 小于最小值的部分出现次数为0
                probs[1 - flag][j] = 0;
            }
            for (int j = i; j <= i*maxNum; ++j) { // 遍历可能出现的所有值
                probs[1 - flag][j] = 0; // 置为0
                for (int k = 1; k <= maxNum; ++k) {
                    if (j - k >= 0) probs[1 - flag][j] += probs[flag][j - k];
                }
            }
            flag = 1 - flag;
        }
        double base = 1 / (double) pow(6, n);
        for (int i = n; i <= n*maxNum; ++i) {
            rtn.push_back(probs[flag][i]*base);
        }
        return rtn;
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