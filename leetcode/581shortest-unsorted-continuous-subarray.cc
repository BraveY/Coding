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
	int findUnsortedSubarray(vector<int>& nums) {
		int n = nums.size();
		vector<int> sorted(nums);
		int i , j;
		sort(sorted.begin(), sorted.end());
		for (i = 0; i < n; ++i) {
			if (nums[i] != sorted[i] ) break;
		}
		for (j = n - 1; j > i; --j) {// j >i? j == i是分界线
			if (nums[j] != sorted[j] ) break;
		}
		return j - i + 1;
	}

  private:
};

/*
Runtime: 48 ms, faster than 99.19% of C++ online submissions for Shortest Unsorted Continuous Subarray.
Memory Usage: 28.4 MB, less than 7.74% of C++ online submissions for Shortest Unsorted Continuous Subarray.
 */
class Solution {
  public:
	int findUnsortedSubarray(vector<int>& nums) {
		int n = nums.size();
		vector<int> maxlhs(n);   // max number from left to cur
		vector<int> minrhs(n);   // min number from right to cur
		for (int i = n - 1, minr = INT_MAX; i >= 0; i--) minrhs[i] = minr = min(minr, nums[i]);
		for (int i = 0,     maxl = INT_MIN; i < n;  i++) maxlhs[i] = maxl = max(maxl, nums[i]);

		int i = 0, j = n - 1;
		while (i < n && nums[i] <= minrhs[i]) i++;
		while (j > i && nums[j] >= maxlhs[j]) j--;

		return j + 1 - i;
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
	vector<int> nums = {1, 3, 2, 4, 5};
	cout << sol.findUnsortedSubarray(nums) << endl;
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