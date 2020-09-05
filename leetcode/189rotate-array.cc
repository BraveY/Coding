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
Runtime: 8 ms, faster than 88.09% of C++ online submissions for Rotate Array.
Memory Usage: 9.9 MB, less than 61.02% of C++ online submissions for Rotate Array.
 */
class Solution1 {
  public:
	void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		int n = len;
		if (k > len ) {
			rotate(nums, k - len);
			return;
		} else if (k == len) return;
		vector<int> tmpArr(k);
		while (n--) {
			if (n + k < len) {
				nums[n + k] = nums[n];
			} else {
				tmpArr[n + k - len] = nums[n];
			}
		}
		n = k;
		while (n--) {
			nums[n] = tmpArr[n];
		}
	}

  private:
};

/*
Runtime: 4 ms, faster than 99.51% of C++ online submissions for Rotate Array.
Memory Usage: 10.2 MB, less than 19.36% of C++ online submissions for Rotate Array.
 */
class Solution2 {
  public:
	void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		if (!len || len < 2) return;

		k = k % len;
		reverse(nums, 0, len - k - 1);
		reverse(nums, len - k, len - 1);
		reverse(nums, 0, len - 1 );
	}

  private:
	void reverse(vector<int>& nums, int l, int r) {
		while (l < r) {
			swap(nums[l], nums[r]);
			++l;
			--r;
		}
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