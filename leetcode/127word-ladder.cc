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
#include <queue>
using namespace std;

/*
BFS / Brute Force/ Single direction
Runtime: 124 ms, faster than 75.87% of C++ online submissions for Word Ladder.
Memory Usage: 15.1 MB, less than 59.09% of C++ online submissions for Word Ladder.
 */
class Solution1 {
 public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());//可以直接使用vector初始
		if (!dict.count(endWord)) return 0;

		queue<string> q;
		//表示这个单词从修改第几个字母获得的。相当于记录完整的变换过程
		//可以不需要 ，只优化少了一次字母的遍历，不是很大。
		unordered_map<string, int> words;
		words[beginWord] = -1;
		q.push(beginWord);

		int l = beginWord.length();
		int step = 0;

		while (!q.empty()) {
			++step;
			for (int size = q.size(); size > 0; size--) { // last level nodes
				string w = q.front();
				q.pop();
				int loc = words[w];
				for (int i = 0; i < l; i++) {
					if (i == loc) continue;//从loc变换过来的，所以可以不考虑再变换loc位置
					char ch = w[i];
					for (int j = 'a'; j <= 'z'; j++) {
						w[i] = j;
						//找到解
						if (w == endWord) return step + 1; //字符串比较直接==
						//变换的词不在dict中
						if (!dict.count(w)) continue;
						// 在字典中存储 代表已经访问过了
						words[w] = i;
						//已经确定可以走的节点删除，如果使用过的节点重新在走一遍，路径只会变长
						dict.erase(w);
						q.push(w);
					}
					w[i] = ch; //改了之后复位
				}
			}
		}
		return 0;

	}

 private:
};

/*
Runtime: 1240 ms, faster than 11.06% of C++ online submissions for Word Ladder.
Memory Usage: 27.3 MB, less than 34.09% of C++ online submissions for Word Ladder.
 */
class Solution2 {
 public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		wordList.push_back(beginWord);

		unordered_map<string, int> dict;
		for (int i = 0; i < wordList.size(); i++) {
			dict[wordList[i]] = 0;
		}
		if (!dict.count(endWord)) return 0;

		unordered_map<string, vector<string>> graph;
		buildGraph(wordList, graph);
		queue<string> q;

		q.push(beginWord);
		int step = 0;
		while (!q.empty()) {
			step++;
			for (int size = q.size(); size > 0; size--) {
				string cur = q.front();
				q.pop();
				for (string node : graph[cur]) {
					if (node == endWord) return step + 1 ;
					if (dict[node]) continue; //已经访问过了
					dict[node] = 1;
					q.push(node);
				}
			}
		}
		return 0;

	}

 private:
	bool canchange(string& a, string& b) {
		int diff = 0;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != b[i]) diff++;
		}
		return diff == 1;
	}
	void buildGraph(vector<string>& wordList, unordered_map<string, vector<string>>& graph) {
		int n = wordList.size();
		//init
		for (int i = 0; i < n; i++) {
			graph[wordList[i]] = vector<string> ();
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (canchange(wordList[i], wordList[j])) {
					graph[wordList[i]].push_back(wordList[j]);
					graph[wordList[j]].push_back(wordList[i]);
				}
			}
		}
	}
};


/*
BFS Bi direction
Runtime: 44 ms, faster than 93.14% of C++ online submissions for Word Ladder.
Memory Usage: 12.6 MB, less than 100.00% of C++ online submissions for Word Ladder.
 */
class Solution {
 public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());//可以直接使用vector初始
		if (!dict.count(endWord)) return 0;

		unordered_set<string> q1{beginWord};
		unordered_set<string> q2{endWord};

		int l = beginWord.length();
		int step = 0;

		while (!q1.empty() && !q2.empty()) {
			++step;
			if (q1.size() > q2.size()) swap(q1, q2);
			unordered_set<string> q;
			for (string w : q1) {
				for (int i = 0; i < l; i++) {
					char ch = w[i];
					for (int j = 'a'; j <= 'z'; j++) {
						w[i] = j;
						if (q2.count(w)) return step + 1;
						if (!dict.count(w)) continue;
						dict.erase(w);
						q.insert(w);
					}
					w[i] = ch;
				}
			}
			swap(q, q1);
		}
		return 0;

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
	// cout << sol.solution() << endl;

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
	string a = "hit";
	string b = "cog";
	vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
	cout << sol.ladderLength(a, b, wordList) << endl;
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}