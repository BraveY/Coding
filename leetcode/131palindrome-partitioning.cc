#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
	vector<vector<string>> partition(string s) {
		backtrack(s);
		return ans;
	}
  private:
	vector<string> path;
	vector<vector<string>> ans;
	void backtrack(string s) {
		string tmp;
		int len = s.length();
		if (!len) {
			ans.push_back(path);
			return;
		}
		for (int i = 1; i <= len; i++) {
			tmp = s.substr(0, i);
			if (palindrome(tmp)) {
				path.push_back(tmp);
				backtrack(s.substr(i));
				path.pop_back();
			}
		}
	}
	bool palindrome(string str) {
		int len = str.length();
		int p = 0;
		int q = len - 1;
		while (true) {
			if (p >= q) break;
			if (str[p] != str[q]) return false;
			p++;
			q--;
		}
		return true;
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