#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
class Solution {
	public:
	vector<int> ans;
	void quickSort(vector<int>& nums, int l, int r) {
		if (l >= r) return;
		int pivotIndex = partition(nums, l, r);
		quickSort(nums, l, pivotIndex - 1);
		quickSort(nums, pivotIndex + 1, r);
	}
	int partition(vector<int>& nums, int l, int r) {
		int pivotIndex = r;
		int pivot = nums[pivotIndex];
		while( l <= r) {
			if (nums[l] >= pivot && nums[r] <= pivot) swap(nums[l], nums[r]);
			if (nums[l] <= pivot ) ++l;
			if (nums[r] >= pivot) --r;
		}
		swap(nums[l], nums[pivotIndex]);
		pivotIndex = l;
		return l;
	}
};


void debug() {
	Solution sol;

	//一维数组的输入
	vector<int> nums1 = {1, 2, 3, 9, 8, 4};
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
	// vector<vector<int>> grid{{1,3,1},{1,5,1},{4,2,1}};
	//二叉树输入
	//TreeNode* root = stringToTreeNode("[3,9,20,null,null,15,7]")
    sol.quickSort(nums1, 0, nums1.size() - 1);
    cout_vector(nums1);
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}