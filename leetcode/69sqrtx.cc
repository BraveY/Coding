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
Runtime: 4 ms, faster than 59.71% of C++ online submissions for Sqrt(x).
Memory Usage: 6.2 MB, less than 100.00% of C++ online submissions for Sqrt(x).
 */
class Solution {
 public:
	int mySqrt(int x) {
		int hi = x;
		int lo = 0;
		while (lo < hi) {
			long long mid = lo + (hi - lo) / 2; // mid 一定要考虑溢出的问题 用long long
			long long  pow = mid * mid;
			if (pow == x ) return mid;
			else if (pow > x) hi = mid;
			else {
				long long greater = (mid + 1) * (mid + 1);
				if (greater > x) return mid;
				else lo = mid + 1;
			}
		}
		return -1;
	}

 private:
};

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	Solution sol;
	cout << sol.mySqrt(13) << endl;
	system("pause");
	return 0;
}