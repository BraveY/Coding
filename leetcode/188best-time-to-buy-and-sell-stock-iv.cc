#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution1 {
  public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.empty()) return 0;
		int ans = 0;
		if (k >= prices.size() / 2) {
			for (int i = 1; i < prices.size(); ++i) {
				if (prices[i] > prices[i - 1])
					ans += prices[i] - prices[i - 1];
			}
			return ans;
		}
		vector<vector<int>> dp(prices.size(), vector<int>(k + 1, 0));
		for (int x = 1; x <= k; ++x) {
			for (int i = 1; i < prices.size(); ++i) {
				dp[i][x] = dp[i - 1][x]; // 不做交易
				for (int j = 0; j < i; ++j) {
					dp[i][x] = max(dp[i][x], dp[j][x - 1] + prices[i] - prices[j]);
				}
			}
			ans = max(ans, dp[prices.size() - 1][x]);
		}
		return ans;
	}
};

// class Solution {
// public:
//     int allTimeProfit(vector<int> arr){
//         int profit = 0;
//         int localMin = arr[0];
//         for(int i=1; i < arr.size();i++){
//             if(arr[i-1] >= arr[i]){
//                 localMin = arr[i];
//             }else{
//                 profit += arr[i] - localMin;
//                 localMin = arr[i];
//             }

//         }
//         return profit;
//     }

//     int maxProfit(int k, vector<int>& prices) {
//         if(prices.size()==0 || k==0) return 0;
//         int n=prices.size();
//         if(k>n/2){
//             return allTimeProfit(prices);
//         }
//         int dp[k+1][n];
//         for(int i=0;i<n;i++){
//             dp[0][i]=0;
//         }
//         for(int i=0;i<k+1;i++){
//             dp[i][0]=0;
//         }
//         int maxDiff=-prices[0];
//         for(int i=1;i<k+1;i++){
//             int maxDiff=-prices[0];
//             for(int j=1;j<n;j++){
//                 dp[i][j]=max(dp[i][j-1],prices[j]+maxDiff);
//                 maxDiff=max(maxDiff,dp[i-1][j]-prices[j]);
//             }
//         }
//         return dp[k][n-1];
//     }
// };


class Solution {
  public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.empty()) return 0;
		int ans = 0;
		if (k >= prices.size() / 2) {
			for (int i = 1; i < prices.size(); ++i) {
				if (prices[i] > prices[i - 1])
					ans += prices[i] - prices[i - 1];
			}
			return ans;
		}
		vector<vector<int>> dp(prices.size(), vector<int>(k + 1, 0));
		for (int x = 1; x <= k; ++x) {
			int min_diff = prices[0]; //第0天的情况就是price[0] - 0 = prices[0]
			for (int i = 1; i < prices.size(); ++i) { //从第1天开始，
				dp[i][x] = max(dp[i - 1][x], prices[i] - min_diff);// 卖出所得到的收益
				min_diff = min(min_diff, prices[i] - dp[i][x - 1]);//加入当前天数后得到最新的最小差值。
			}
		}
		return dp[prices.size() - 1][k];
	}
};
void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}

void debug() {
	Solution sol;

	//一维数组的输入
	//[1,2,4,2,5,7,2,4,9,0]
	vector<int> nums1 = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
	// vector<int> nums2;
	int k = 4;
	cout << sol.maxProfit(k, nums1) << endl;

	//二维数组的输入
	//int m, n;
	// while (cin >> m >> n) {
	// 	vector<vector<char>> grid(m, vector<char>(n));
	// 	for (int i = 0; i < m; i++) {
	// 		for (int j = 0; j < n; j++ ) {
	// 			cin >> grid[i][j];
	// 		}
	// 	}
	// 	int ans = sol.solution(grid);
	// 	cout << ans << endl;
	// }
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}