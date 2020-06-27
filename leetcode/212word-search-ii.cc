#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*
Runtime: 1132 ms, faster than 9.24% of C++ online submissions for Word Search II.
Memory Usage: 13.6 MB, less than 93.56% of C++ online submissions for Word Search II.
 */
class Solution {
  public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> ans;
		for (auto str : words) {
			if (exist(board, str))
				ans.push_back(str);
		}
		return ans;
	}

  private:
	bool exist(vector<vector<char>>& board, const string& word) {
		m = board.size();
		n = board[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (word[0] == board[i][j]) {
					if (backtrack(board, word, i , j , 0))
						return true;
				}
			}
		}
		return false;
	}
	bool backtrack(vector<vector<char>>& board, const string& word, int i, int j, int d) {
		if (word.length() == d) return true;
		if ( i < 0 || i > m - 1 || j < 0 || j > n - 1) return false;
		if (word[d] != board[i][j]) return false;
		board[i][j] = '1';
		// string next = word.substr(1);
		bool found = backtrack(board, word, i, j - 1, d + 1)
		             || backtrack(board, word, i, j + 1, d + 1)
		             || backtrack(board, word, i - 1, j, d + 1)
		             || backtrack(board, word, i + 1, j, d + 1);
		board[i][j] = word[d];
		return found;
	}
	int m , n;
};

class Solution2 {
  public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> ans;
		unordered_map<char, vector<string>> begin;
		unordered_map<string, int> memo;
		for (auto str : words) {
			if (!begin.count(str[0])) {
				begin[str[0]] = {};
			}
			begin[str[0]].push_back(str);
			memo[str] = 0;
		}
		m = board.size();
		n = board[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (begin.count(board[i][j])) {
					for (auto str : begin[board[i][j]]) {
						if (backtrack(board, str, i, j , 0) && !memo[str]) {
							ans.push_back(str);
							memo[str] = 1;
						}
					}
				}
			}
		}
		return ans;
	}

  private:
	bool exist(vector<vector<char>>& board, const string& word) {
		m = board.size();
		n = board[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (word[0] == board[i][j]) {
					if (backtrack(board, word, i , j , 0))
						return true;
				}
			}
		}
		return false;
	}
	bool backtrack(vector<vector<char>>& board, const string& word, int i, int j, int d) {
		if (word.length() == d) return true;
		if ( i < 0 || i > m - 1 || j < 0 || j > n - 1) return false;
		if (word[d] != board[i][j]) return false;
		board[i][j] = '1';
		// string next = word.substr(1);
		bool found = backtrack(board, word, i, j - 1, d + 1)
		             || backtrack(board, word, i, j + 1, d + 1)
		             || backtrack(board, word, i - 1, j, d + 1)
		             || backtrack(board, word, i + 1, j, d + 1);
		board[i][j] = word[d];
		return found;
	}
	int m , n;
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