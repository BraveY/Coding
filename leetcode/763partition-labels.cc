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
Runtime: 4 ms, faster than 95.52% of C++ online submissions for Partition Labels.
Memory Usage: 6.9 MB, less than 6.59% of C++ online submissions for Partition Labels.
 */
class Solution {
  public:
	vector<int> partitionLabels(string S) {
		vector<int> lastIndex(26, -1);
		int n = S.size();
		for (int i = 0; i < n; ++i) {
			lastIndex[S[i] - 'a'] = i;
		}
		vector<int> ans;
		int r = 0;
		int i = 0;
		while (i < n) {
			r = max(i, lastIndex[S[i] - 'a']);
			for (int j = i + 1; j <= r; ++j) {
				if (lastIndex[S[j] - 'a'] > r) {
					r = lastIndex[S[j] - 'a'];
				}
			}
			ans.push_back(r + 1 - i);
			i = r + 1;
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

	string s = "abc";
	vector<int> ans = sol.partitionLabels(s);
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