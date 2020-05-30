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
Runtime: 4 ms, faster than 87.79% of C++ online submissions for Kids With the Greatest Number of Candies.
Memory Usage: 9.1 MB, less than 100.00% of C++ online submissions for Kids With the Greatest Number of Candies
 */
class Solution {
  public:
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
		int n = candies.size();
		vector<bool> ans(n);
		if (n == 0)	return ans;
		int maxCandies = candies[0];
		for (int i = 0; i < n; i++) {
			maxCandies = max(maxCandies, candies[i]);
		}
		for (int i = 0; i < n; i++) {
			if (candies[i] + extraCandies >= maxCandies) {
				ans[i] = true;
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