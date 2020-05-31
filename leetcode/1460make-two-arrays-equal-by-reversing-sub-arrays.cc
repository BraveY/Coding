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
Runtime: 28 ms, faster than 75.00% of C++ online submissions for Make Two Arrays Equal by Reversing Sub-arrays.
Memory Usage: 15.2 MB, less than 100.00% of C++ online submissions for Make Two Arrays Equal by Reversing Sub-arrays.
 */
class Solution {
  public:
	bool canBeEqual(vector<int>& target, vector<int>& arr) {
		unordered_set<int> hash;
		for (int i = 0; i < target.size(); i++) {
			hash.insert(target[i]);
		}
		for (int i = 0 ; i < arr.size(); i++) {
			if (!hash.count(arr[i])) return false;
		}
		return true;
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