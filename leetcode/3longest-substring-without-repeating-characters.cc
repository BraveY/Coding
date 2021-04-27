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
Runtime: 1720 ms, faster than 5.05% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 141.1 MB, less than 5.86% of C++ online submissions for Longest Substring Without Repeating Characters.
 */
class Solution {
  public:
	int lengthOfLongestSubstring(string s) {
		int len = s.length();
		if (len == 1) return 1;
		int maxLen = 0;
		int start, end = 0;
		unordered_map<char, int> memo;
		for (int i = 0; i < len; i++) {
			if (memo.count(s[i])) {
				start = memo[s[i]] + 1;
				memo.clear();
				for (int j = start; j <= end; j++) {
					memo[s[j]] = j;
				}
			}
			memo[s[i]] = i;
			end = i;
			maxLen = max(maxLen, end - start + 1);
		}
		return maxLen;
	}

  private:
};

/*
Runtime: 20 ms, faster than 77.56% of C++ online submissions for Longest Substring Without Repeating Characters.
Memory Usage: 7.5 MB, less than 78.82% of C++ online submissions for Longest Substring Without Repeating Characters.
Hash表加移动窗口
 */
class Solution2 {
  public:
	int lengthOfLongestSubstring(string s) {
		const int n = s.length();
		int ans = 0;
		vector<int> idx(128, -1);
		for (int i = 0, j = 0; j < n; ++j) {
			i = max(i, idx[s[j]] + 1); // i 是起始位置，判断当前字符的上一次出现位置如果比当前起点大则会出现重复，所以更新到重复的下一个位置。
			ans = max(ans, j - i + 1);
			idx[s[j]] = j;
		}
		return ans;
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