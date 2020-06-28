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
class Solution2 {
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

/*
Runtime: 164 ms, faster than 54.99% of C++ online submissions for Word Search II.
Memory Usage: 36.4 MB, less than 51.95% of C++ online submissions for Word Search II.
 */
class TrieNode {
  public:
	vector<TrieNode*> nodes;  //指向下一个节点，有26个可以选择
	const string* word; //对应的字符串
	TrieNode(): nodes(26), word(nullptr) {}
	~TrieNode() {
		for (auto node : nodes) delete node;
	}
};
class Solution {
  public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		TrieNode root;

		// Add all the words into Trie.
		for (const string& word : words) {
			TrieNode* cur = &root; // 每次从root开始构建
			for (char c : word) {
				auto& next = cur->nodes[c - 'a'];//字母的索引 从a开始
				if (!next) next = new TrieNode(); //没有已经建立的字符节点则新建
				cur = next;
			}
			cur->word = &word;
		}

		const int n = board.size();
		const int m = board[0].size();
		vector<string> ans;

		function<void(int, int, TrieNode*)> walk = [&](int x, int y, TrieNode * node) { //回溯的过程
			if (x < 0 || x == m || y < 0 || y == n || board[y][x] == '#')
				return;

			const char cur = board[y][x];
			TrieNode* next_node = node->nodes[cur - 'a'];

			// Pruning, only expend paths that are in the trie.
			if (!next_node) return;

			if (next_node->word) {
				ans.push_back(*next_node->word);
				next_node->word = nullptr;
			}

			board[y][x] = '#';
			walk(x + 1, y, next_node);
			walk(x - 1, y, next_node);
			walk(x, y + 1, next_node);
			walk(x, y - 1, next_node);
			board[y][x] = cur;
		};

		// Try all possible pathes.
		for (int i = 0 ; i < n; i++)
			for (int j = 0 ; j < m; j++)
				walk(j, i, &root);

		return ans;
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