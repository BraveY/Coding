#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Runtime: 16 ms, faster than 68.49% of C++ online submissions for Roman to Integer.
Memory Usage: 7.7 MB, less than 50.04% of C++ online submissions for Roman to Integer.
 */
class Solution {
  public:
	int romanToInt(string s) {
		unordered_map<char, int> dict = {
			{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
			{'C', 100}, {'D', 500}, {'M', 1000}
		};
		int len = s.length();
		int ans = 0;
		for (int i = 0; i < len; ++i) {
			char c = s[i];
			if (c != 'I' && c != 'X' && c != 'C') ans += dict[c];
			else {
				if (c == 'I') {
					if (s[i + 1] == 'V') {
						ans += 4;
						++i;
					} else if (s[i + 1] == 'X') {
						ans += 9;
						++i;
					} else {
						ans += dict[c];
					}
				} else if (c == 'X') {
					if (s[i + 1] == 'L') {
						ans += 40;
						++i;
					} else if (s[i + 1] == 'C') {
						ans += 90;
						++i;
					} else {
						ans += dict[c];
					}
				} else {
					if (s[i + 1] == 'D') {
						ans += 400;
						++i;
					} else if (s[i + 1] == 'M') {
						ans += 900;
						++i;
					} else {
						ans += dict[c];
					}
				}
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