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
TLE O(n^2)
 */
class Solution1 {
  public:
	int trap(vector<int>& height) {
		int n = height.size();
		int ans = 0;
		auto sit = height.begin();
		auto eit = height.end();
		for (int i = 0; i < n; ++i) {
			int l = *max_element(sit, sit + i + 1);//左闭，右开.
			int r = *max_element(sit + i, eit);
			ans += min(l, r) - height[i];
		}
		return ans;
	}

  private:
};

/*
Runtime: 12 ms, faster than 66.17% of C++ online submissions for Trapping Rain Water.
Memory Usage: 14.1 MB, less than 57.68% of C++ online submissions for Trapping Rain Water.
 */
class Solution2 {
  public:
	int trap(vector<int>& height) {
		int n = height.size();
		int ans = 0;
		vector<int> l(n);
		vector<int> r(n);
		for (int i = 0; i < n; ++i) {
			l[i] = i == 0 ? height[i] : max(l[i - 1], height[i]);
		}
		for (int i = n - 1; i >= 0; --i) {
			r[i] = i == n - 1 ? height[i] : max(r[i + 1], height[i]);
		}
		for (int i = 0; i < n; ++i) {
			ans += min(l[i], r[i]) - height[i];
		}
		return ans;
	}

  private:
};

/*
Runtime: 12 ms, faster than 66.17% of C++ online submissions for Trapping Rain Water.
Memory Usage: 14.1 MB, less than 65.41% of C++ online submissions for Trapping Rain Water.
 */
class Solution {
  public:
	int trap(vector<int>& height) {
		int n = height.size();
		if (n == 0) return 0;
		int ans = 0;
		int l = 0;
		int r = n - 1 ;
		int max_l = height[l];
		int max_r = height[r];
		while (l < r) {
			if (max_l < max_r) {
				ans += max_l - height[l];
				max_l = max(max_l, height[++l]);
			} else {
				ans += max_r - height[r];
				max_r = max(max_r, height[--r]);
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
	vector<int> nums = {5, 4, 1, 2};
	// vector<int> nums2;
	// int i;
	// while (cin >> i) {
	// 	nums2.push_back(i);
	// }
	cout << sol.trap(nums) << endl;

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