/*
 * @Author: your name
 * @Date: 2021-03-21 20:30:49
 * @LastEditTime: 2021-03-21 21:02:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\exps\TencentTransform.cc
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

class Solution {
  public:
	int solution(int n) {
        vector<int> dp(n+1, 0);
        // for (int i = 1; i <=n; ++i) {
        //     dp[i] = i;
        // }
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + 1;
            if (i % 2 == 0) {
                dp[i] = min(dp[i], dp[i / 2] + 1);
            }
            if (i % 3 == 0) {
                dp[i] = min(dp[i], dp[i / 3] + 1);
            }
        }
        return dp[n];
    }

  private:
};



int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
    Solution sol;
    int T, n;
    cin >> T;
    while (T--) {
        cin>>n;
        cout << sol.solution(n) << endl;
    }
    return 0;    
}