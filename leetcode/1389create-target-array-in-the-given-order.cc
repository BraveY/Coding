#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>

using namespace std;

/*
Runtime: 4 ms, faster than 60.45% of C++ online submissions for Create Target Array in the Given Order.
Memory Usage: 8.4 MB, less than 61.76% of C++ online submissions for Create Target Array in the Given Order.
 */
class Solution {
  public:
	vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
		int n = nums.size();
		if (!n) return vector<int> {};
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			ans.push_back(-1);
			if (ans[index[i]] < 0) {
				ans[index[i]] = nums[i];
			} else {
				for (int j = ans.size() - 1; j > index[i]; j--) {
					ans[j] = ans[j - 1];
				}
				ans[index[i]] = nums[i];
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