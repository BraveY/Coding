/*
 * @Author: your name
 * @Date: 2021-04-22 15:32:42
 * @LastEditTime: 2021-04-22 15:41:51
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\nowcoder\NC127LCSubstring.cpp
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
        int longest = INT_MIN;
        int row = 0, col = 0;        
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= n; ++j){
                if (s1[i-1] == s2[j -1]) dp[i][j] = dp[i-1][j-1] + 1; // 相等case1            
                if (dp[i][j] >= longest) { // 更新坐标 相应得减1
                    longest = dp[i][j];
                    row = i - 1;
                    col = j - 1;
                }
            }
        }
        if (!longest)  return "-1"; // no common         
        string ans = "";
        int len = longest;
        int ix = row;
        while(len--){
            ans += s1[ix--];
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