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
Runtime: 12 ms, faster than 50.38% of C++ online submissions for Find Numbers with Even Number of Digits.
Memory Usage: 9.8 MB, less than 56.18% of C++ online submissions for Find Numbers with Even Number of Digits.
 */
class Solution {
  public:
	int findNumbers(vector<int>& nums) {
		int n = nums.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int cur = nums[i];
			int count = 0;
			while (cur) {
				cur /= 10;
				count++;
			}
			if (!(count & 1)) ans++;
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
	vector<int> nums1 = {12, 345, 2, 6, 7896};
	// vector<int> nums2;
	// int i;
	// while (cin >> i) {
	// 	nums2.push_back(i);
	// }
	cout << sol.findNumbers(nums1) << endl;

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