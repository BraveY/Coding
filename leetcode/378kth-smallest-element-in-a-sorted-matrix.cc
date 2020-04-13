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
Runtime: 40 ms, faster than 78.81% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.
Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.
 */
class Solution {
 public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		if (n < 1) return -1;
		int lo = matrix[0][0];
		int hi = matrix[n - 1][n - 1];
		while (lo < hi) {
			int mid = lo + (hi - lo) / 2;
			int count = notGreaterCount(matrix, mid);
			if (count < k) {
				lo = mid + 1;
			} else hi = mid;
		}
		return lo;
	}

 private:
	int notGreaterCount(vector<vector<int>>& matrix, int target) {
		int curRow = 0;
		int n = matrix.size();
		int count = 0;
		// 要把所有的行都给遍历了。
		while (curRow < n) {
			if (matrix[curRow][n - 1] < target) {
				count += n;
			} else {
				int i = n - 1;
				while (i >= 0 && matrix[curRow][i] > target) {
					i--;
				}
				count += i + 1;
			}
			curRow++;
		}
		return count;
	}
};

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	Solution sol;
	vector<vector<int> > matrix({{1, 5, 9}, {10, 11, 13}, {12, 13, 15}});
	cout << sol.kthSmallest(matrix, 8) << endl;
	system("pause");
	return 0;
}