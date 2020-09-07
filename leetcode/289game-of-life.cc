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
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Game of Life.
Memory Usage: 7.2 MB, less than 41.50% of C++ online submissions for Game of Life.
 */
class Solution1 {
  public:
	void gameOfLife(vector<vector<int>>& board) {
		int m = board.size();
		if (!m) return ;
		int n = board[0].size();
		if (!n) return;
		vector<vector<int>> state(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				int liveCount = 0;
				if (i - 1 >= 0 && board[i - 1][j]) ++liveCount;
				if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1]) ++liveCount;
				if (i - 1 >= 0 && j + 1 < n && board[i - 1][j + 1]) ++liveCount;
				if (j - 1 >= 0 && board[i][j - 1]) ++liveCount;
				if (j + 1  < n && board[i][j + 1]) ++liveCount;
				if (i + 1 < m && board[i + 1][j]) ++liveCount;
				if (i + 1 < m && j - 1 >= 0 && board[i + 1][j - 1]) ++liveCount;
				if (i + 1 < m && j + 1 < n && board[i + 1][j + 1]) ++liveCount;
				if (board[i][j]) { //live
					if (liveCount < 2) state[i][j] = 0;
					else if (liveCount == 2 || liveCount == 3) state[i][j] = 1;
					else state[i][j] = 0;
				} else {
					if (liveCount == 3) state[i][j] = 1;
					else state[i][j] = 0;
				}
			}
		}
		board = state;
	}

  private:
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Game of Life.
Memory Usage: 7 MB, less than 67.48% of C++ online submissions for Game of Life.
 */
class Solution {
  public:
	void gameOfLife(vector<vector<int>>& board) {
		int m = board.size();
		if (!m) return ;
		int n = board[0].size();
		if (!n) return;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				int count = liveCount(board, i, j, m, n);
				if (count == 3 || count - board[i][j] == 3) board[i][j] |= 2; //high bit set to 1; no matter live or dead
			}
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				board[i][j] >>= 1;
			}
		}
	}
  private:
	int liveCount(vector<vector<int>>& board, int i, int j, int m, int n) {
		int count = 0;
		for (int I = max(i - 1, 0); I < min(i + 2, m); ++I) {
			for (int J = max(j - 1, 0); J < min(j + 2, n); ++J) {
				count += board[I][J] & 1;
			}
		}
		return count;
	}
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