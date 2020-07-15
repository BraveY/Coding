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
Runtime: 76 ms, faster than 5.65% of C++ online submissions for Sort Array By Parity.
Memory Usage: 16.4 MB, less than 52.10% of C++ online submissions for Sort Array By Parity.
 */
class Solution {
  public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int n = A.size();
		if (!n) return {};
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			if (A[i] % 2) ans.push_back(A[i]);
			else ans.insert(ans.begin(), A[i]);
		}
		return ans;
	}

  private:
};

/*
Runtime: 56 ms, faster than 7.78% of C++ online submissions for Sort Array By Parity.
Memory Usage: 16.6 MB, less than 17.41% of C++ online submissions for Sort Array By Parity.

 */
class Solution2 {
  public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int n = A.size();
		if (!n) return {};
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			if (A[i] & 1) ans.push_back(A[i]);
			else ans.insert(ans.begin(), A[i]);
		}
		return ans;
	}

  private:
};
/*
Runtime: 20 ms, faster than 63.01% of C++ online submissions for Sort Array By Parity.
Memory Usage: 16.5 MB, less than 42.98% of C++ online submissions for Sort Array By Parity.
 */
class Solution3 {
  public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int n = A.size();
		if (!n) return {};
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			if (!(A[i] & 1)) ans.push_back(A[i]);
		}
		for (int i = 0; i < n; i++) {
			if (A[i] & 1) ans.push_back(A[i]);
		}
		return ans;
	}

  private:
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