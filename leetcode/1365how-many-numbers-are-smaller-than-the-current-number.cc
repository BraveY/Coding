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
Runtime: 44 ms, faster than 45.01% of C++ online submissions for How Many Numbers Are Smaller Than the Current Number.
Memory Usage: 10.2 MB, less than 100.00% of C++ online submissions for How Many Numbers Are Smaller Than the Current Number.
 */
class Solution1 {
  public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans(n, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (nums[j] < nums[i]) {
					ans[i]++;
				}
			}
		}
		return ans;
	}

  private:
};

/*
限制了范围，类似桶排序的方式记录每一个的累积和
Runtime: 4 ms, faster than 99.82% of C++ online submissions for How Many Numbers Are Smaller Than the Current Number.
Memory Usage: 10.1 MB, less than 100.00% of C++ online submissions for How Many Numbers Are Smaller Than the Current Number.
 */
class Solution {
  public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans(n, 0);
		vector<int> count(101, 0);
		for (int i = 0; i < n; i++) {
			count[nums[i]]++;
		}
		int sum = count[0];
		for (int i = 1; i < 101; i++) {
			sum += count[i];
			count[i] = sum - count[i];
		}
		for (int i = 0; i < n; i++) {
			if (nums[i] == 0) continue;
			ans[i] = count[nums[i]];
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
	vector<int> nums1 = {8, 1, 2, 2, 3};
	// vector<int> nums2;
	// int i;
	// while (cin >> i) {
	// 	nums2.push_back(i);
	// }
	vector<int> ans = sol.smallerNumbersThanCurrent(nums1);
	cout_vector(ans);

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