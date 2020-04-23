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
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pow(x, n).
Memory Usage: 7.1 MB, less than 100.00% of C++ online submissions for Pow(x, n).
记忆化递归
 */
class Solution {
 public:
	double myPow(double x, int n) {
		if (memo.count(n)) return memo[n];
		if (n == 0) memo[0] = 1;
		else if (n > 0) {
			if (n % 2 == 0)  memo[n] = myPow(x, n / 2) * myPow(x, n / 2);
			else	memo[n] = myPow(x, n / 2) * myPow(x, n / 2) * x;
		} else {
			if (n == INT_MIN) return 1 / myPow(x, INT_MAX) * x; // 考虑负数为最小的时候，其没有对应的整形最大。
			else return 1 / myPow(x, -n);
		}
		return memo[n];
	}

 private:
	unordered_map<int, double> memo;
};

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	Solution sol;
	// cout << sol.myPow(2.1, 3) << endl;
	cout << sol.myPow(2, -2) << endl;
	system("pause");
	return 0;
}