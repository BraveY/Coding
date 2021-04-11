/*
 * @Author: your name
 * @Date: 2021-04-11 16:26:40
 * @LastEditTime: 2021-04-11 17:38:14
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\nowcoder\BD4MoGuZheng.cc
 */
/*
 * @Author: your name
 * @Date: 2019-11-22 15:00:25
 * @LastEditTime: 2021-04-10 14:22:45
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \Coding\solution_template.cc
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
#include <iomanip> 

using namespace std;

/*
https://www.nowcoder.com/practice/ed9bc679ea1248f9a3d86d0a55c0be10?tpId=143&tqId=33928&rp=1&ru=%2Fta%2Fexam-baidu&qru=%2Fta%2Fexam-baidu%2Fquestion-ranking&tab=answerKey
运行时间：2ms
超过37.03%用C++提交的代码
占用内存：400KB
超过80.07%用C++提交的代码
*/ 
class Solution {
  private:
  public:
	void solution() {
        int N, M, K;
        while (cin >> N >> M >> K) {
            int x, y;
            vector<vector<int>> grid(N+1, vector<int>(M+1, 0));
            vector<vector<double>> dp(N+1, vector<double>(M+1, 0));        
            while(K--){
                cin >> x >> y;
                grid[x][y] = 1;
            }
            dp[1][1] = 1.0;
            for(int i = 1; i <= N; ++i) {
                for (int j = 1; j <= M; ++j) {
                    if (i == 1 && j == 1) continue;
                    dp[i][j] = dp[i-1][j] * (j == M ? 1 : 0.5) + dp[i][j-1] * (i == N ? 1 : 0.5);
                    if (grid[i][j]) dp[i][j] = 0.0;
                }
            }    
            cout << fixed << setprecision(2) << dp[N][M] << endl;
        }                        
    }
    int path(vector<vector<int>>& grid, int N, int M, int flag) {
        vector<vector<int>> dp(N+1, vector<int>(M+1, 0));        
        for(int i = 1; i <= N; ++i) {
            dp[i][1] = 1;
        }
        for (int i = 1; i <= M; ++i) {
            dp[1][i] = 1;
        }
                
        if (flag) { // 统计不走蘑菇得路径数
            for(int i = 2; i <= N; ++i) {
                for (int j = 2; j <= M; ++j) {
                    if (!grid[i-1][j]) dp[i][j] = dp[i-1][j];
                    if (!grid[i][j-1]) dp[i][j] += dp[i][j-1];                    
                }
            }                 
        }else { // 统计所有得路径数
            for(int i = 2; i <= N; ++i) {
                for (int j = 2; j <= M; ++j) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }            
        }
        return dp[N][M];
    }
};


int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
    Solution sol;
    sol.solution();
	return 0;
}