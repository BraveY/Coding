#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
Runtime: 20 ms, faster than 69.33% of C++ online submissions for Longest Consecutive Sequence.
Memory Usage: 11 MB, less than 47.11% of C++ online submissions for Longest Consecutive Sequence.
 */
class Solution1 {
  public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> h;
		for (int num : nums) {
			if (h.count(num)) continue;

			auto itL = h.find(num - 1);
			auto itR = h.find(num + 1);
			int l = itL != h.end() ? itL->second : 0;
			int r = itR != h.end() ? itR->second : 0;
			if (l > 0 && r > 0) {
				h[num] = h[num - l] = h[num + r] = l + r + 1; // bridge case
			} else if (l > 0) {
				h[num] = h[num - l] = l + 1;	// one neighbor
			} else if (r > 0) {
				h[num] = h[num + r] = r + 1;	//one neighbor
			} else {
				h[num] = 1; // no neighbor
			}
		}

		int ans = 0;
		for (const auto& kv : h) {
			ans = max(ans, kv.second);
		}
		return ans;
	}

  private:
};


/*
Runtime: 20 ms, faster than 69.33% of C++ online submissions for Longest Consecutive Sequence.
Memory Usage: 10.8 MB, less than 86.92% of C++ online submissions for Longest Consecutive Sequence.
 */
class Solution {
  public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> h(nums.begin(), nums.end());
		int ans = 0;
		for (long num : nums) {
			if (!h.count(num - 1)) {
				int l = 0;
				while (h.count(num++)) ++l;
				ans = max(ans, l);
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