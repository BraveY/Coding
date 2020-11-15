#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*
Runtime: 44 ms, faster than 26.09% of C++ online submissions for Palindromic Substrings.
Memory Usage: 7.8 MB, less than 47.07% of C++ online submissions for Palindromic Substrings.
*/
class Solution {
  public:
    int countSubstrings(string s) {
        int n = s.size();
        if(!n) return 0;
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        int count = 0;
        for(int j = 0; j < n; ++j){
            for(int i = 0; i <=j; ++i){
                if(i == j) {
                    dp[i][j] = 1;
                    ++count;
                }
                else if(i + 1 == j && s[i] == s[j]) {
                    dp[i][j] = 1;
                    ++count;
                }
                else if(dp[i + 1][j - 1] == 1 && s[i] == s[j]) {
                    dp[i][j] = 1;
                    ++count;
                }
            }
        }
        return count;
    }

  private:
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
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}