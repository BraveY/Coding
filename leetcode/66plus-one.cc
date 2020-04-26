#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <stack>

using namespace std;

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Plus One.
Memory Usage: 6.4 MB, less than 100.00% of C++ online submissions for Plus One.
 */
class Solution {
 public:
	vector<int> plusOne(vector<int>& digits)  {
		stack<int> plusStack;
		vector<int> rtn;
		int n = digits.size();
		if (!n) return rtn;
		// digits[n - 1]++;
		int step = 1;
		while (n--) {
			digits[n] += step;
			if (digits[n] >= 10) {
				digits[n] = digits[n] % 10;
				step = 1;
			} else {
				step = 0;
			}
			plusStack.push(digits[n]);
		}
		if (step > 0) plusStack.push(step);
		while (!plusStack.empty()) {
			rtn.push_back(plusStack.top());
			plusStack.pop();
		}
		return rtn;
	}

 private:
};

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	Solution sol;
	vector<int> v = {};
	vector<int> ans = sol.plusOne(v);
	for (auto i : ans) {
		cout << i << "	";
	}
	cout << endl;
	// cout << sol.plusOne(v) << endl;
	system("pause");
	return 0;
}