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
Runtime: 40 ms, faster than 96.20% of C++ online submissions for Word Search.
Memory Usage: 11.2 MB, less than 82.77% of C++ online submissions for Word Search.
 */
class Solution {
  public:
	bool exist(vector<vector<char>>& board, string word) {
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

  private:
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
	vector<vector<char>> board = {
		{'A', 'B', 'C', 'E'},
		{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'}
	};
	cout << sol.exist(board, "SEE") << endl;

	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}