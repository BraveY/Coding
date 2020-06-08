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
Runtime: 236 ms, faster than 5.26% of C++ online submissions for Kth Largest Element in an Array.
Memory Usage: 10.2 MB, less than 25.55% of C++ online submissions for Kth Largest Element in an Array.
 */
class Solution {
  public:
	int findKthLargest(vector<int>& nums, int k) {
		int n = nums.size();
		quicksort(nums, 0, n - 1, n - k);
		return ans;
	}
  private:
	int ans;
	void quicksort(vector<int>& nums, int lo , int hi, int k) {
		if (lo >= hi) {
			ans = nums[hi];
			return ;
		}
		int piv = partition(nums, lo, hi);
		if (piv == k) {
			ans = nums[k];
			return;
		} else if (k < piv ) quicksort(nums, lo , piv - 1, k);
		else quicksort(nums, piv + 1, hi, k );
	}
	int partition(vector<int>& nums, int lo, int hi) {
		int loNow = lo - 1;
		int piv = hi;
		for (int i = lo; i <= hi - 1; i++) {
			if (nums[i] <= nums[piv]) {
				loNow++;
				swap(nums[loNow], nums[i]);
			}
		}
		swap(nums[loNow + 1], [piv]);
		piv = loNow + 1;
		return piv;
	}
};

class Solution2 {
  public:
	int findKthLargest(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end(), greater<int>());
		//int length = nums.size();
		return nums[k - 1];
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
	vector<int> nums1 = {3, 2, 1, 5, 6, 4};
	// vector<int> nums2;
	// int i;
	// while (cin >> i) {
	// 	nums2.push_back(i);
	// }
	cout << sol.findKthLargest(nums1, 2) << endl;


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