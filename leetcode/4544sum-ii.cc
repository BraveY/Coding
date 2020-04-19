#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Runtime: 304 ms, faster than 45.61% of C++ online submissions for 4Sum II.
Memory Usage: 23 MB, less than 95.45% of C++ online submissions for 4Sum II.
不用条件语句
Runtime: 248 ms, faster than 71.92% of C++ online submissions for 4Sum II.
Memory Usage: 23.2 MB, less than 95.45% of C++ online submissions for 4Sum II.
 */
class Solution {
 public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		unordered_map<int, int> map;
		int rtn = 0;
		int n = A.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int sum = A[i] + B[j];
				// if (map.count(sum)) map[sum]++;
				// else map[sum] = 1;
				map[sum]++;// 默认初试的值为0
			}
		}

		for (int k = 0; k < n; k++ ) {
			for (int l = 0; l < n; l++) {
				int sum = C[k] + D[l];
				if (map.count(-sum)) rtn += map[-sum];
			}
		}
		return rtn;
	}

 private:
};

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	vector<int> A = {1, 2};
	vector<int> B = { -1, -2};
	vector<int> C = { -1, 2};
	vector<int> D = {0, 2};
	Solution sol;
	cout << sol.fourSumCount(A, B, C, D) << endl;
	system("pause");
	return 0;
}