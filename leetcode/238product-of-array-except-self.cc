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
Runtime: 52 ms, faster than 6.42% of C++ online submissions for Product of Array Except Self.
Memory Usage: 15.7 MB, less than 80.05% of C++ online submissions for Product of Array Except Self.
 */
class Solution {
  public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		if (!n) return vector<int> {};
		vector<int> ans(n, 1);
		int rProduct = 1;
		int lProduct = 1;
		for (int i = n - 1; i >= 0; --i) {
			rProduct *= nums[i];
			ans[i] = rProduct;
		}
		for (auto i : ans) {
			cout << i << ' ';
		}
		cout << endl;
		for (int i = 0; i < n; ++i) {
			if (i == n - 1) ans[i] = lProduct;
			else ans[i] = lProduct * ans[i + 1];
			lProduct *= nums[i];
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
	vector<int> nums1 = {9, 0, -2};
	// vector<int> nums2;
	// int i;
	// while (cin >> i) {
	// 	nums2.push_back(i);
	// }
	// cout << sol.solution(nums) << endl;
	vector<int> ans = sol.productExceptSelf(nums1);
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