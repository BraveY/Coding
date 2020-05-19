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
Runtime: 36 ms, faster than 67.78% of C++ online submissions for Surrounded Regions.
Memory Usage: 10.3 MB, less than 100.00% of C++ online submissions for Surrounded Regions.
 */
class Solution {
 public:
	void solve(vector<vector<char>>& board) {
		int m = board.size();
		if (!m) return;
		int n = board[0].size();
		unordered_map<char, char> v{//使用<>尖角括号
			{'C', 'O'}, {'X', 'X'}, {'O', 'X'}
		};
		for (int i = 0; i < m; i++) {
			dfsCapture(board, i, 0, m, n);
			dfsCapture(board, i, n - 1, m, n);
		}
		for (int j = 0; j < n; j++) {
			dfsCapture(board, 0, j, m, n);
			dfsCapture(board, m - 1, j, m, n);
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j] = v[board[i][j]];
			}
		}

	}
 private:
	void dfsCapture(vector<vector<char>>& board,
	                int i, int j, int m, int n) {
		if (i < 0 || i  >= m || j  < 0 || j  >= n)// 不越界
			return;
		if (board[i][j] == 'X' || board[i][j] == 'C') return; //c means no need Capture and visited;
		board[i][j] = 'C';
		dfsCapture(board, i - 1, j, m, n);
		dfsCapture(board, i, j - 1, m, n);
		dfsCapture(board, i + 1, j, m, n );
		dfsCapture(board, i, j + 1, m, n);

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
	// 	vector<vector<char>> grid(m, vector<char>(n));
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