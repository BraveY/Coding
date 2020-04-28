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
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Merge Sorted Array.
Memory Usage: 6.5 MB, less than 100.00% of C++ online submissions for Merge Sorted Array.
 */
class Solution {
 public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int p1 = 0, p2 = 0;
		int cur = 0;
		vector<int> tmp(m + n);
		while ( p1 < m && p2 < n) {
			if (nums1[p1] < nums2[p2]) {
				tmp[cur++] = nums1[p1++];
				// p1++;
				// cur++;
			} else {
				tmp[cur++] = nums2[p2++];
			}
		}
		while (p1 < m) tmp[cur++] = nums1[p1++];
		while (p2 < n) tmp[cur++] = nums2[p2++];
		for (int i = 0; i < m + n; i++) {
			nums1[i] = tmp[i];
		}
	}

 private:
};

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	Solution sol;
	vector<int> nums1 = {1, 2, 3, 0, 0, 0};
	vector<int> nums2 = {2, 5, 6};
	sol.merge(nums1, 3, nums2, 3);
	for (auto i : nums1) {
		cout << i << ' ';
	}
	cout << endl;
	// cout << sol.solution() << endl;
	system("pause");
	return 0;
}