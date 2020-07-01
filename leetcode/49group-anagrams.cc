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
Runtime: 68 ms, faster than 73.27% of C++ online submissions for Group Anagrams.
Memory Usage: 24.3 MB, less than 13.44% of C++ online submissions for Group Anagrams.
 */
class Solution {
  public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string> > anagrams;
		vector<vector<string>> ans;
		for (int i = 0; i < strs.size(); i++) {
			vector<int> memo(26, 0);
			for (int j = 0; j < strs[i].length(); j++) {
				// char c = strs[i];
				memo[strs[i][j] - 'a']++;
			}
			string tmp;
			for (int k = 0; k < 26; k++) {
				while (memo[k]) {
					tmp += 'a' + k;
					memo[k]--;
				}
			}
			anagrams[tmp].push_back(strs[i]);
		}
		for (auto iter : anagrams) {
			ans.push_back(iter.second);
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
	string tmp;
	tmp += 'a';
	tmp += 'a' + 1;
	cout << tmp << endl;
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