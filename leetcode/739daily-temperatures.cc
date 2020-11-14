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
Runtime: 80 ms, faster than 100.00% of C++ online submissions for Daily Temperatures.
Memory Usage: 40.4 MB, less than 68.13% of C++ online submissions for Daily Temperatures.
*/
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n, 0);
        for(int i = n - 2; i >= 0; --i){
            int j = i + 1;                
            while(j <= n - 1){
                if(T[i] < T[j]){
                    ans[i] =  j - i;
                    // cout <<"i: "<< i <<"ans[i]" << ans[i] <<endl;
                    break;
                }else if(T[i] == T[j]){
                    ans[i] = ans[j] == 0 ? 0 : j - i + ans[j];
                    break;
                }                
                if(ans[j] == 0 ) break;
                j = ans[j] + j;
            }            
        }
        return ans;
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
	vector<int> nums = {73,74,75,71,69,72,76,73};
	// vector<int> nums2;
	// int i;
	// while (cin >> i) {
	// 	nums2.push_back(i);
	// }
    vector<int> ans = sol.dailyTemperatures(nums);
    cout_vector(ans);

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