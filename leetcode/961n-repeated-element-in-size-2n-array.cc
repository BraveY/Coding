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
Runtime: 100 ms, faster than 51.36% of C++ online submissions for N-Repeated Element in Size 2N Array.
Memory Usage: 24.8 MB, less than 77.21% of C++ online submissions for N-Repeated Element in Size 2N Array.
 */
class Solution {
  public:
	int repeatedNTimes(vector<int>& A) {
		int n = A.size();
		unordered_set<int> memo;
		for (int i = 0; i < n; i++) {
			if (memo.count(A[i])) return A[i];
			else memo.insert(A[i]);
		}
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