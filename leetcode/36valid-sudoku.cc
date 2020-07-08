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
Runtime: 28 ms, faster than 95.96% of C++ online submissions for Valid Sudoku.
Memory Usage: 18.9 MB, less than 46.80% of C++ online submissions for Valid Sudoku.
 */
class Solution {
  public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<int> memo(9, 0);
		for (int i = 0; i < 9; i++) {
			memo = vector<int>(9, 0);
			for (int j = 0; j < 9; j++) {
				char cur = board[i][j];
				// cout << cur << endl;
				if (cur != '.' ) {
					if (memo[cur - '1'] == 1) return false;
					else memo[cur - '1'] = 1;
				}
			}
		}
		// cout << "row" << endl;
		for (int i = 0; i < 9; i++) {
			memo = vector<int>(9, 0);
			for (int j = 0; j < 9; j++) {
				char cur = board[j][i];
				if (cur != '.' ) {
					if (memo[cur - '1'] == 1) return false;
					else memo[cur - '1'] = 1;
				}
			}
		}
		// cout << "col" << endl;
		for (int i = 0; i < 9; i += 3) {
			for (int j = 0; j < 9; j += 3) {
				memo = vector<int>(9, 0);
				// cout << i << " " << j << endl;
				for (int m = 0; m < 3; m++) {
					for (int n = 0; n < 3; n++) {
						char cur = board[m + i][n + j];
						if (cur != '.' ) {
							if (memo[cur - '1'] == 1) return false;
							else memo[cur - '1'] = 1;
						}
					}
				}
			}
		}
		return true;
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
	vector<vector<char>> board = {
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
	};
	cout << sol.isValidSudoku(board) << endl;
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