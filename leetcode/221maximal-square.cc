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
Runtime: 44 ms, faster than 19.50% of C++ online submissions for Maximal Square.
Memory Usage: 11.5 MB, less than 7.41% of C++ online submissions for Maximal Square.
 */
class Solution {
  public:
	int maximalSquare(vector<vector<char>>& matrix)  {
		int m = matrix.size();
		if (m == 0) return 0;
		int n = matrix[0].size();
		vector<vector<int>> opt(m + 1, vector<int>(n + 1, 0));
		int max_cur = 0;
		for (int i = 1; i < m + 1; i++) {
			for (int j = 1; j < n + 1; j++) {
				if (matrix[i - 1][j - 1] == '0') { // char 类型不是int，一定要加单引号
					opt[i][j] = 0; //原始矩阵要少一个维度
				} else {
					opt[i][j] = 1 + min(min(opt[i - 1][j], opt[i][j - 1]), opt[i - 1][j - 1]);
				}
				max_cur = max(max_cur, opt[i][j]);
			}
		}
		return max_cur * max_cur;
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
	int m, n;
	while (cin >> m >> n) {
		vector<vector<char>> grid(m, vector<char>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++ ) {
				cin >> grid[i][j];
			}
		}
		int ans = sol.maximalSquare(grid);
		cout << ans << endl;
	}
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}