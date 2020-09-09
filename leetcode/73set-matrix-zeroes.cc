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
Runtime: 24 ms, faster than 94.45% of C++ online submissions for Set Matrix Zeroes.
Memory Usage: 13.7 MB, less than 5.26% of C++ online submissions for Set Matrix Zeroes.
space:O(m*n)
 */
class Solution1 {
  public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>> dummy(m, vector<int>(n, 1));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					for (int k = 0; k < m; ++k) {
						dummy[k][j] = 0;
					}
					for (int k = 0; k < n; ++k) {
						dummy[i][k] = 0;
					}
				} else {
					if (dummy[i][j] != 0) dummy[i][j] = matrix[i][j];
				}
			}
		}
		matrix = dummy;
	}

  private:
};

/*
Runtime: 24 ms, faster than 94.45% of C++ online submissions for Set Matrix Zeroes.
Memory Usage: 13.3 MB, less than 53.91% of C++ online submissions for Set Matrix Zeroes.
space:O(m + n)
 */
class Solution2 {
  public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		vector<int> row;
		vector<int> col;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					row.push_back(i);
					col.push_back(j);
				}
			}
		}
		for (int i = 0; i < row.size(); ++i) {
			for (int j = 0; j < n; ++j) {
				matrix[row[i]][j] = 0;
			}
		}
		for (int i = 0; i < col.size(); ++i) {
			for (int j = 0; j < m; ++j) {
				matrix[j][col[i]] = 0;
			}
		}
	}

  private:
};

/*
Runtime: 28 ms, faster than 77.73% of C++ online submissions for Set Matrix Zeroes.
Memory Usage: 13.2 MB, less than 71.57% of C++ online submissions for Set Matrix Zeroes.
 */
class Solution {
  public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		bool row0 = false;
		bool col0 = false;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					if (i == 0) row0 = true;
					if (j == 0) col0 = true;
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				if (matrix[0][j] == 0 || matrix[i][0] == 0)
					matrix[i][j] = 0;
			}
		}
		if (row0) {
			for (int i = 0; i < n; ++i) {
				matrix[0][i] = 0;
			}
		}
		if (col0) {
			for (int i = 0; i < m; ++i) {
				matrix[i][0] = 0;
			}
		}
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