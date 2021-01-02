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

/*
Time Limit Exceeded
*/
class Solution1 {
  public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (!n) return  0;
        int ans = 0;
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for(int i = 0; i < n; ++i){
            if(i > 0){
                prefixSum[i] = prefixSum[i - 1] + nums[i];
            }            
        }
        for(int i = 0; i < n; ++i) {
            if(prefixSum[i] == k) ans++;
            for(int j = 0; j < i; ++j){
                if(prefixSum[i] - prefixSum[j] == k) ans++;
            }
        }
        return ans;
    }

  private:
};

/*
Runtime: 160 ms, faster than 50.15% of C++ online submissions for Subarray Sum Equals K.
Memory Usage: 42.4 MB, less than 12.32% of C++ online submissions for Subarray Sum Equals K.
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(!n) return 0;
        unordered_map<int, int> memo {{0, 1}};
        int prefixSum = 0;
        int ans = 0;
        for(int i = 0; i < n; ++i){
            prefixSum += nums[i];
            ans += memo[prefixSum - k];
            memo[prefixSum]++;
        }
        return ans;
        
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
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}