/*
 * @Author: your name
 * @Date: 2021-03-17 09:27:21
 * @LastEditTime: 2021-03-18 16:21:38
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\exps\alicombinationSum.cc
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

#define MOD (1000000007)

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}

/*
n个数组作为n层节点。
backtrack 来求解所有的路径。
*/
class Solution2 {
public:
    int solve(int n, int m, int k) {
        ans = 0;
        dfs(0, 0, m, n, k);
        return ans;
    }

    int ans = 0;
    void dfs(int sum, int cur, int m, int n, int k) { //cur 作为depth
        if (sum > k) return; // 有个简单的剪枝，当前sum已经超过了目标就直接返回
        if (k - sum > (n - cur)*m) return ; // 剩下的全选最大的m也凑不够需要的，直接返回
        if (cur == n) {
            if (sum == k) // 
                // cout << "m: " << m << "n: " << n << endl;
                ans = (ans % MOD) + 1;
            return;
        }
        for (int i = 1; i <= m; i++) {
            sum += i;
            dfs(sum, cur + 1, m, n, k);
            sum -= i;
        }
    }
};

/*
题意:对n个数组，每个数组长度为m，并且都包含（1——m)，求每个数组均选择一个数字，使得最终和为k的个数
返回值对MOD 取余。
*/
class Solution {
  public:
	int combinationSum(int n, int m, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for (int i = 1; i <= k; ++i) {
            if (i <= m) dp[1][i] = 1;
        }
        for (int i = 2; i <= n; ++i){
            for (int j = 1; j <= k; ++j) {
                for (int p = 1; p <= j; ++p) {     // 和为j的个数 当前数组出p的情况 考虑p大于m的情况
                    if(p <= m ) {  // j可能大于m，但是p的范围是1至m    
                        dp[i][j] +=dp[i-1][j-p];
                        dp[i][j]  %= MOD;  // 确保每次组合得到的值都小于MOD
                    }
                }                
            }
        }
        return dp[n][k] % MOD;
    }

  private:
};



int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	// debug();
	// system("pause");
    int Nums, n, m, k;
    Solution sol;
    Solution2 sol2;
    cin >> Nums;
    while (Nums--) {
        cin>>n>>m>>k;
        cout << sol.combinationSum(n, m, k) << endl;
        cout << sol2.solve(n,m,k) << endl;
    }
    return 0;    
}