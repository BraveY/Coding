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
huahua
Runtime: 20 ms, faster than 66.18% of C++ online submissions for Median of Two Sorted Arrays.
Memory Usage: 7.3 MB, less than 100.00% of C++ online submissions for Median of Two Sorted Arrays.
 */
class Solution1 {
  public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		const int n1 = nums1.size();
		const int n2 = nums2.size();
		// make sure n1 < n2, by swapping
		if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
		const int k = (n1 + n2 + 1) / 2 ;
		int l = 0;
		int r = n1;

		while (l < r) {
			const int m1 = l + (r - l) / 2;
			const int m2 = k - m1;
			// 寻找最小的m1满足 maxLeftA >= minRightB
			if (nums1[m1] < nums2[m2 - 1])
				l = m1 + 1;
			else
				r = m1;
		}
		// cout << l << "	" << r << endl;
		const int m1 = l;
		const int m2 = k - m1;

		const int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1],
		                   m2 <= 0 ? INT_MIN : nums2[m2 - 1]);

		if ((n1 + n2) % 2 == 1) return c1;

		const int c2 = min(m1 >= n1 ? INT_MAX : nums1[m1],
		                   m2 >= n2 ? INT_MAX : nums2[m2]);
		return (c1 + c2) * 0.5;

	}

  private:
};

/*
Runtime: 20 ms, faster than 66.18% of C++ online submissions for Median of Two Sorted Arrays.
Memory Usage: 7.2 MB, less than 100.00% of C++ online submissions for Median of Two Sorted Arrays.
 */
class Solution2 {
  public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		const int n1 = nums1.size();
		const int n2 = nums2.size();
		// make sure n1 < n2, by swapping
		if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
		const int k = (n1 + n2 + 1) / 2 ;
		int l = 0;
		int r = n1;

		while (l <= r) {
			const int m1 = l + (r - l) / 2;
			const int m2 = k - m1;
			const int maxLeftA = m1 <= 0 ? INT_MIN : nums1[m1 - 1];
			const int minRightA = m1 >= n1 ? INT_MAX : nums1[m1];
			const int maxLeftB = m2 <= 0 ? INT_MIN : nums2[m2 - 1];
			const int minRightB = m2 >= n2 ? INT_MAX : nums2[m2];
			if (maxLeftA < minRightB && maxLeftB <= minRightA) {
				// cout << l << "	" << r << endl;
				if ((n1 + n2) % 2 == 1) return max(maxLeftA, maxLeftB);
				else {
					return (max(maxLeftB, maxLeftA) + min(minRightB, minRightA)) * 0.5;
				}
			}
			if (nums1[m1] < nums2[m2 - 1])
				l = m1 + 1;
			else
				r = m1 - 1;
		}
		return 0.0;

	}

  private:
};

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	std::vector<int> nums1({1, 4, 6, 10});
	std::vector<int> nums2({2, 4, 8, 10, 12, 34});
	Solution1 sol1;
	cout << sol1.findMedianSortedArrays(nums1, nums2) << endl;
	Solution2 sol2;
	cout << sol2.findMedianSortedArrays(nums1, nums2) << endl;
	system("pause");
	return 0;
}