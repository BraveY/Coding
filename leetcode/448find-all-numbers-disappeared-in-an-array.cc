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
swap in place
Runtime: 116 ms, faster than 82.51% of C++ online submissions for Find All Numbers Disappeared in an Array.
Memory Usage: 34 MB, less than 36.18% of C++ online submissions for Find All Numbers Disappeared in an Array.
 */
class Solution {
  public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> ans;
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			while (nums[i] != i + 1) {
				if (nums[i] == nums[nums[i] - 1]) break;
				swap(nums[nums[i] - 1], nums[i]);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (nums[i] != i + 1)
				ans.push_back(i + 1);
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