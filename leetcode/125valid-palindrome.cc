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
Runtime: 8 ms, faster than 99.31% of C++ online submissions for Valid Palindrome.
Memory Usage: 7.2 MB, less than 75.04% of C++ online submissions for Valid Palindrome.
 */
class Solution {
  public:
	bool isPalindrome(string s) {
		int len = s.length();
		if (!len) return true;
		int l = 0;
		int r = len - 1;
		while (l < r) {
			int lNum = transform(s[l]);
			int rNum = transform(s[r]);
			if (!lNum) {
				++l;
				continue;
			}
			if (!rNum) {
				--r;
				continue;
			}
			if (lNum != rNum) return false;
			++l;
			--r;
		}
		return true;
	}

  private:
	int transform(char c) {
		if ( c >= 97 && c <= 122) return c;
		else if (c >= 65 && c <= 90 ) return c + 32;
		else if (c >= 48 && c <= 57) return c;
		else return 0;
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