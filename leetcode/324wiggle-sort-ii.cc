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
Runtime: 120 ms, faster than 14.70% of C++ online submissions for Wiggle Sort II.
Memory Usage: 17.7 MB, less than 7.69% of C++ online submissions for Wiggle Sort II.
 */
class Solution1 {
 public:
	void wiggleSort(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> sort_nums = nums;
		int n = sort_nums.size();
		int lo = 0, hi = n - 1;
		int mid = lo + (hi - lo ) / 2;
		int i = 0;
		int left_mid = mid;
		while (left_mid >= 0) { // 两部分都向前填充
			nums[i++] = sort_nums[left_mid--];
			if (hi > mid) nums[i++] = sort_nums[hi--];
		}
	}
 private:
};


class Solution {
 public:
	void wiggleSort(vector<int>& nums) {
		int n = nums.size();
		std::nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
		int mid = nums[n / 2];

		// 3-way-partion
		int i = 0;
		int j = 0;
		int k = n - 1;

#define a(i) nums[(2*(i)+1)%(n|1)]

		while (j <= k) {
			if (a(j) > mid) {
				swap(a(i), a(j));
				++i;
				++j;
			} else if (a(j) < mid) {
				swap(a(j), a(k));
				--k;
			} else {
				++j;
			}
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
	// vector<int> nums1 = {1, 5, 1, 1, 6, 4};
	vector<int> nums2;
	int i;
	while (cin >> i) {
		nums2.push_back(i);
	}
	sol.wiggleSort(nums2);
	cout_vector(nums2);
	// cout << sol.solution() << endl;

	//二维数组的输入
	// while (cin >> m >> n) {
	// 	vector<vector<char>> grid(m, vector<char>(n));
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