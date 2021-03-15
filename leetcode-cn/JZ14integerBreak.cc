/*
 * @Author: your name
 * @Date: 2021-03-11 15:32:13
 * @LastEditTime: 2021-03-13 11:00:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode-cn\JZ14integerBreak.cc
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
28.71%
的用户
内存消耗：
6.1 MB
, 在所有 C++ 提交中击败了
68.28%
的用户
*/
class Solution {
  public:
    int integerBreak(int n) {
        if (n < 2) {
            return -1;
        }
        vector<int> dp(n,0);
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] = max(dp[j]*(i - j), dp[i]); // 左边的继续拆分 1*1*2
                // dp[i] = max((j + 1)*dp[i - j -1], dp[i]); // 右边继续拆分2*1*1 因为是对称的所以不需要了
                dp[i] = max((j + 1) * (i - j), dp[i]);// 左右都不继续拆分  分成两个比分成3个还要大 比如4分成2*2,比分成1*1*2大
                dp[i] = max(dp[j]*dp[i - j - 1], dp[i]); //左右都继续拆分 对第二个也进行拆分 4*2 分成 1*1*1*1 (包含上述所有情况) 当大于等于4的时候只用这种
            }
        }
        return dp[n - 1];
    }

  private:
};


void debug() {
	Solution sol;
    int n = 10; 
    cout << sol.integerBreak(n) << endl;
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}