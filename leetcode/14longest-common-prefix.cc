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
Runtime: 4 ms, faster than 98.74% of C++ online submissions for Longest Common Prefix.
Memory Usage: 9.5 MB, less than 23.67% of C++ online submissions for Longest Common Prefix.
 */
class Solution {
  public:
	string longestCommonPrefix(vector<string>& strs) {
		int n = strs.size();
		if (!n) return "";
		string ans = "";
		int pos = 0;
		while (1) {
			char c = strs[0][pos];
			for (int i = 0; i < n; ++i) {
				if (pos >= strs[i].length() || strs[i][pos] != c) return ans;
			}
			ans += c;
			pos++;
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