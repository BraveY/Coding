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
TLE
 */
class Solution1 {
  public:
	int maxArea(vector<int>& height) {
		int ans = 0;
		int n = height.size();
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				int area = (j - i) * min(height[i], height[j]);
				ans = max(ans, area);
			}
		}
		return ans;
	}

  private:
};

/*
Runtime: 36 ms, faster than 49.14% of C++ online submissions for Container With Most Water.
Memory Usage: 14.3 MB, less than 42.33% of C++ online submissions for Container With Most Water.
从两边向中间缩小
只移动长度较小的部分
当高度变大时计算面积
 */
class Solution {
  public:
	int maxArea(vector<int>& height) {
		int ans = 0;
		int n = height.size();
		int i = 0, j = n - 1;
		int leftHeight = i;
		int rightHeight = j;
		ans = (rightHeight - leftHeight) * min(height[leftHeight], height[rightHeight]);
		while (i <= j) {
			if (height[i] > height[leftHeight]) {
				leftHeight = i;
				int area = (rightHeight - leftHeight) * min(height[leftHeight], height[rightHeight]);
				ans = max(ans, area);
			}
			if (height[j] > height[rightHeight]) {
				rightHeight = j;
				int area = (rightHeight - leftHeight) * min(height[leftHeight], height[rightHeight]);
				ans = max(ans, area);
			}
			if ( height[leftHeight] > height[rightHeight])  j--;
			else i++;
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
	vector<int> nums1 = {1, 2};
	// vector<int> nums2;
	// int i;
	// while (cin >> i) {
	// 	nums2.push_back(i);
	// }
	cout << sol.maxArea(nums1) << endl;

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