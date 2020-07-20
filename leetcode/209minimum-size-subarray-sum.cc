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
Runtime: 628 ms, faster than 5.09% of C++ online submissions for Minimum Size Subarray Sum.
Memory Usage: 10.6 MB, less than 55.91% of C++ online submissions for Minimum Size Subarray Sum.
 */
class Solution2 {
  public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		int ans = INT_MAX;
		for (int i = 0; i < n ; i++) {
			int sum = 0;
			for (int j = i; j >= 0; j--) {
				sum += nums[j];
				if (sum >= s) {
					ans = min(ans, i - j + 1);
					break;
				}
			}

		}
		return ans == INT_MAX ? 0 : ans;
	}

  private:
};

/*
Runtime: 16 ms, faster than 83.14% of C++ online submissions for Minimum Size Subarray Sum.
Memory Usage: 10.5 MB, less than 91.57% of C++ online submissions for Minimum Size Subarray Sum.
 */
class Solution {
  public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		int ans = n + 1;
		int start = 0, end = 0, sum = 0;
		while (start < n) {
			while (sum < s && end < n ) sum += nums[end++]; //右边结尾扩展，增大窗口
			if ( sum  < s) break; // 没有找到大于s的子字符串， 返回0
			ans = min(ans, end - start);
			sum -= nums[start++]; //左边起点向右移动，缩小窗口
		}
		return ans == n + 1 ? 0 : ans;
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