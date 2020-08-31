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
Runtime: 4 ms, faster than 98.98% of C++ online submissions for Implement strStr().
Memory Usage: 6.9 MB, less than 66.41% of C++ online submissions for Implement strStr().
 */
class Solution {
  public:
	int strStr(string haystack, string needle) {
		int nLen = needle.length();
		if (!nLen) return 0;
		int hLen = haystack.length();
		if (!hLen) return -1;
		if (nLen > hLen) return -1;
		for (int i = 0; i < hLen; ++i) {
			int j = 0;
			while  (j < nLen &&  i < hLen && haystack[i] == needle[j]) {
				++j;
				++i;
			}
			if (j == nLen) return i - nLen;
			if (i == hLen) return -1;
			i -= j;
		}
		return -1;
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