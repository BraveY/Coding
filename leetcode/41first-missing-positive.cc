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
time complexity:O(N)
space complexity:O(N)
Runtime: 4 ms, faster than 83.55% of C++ online submissions for First Missing Positive.
Memory Usage: 10.3 MB, less than 5.11% of C++ online submissions for First Missing Positive.
 */
class Solution1 {
  public:
	int firstMissingPositive(vector<int>& nums) {
		unordered_set<int> s(nums.begin(), nums.end());
		int minPos = INT_MAX;
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			if (nums[i] > 0) {
				minPos = min(minPos, nums[i]);
			}
		}
		if (minPos > 1 || minPos == 0) {
			return 1;
		}
		while (1) {
			if (s.count(minPos)) ++minPos;
			else {
				break;
			}
		}
		return minPos;
	}

  private:
};


/*
Runtime: 4 ms, faster than 83.55% of C++ online submissions for First Missing Positive.
Memory Usage: 9.8 MB, less than 59.20% of C++ online submissions for First Missing Positive.
 */
class Solution {
  public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			while (nums[i] <= n && nums[i] > 0 && nums[nums[i] - 1] != nums[i]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for (int i = 0; i < n; ++i) {
			if (nums[i] != i + 1) return i + 1;
		}
		return n + 1;
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
	vector<int> nums = {1, 2, 0};
	sol.firstMissingPositive(nums);
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