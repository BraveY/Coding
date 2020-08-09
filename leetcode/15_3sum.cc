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
Runtime: 2760 ms, faster than 5.03% of C++ online submissions for 3Sum.
Memory Usage: 23.1 MB, less than 37.51% of C++ online submissions for 3Sum.
 */
class Solution1 {
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


class Solution {
  public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		for (int i = 0; i < n - 2; ++i) {
			if (nums[i] > 0) break; // 排序后后面的都是正数。
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int l = i + 1;
			int r = n - 1;
			while (l < r) {
				if (nums[i] + nums[l] + nums[r] == 0) {
					ans.push_back({nums[i], nums[l++], nums[r++]});
					while ( l < r && nums[l] == nums[l - 1]) ++l;
					while ( l < r && r + 1 < n && nums[r] == nums[r + 1]) --r;
				} else if ( nums[i] + nums[l] + nums[r] < 0) ++l;
				else --r;
			}
		}
		return ans;
	}

  private:
};

/*
Runtime: 84 ms, faster than 88.28% of C++ online submissions for 3Sum.
Memory Usage: 19.8 MB, less than 67.87% of C++ online submissions for 3Sum.
 */
class Solution {
  public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		std::sort(nums.begin(), nums.end());
		const int n = nums.size();
		for (int i = 0; i < n - 2; ++i) {
			if (nums[i] > 0) break;
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int l = i + 1;
			int r = n - 1;
			while (l < r) {
				if (nums[i] + nums[l] + nums[r] == 0) {
					ans.push_back({nums[i], nums[l++], nums[r--]});
					while (l < r && nums[l] == nums[l - 1]) ++l;
					while (l < r && nums[r] == nums[r + 1]) --r;
				} else if (nums[i] + nums[l] + nums[r] < 0) {
					++l;
				} else {
					--r;
				}
			}
		}
		return ans;
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
	vector<int> nums = { -1, 0, 1, 2, -1, -4};
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