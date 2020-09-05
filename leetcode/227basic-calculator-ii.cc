#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <stack>
#include <numeric>

using namespace std;

/*
Runtime: 40 ms, faster than 35.74% of C++ online submissions for Basic Calculator II.
Memory Usage: 12 MB, less than 11.05% of C++ online submissions for Basic Calculator II.
 */
class Solution1 {
  public:
	int calculate(string s) {
		int len = s.length();
		vector<int> first;
		vector<long long > math;
		int strLen = 0;
		int mathLen = 0;
		string opStr = "";
		for (int i = 0; i < len; ++i) {
			if (s[i] == ' ') continue;
			if (s[i] == '/' || s[i] == '*') {
				mathLen += 2;
				first.push_back(mathLen - 1 );
				math.push_back(str2int(opStr));
				if (s[i] == '/') math.push_back(-2);
				else math.push_back(-1);
				opStr = "";
			} else if (s[i] == '+' || s[i] == '-') {
				mathLen += 2;
				math.push_back(str2int(opStr));
				if (s[i] == '+') math.push_back(-3);
				else math.push_back(-4);
				opStr = "";
			} else {
				opStr += s[i];
			}
		}
		math.push_back(str2int(opStr));

		for (int i = 0; i < first.size(); ++i) {
			int j = first[i] - 1;
			if (math[first[i]] == -1)  {
				while (math[j] < 0) --j;
				math[first[i]] = math[j] * math[first[i] + 1];
			} else {
				while (math[j] < 0) --j;
				math[first[i]] = math[j] / math[first[i] + 1];
			}
			math[j] = -5;
			math[first[i] + 1] = -5;
		}

		int ans = 0;
		for (int i = 0; i < math.size(); ++i) {
			if (math[i] >= 0) {
				ans += math[i];
			} else if (math[i] == -4) {
				while (math[i] < 0 ) ++i;
				ans -= math[i];
			}
		}
		return ans;
	}

  private:
	long long  str2int(string str) {
		int len = str.size();
		long long  digit = 1;
		long long ans = 0;
		while (len--) {
			ans += (str[len] - '0') * digit;
			digit *= 10;
		}
		return ans;
	}
};


/*
Runtime: 20 ms, faster than 92.76% of C++ online submissions for Basic Calculator II.
Memory Usage: 8.9 MB, less than 32.05% of C++ online submissions for Basic Calculator II.
 */
class Solution {
  public:
	int calculate(string s) {
		vector<int> nums;
		char op = '+';
		int cur = 0;
		int pos = 0;
		while (pos < s.size()) {
			if (s[pos] == ' ') {
				++pos;
				continue;
			}
			while (isdigit(s[pos]) && pos < s.size())
				cur = cur * 10 + (s[pos++] - '0');
			if (op == '+' || op == '-') {
				nums.push_back(cur * (op == '+' ? 1 : -1));
			} else if (op == '*') {
				nums.back() *= cur;
			} else if (op == '/') {
				nums.back() /= cur;
			}
			cur = 0;
			op = s[pos++];
		}
		return accumulate(begin(nums), end(nums), 0);
	}
};
void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}

void debug() {
	Solution2 sol;

	cout << sol.calculate("3*4/2+9-2") << endl;
	//一维数组的输入
	// vector<int> nums1 = {1, 2, 3, 0, 0, 0};
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
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}