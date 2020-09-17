#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <stack>
using namespace std;

/*
TLE
 */
class Solution {
  public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		if (!n) return 0;
		int ans = heights[0];
		for (int i = 0; i < n; ++i) {
			int minCur = heights[i];
			if (minCur == 0) continue;
			ans = max(ans, minCur);
			for (int j = i + 1; j < n; ++j) {
				if (heights[j] == 0) {
					break;
				}
				minCur = min(minCur, heights[j]);
				int area = minCur * (j - i + 1);
				ans = max(ans, area);
			}
		}
		return ans;
	}

  private:
};
/*
Runtime: 24 ms, faster than 86.39% of C++ online submissions for Largest Rectangle in Histogram.
Memory Usage: 14.2 MB, less than 60.71% of C++ online submissions for Largest Rectangle in Histogram.
 */
class Solution2 {
  public:
	int largestRectangleArea(vector<int>& heights) {
		heights.push_back(0);
		const int n = heights.size();
		stack<int> s;
		int ans = 0;
		int i = 0;
		while (i < n) {
			if (s.empty() || heights[i] >= heights[s.top()]) {
				s.push(i++);
			} else {
				int h = heights[s.top()];
				s.pop();
				int w = s.empty() ? i : i - s.top() - 1;
				ans = max(ans, h * w);
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