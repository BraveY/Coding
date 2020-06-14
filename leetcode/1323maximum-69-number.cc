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
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum 69 Number.
Memory Usage: 5.9 MB, less than 82.11% of C++ online submissions for Maximum 69 Number.
 */
class Solution {
  public:
	int maximum69Number (int num) {
		vector<int> ans(5, 0);
		int digit = 0;
		while (num) {
			int tmp = num % 10;
			ans[digit] = tmp;
			digit++;
			num /= 10;
		}
		for (int i = 4; i >= 0; i--) {
			if (ans[i] == 6) {
				ans[i] = 9;
				break;
			}
		}
		int rtn = 0;
		digit = 1;
		for (int i = 0; i < 5; i++ ) {
			rtn += digit * ans[i];
			digit *= 10;
		}
		return rtn;
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