/*
 * @Author: your name
 * @Date: 2021-04-22 13:24:51
 * @LastEditTime: 2021-04-22 15:33:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\nowcoder\NC127LCS.cpp
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
  private:
  public:
	string LCS(string s1, string s2) {
        // write code here
        int m = s1.size();
        int n = s2.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));        
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j){
                if (s1[i-1] == s2[j -1]) dp[i][j] = dp[i-1][j-1] + 1; // 相等case1
                else dp[i][j] = max(dp[i-1][j], dp[i][j - 1]); // 不等case2
            }
        }
        if (!dp[m][n])  return "-1"; // no common 
        int i = m, j = n;
        string ans = "";
        while(i && j) {
            if (s1[i - 1] == s2[j - 1]){ // case1 
                ans += s1[i-1];
                --i;
                --j;
            }else { // case2
                if (dp[i-1][j] > dp[i][j - 1]) --i; //s1 长度变小  优先走行
                else --j;                           //s2 长度变小  优先走列
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}