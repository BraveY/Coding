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
Runtime: 8 ms, faster than 98.67% of C++ online submissions for Maximum Product of Two Elements in an Array.
Memory Usage: 10.2 MB, less than 100.00% of C++ online submissions for Maximum Product of Two Elements in an Array.
 */
class Solution {
  public:
	int maxProduct(vector<int>& nums) {
		int n = nums.size();
		int max1 = n;
		int max2 = n;
		nums.push_back(INT_MIN);
		for (int i = 0; i < n; i++)	{
			if (nums[i] > nums[max1]) {
				max1 = i;
			}
		}
		for (int i = 0; i < n; i++) {
			if (i == max1) continue;
			if (nums[i] > nums[max2]) max2 = i;
		}
		return (nums[max2] - 1) * (nums[max1] - 1);
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
	vector<int> nums1 = {10, 3, 4, 5,};
	// vector<int> nums2;
	// int i;
	// while (cin >> i) {
	// 	nums2.push_back(i);
	// }
	cout << sol.maxProduct(nums1) << endl;

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