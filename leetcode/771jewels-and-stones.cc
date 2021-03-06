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
Runtime: 4 ms, faster than 65.44% of C++ online submissions for Jewels and Stones.
Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Jewels and Stones.
 */
class Solution {
  public:
	int numJewelsInStones(string J, string S) {
		unordered_set<char> Jewels;
		for (int i = 0; i < J.length(); i++) {
			Jewels.insert(J[i]);
		}
		int nums = 0;
		for (int i = 0; i < S.length(); i++) {
			if (Jewels.count(S[i])) nums++;
		}
		return nums;
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