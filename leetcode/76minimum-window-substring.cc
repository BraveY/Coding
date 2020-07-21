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
Runtime: 100 ms, faster than 25.03% of C++ online submissions for Minimum Window Substring.
Memory Usage: 8 MB, less than 39.26% of C++ online submissions for Minimum Window Substring.
 */
class Solution2 {
  public:
	string minWindow(string s, string t) {
		vector<int> s_dict(128, 0);
		vector<int> t_dict(128, 0);
		int l = 0, r = 0;
		int len = s.length();
		int min_len = len + 1;
		int ans_l, ans_r = 0;
		for (int i = 0; i < t.length(); i++) {
			t_dict[t[i]]++;
		}
		while (l < len) {
			while (!contain(s_dict, t_dict) && r < len) {
				s_dict[s[r]]++;
				r++;
			}
			// cout << "r" << r << endl;
			while (contain(s_dict, t_dict)) {
				s_dict[s[l]]--;
				l++;
			}
			// cout << "l" << l << endl;
			if (r - l + 1 < min_len) {
				min_len = r - l + 1;
				ans_l = l - 1;
			}
			if (r >= len) break;
		}
		// cout << min_len << endl;
		if (min_len == len + 1) return "";
		return s.substr(ans_l, min_len);
	}

  private:
	bool contain(vector<int> & s_dict, vector<int>& t_dict) {
		for (int i = 0; i < 128; i++) {
			if (t_dict[i]) {
				if (t_dict[i] > s_dict[i]) return false;
			}
		}
		return true;
	}
};

/*
Runtime: 20 ms, faster than 80.47% of C++ online submissions for Minimum Window Substring.
Memory Usage: 7.6 MB, less than 87.18% of C++ online submissions for Minimum Window Substring.
 */
class Solution {
  public:
	string minWindow(string s, string t) {
		vector<int> count(128, 0);
		int l = 0, r = 0;
		int len = s.length();
		int min_len = len + 1;
		int ans_l, ans_r = 0;
		for (int i = 0; i < t.length(); i++) {
			count[t[i]]++;
		}
		int len2find = t.length();
		while (l < len) {
			while (len2find && r < len) {
				if (count[s[r]] > 0) len2find--;
				count[s[r]]--;
				r++;
			}
			// cout << "r" << r << endl;
			while (!len2find) {
				count[s[l]]++;
				if (count[s[l]] > 0 ) len2find++;
				l++;
			}
			// cout << "l" << l << endl;
			if (r - l + 1 < min_len) {
				min_len = r - l + 1;
				ans_l = l - 1;
			}
			if (r >= len) break;
		}
		// cout << min_len << endl;
		if (min_len == len + 1) return "";
		return s.substr(ans_l, min_len);
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
	string s = "ADOBECODEBANC";
	string t = "ABC";
	cout << sol.minWindow(s, t) << endl;
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