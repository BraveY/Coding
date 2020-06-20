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
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
Memory Usage: 6.7 MB, less than 42.17% of C++ online submissions for Letter Combinations of a Phone Number.
 */
class Solution {
  public:
	vector<string> letterCombinations(string digits) {
		int len = digits.length();
		if (!len) return {};
		backtrack(digits, 0, len);
		return ans;
	}

  private:
	unordered_map<char, string> dict{
		{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
		{'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
	};
	vector<string> ans;
	string path;
	void backtrack(string digits, int index, int len ) {
		if (index == len ) {
			ans.push_back(path);
			return;
		}
		string cur = dict[digits[index]];
		// cout << digits[index] << endl;
		for (int i = 0; i < cur.length(); i++ ) {
			path += cur[i];
			// cout << path << " " << cur[i] << endl;
			backtrack(digits, index + 1, len);
			path.erase(path.length() - 1 );
		}
	}
};

void cout_vector(vector<string>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}

void debug() {
	Solution sol;
	vector<string> ans;
	ans = sol.letterCombinations("23");
	cout_vector(ans);
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