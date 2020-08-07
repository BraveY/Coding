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

class Solution {
  public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		int n = nums.size();
		if (!n) return ans;
		unordered_map<int, int> memo;
		unordered_map<int, unordered_set<int>> sumMemo;
		for (int i = 0; i < n; ++i) {
			if (!memo.count(nums[i])) memo[nums[i]] = 1;
			else memo[nums[i]]++;
		}
		for (int i = 0; i < nums.size(); ++i) {
			memo[nums[i]]--;
			for (int j = i + 1; j < nums.size(); ++j) {
				memo[nums[j]]--;
				int twoSum = nums[i] + nums[j];
				if (memo.count(-twoSum) && memo[-twoSum] > 0) {
					int least = min(nums[i], nums[j]);
					least = min(least, -twoSum);
					int greatest = max(nums[i], nums[j]);
					greatest = max(greatest, -twoSum);
					if (sumMemo.count(least) && sumMemo[least].count(greatest))	;
					else {
						sumMemo[least].insert(greatest);
						ans.push_back({nums[i], nums[j], -twoSum});
					}

				}
				memo[nums[j]]++;
			}
			memo[nums[i]]++;
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
	vector<int> nums = { -4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
	// vector<int> nums2;
	// int i;
	// while (cin >> i) {
	// 	nums2.push_back(i);
	// }
	// cout << sol.solution(nums2) << endl;
	vector<vector<int>> ans;
	ans = sol.threeSum(nums);
	for (auto item : ans) {
		cout_vector(item);
	}
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