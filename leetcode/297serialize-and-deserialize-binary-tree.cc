#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include "../binarytree.h"

using namespace std;
/*
Runtime: 96 ms, faster than 29.55% of C++ online submissions for Serialize and Deserialize Binary Tree.
Memory Usage: 35.8 MB, less than 17.24% of C++ online submissions for Serialize and Deserialize Binary Tree.
 */
class Codec {
  public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string encode;
		encode += "[";
		if (!root) {
			encode += "]";
			return encode;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* cur = q.front();
			q.pop();
			if (cur) {
				encode += to_string(cur->val);
				q.push(cur->left);
				q.push(cur->right);
			} else {
				encode += "null";
			}
			encode += ",";
		}
		replace(encode.end() - 1, encode.end(), ',', ']');
		// int n = 10;
		// for (int i = 0; i < n; i++) {
		// 	encode += to_string(i);
		// 	if (i == n - 1)
		// 		encode += "]";
		// 	else
		// 		encode += ",";
		// }
		// string data = encode;
		// data = data.substr(1, encode.length() - 2);
		// cout << data;
		return encode;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		if (data.length() == 2) return nullptr;
		vector<string> split_str = split(data);
		queue<string> strq;
		for (int i = 0; i < split_str.size(); i++) {
			strq.push(split_str[i]);
		}
		queue<TreeNode*> nodeq;
		TreeNode* root = bulidTree(strq.front());
		if (!root) return nullptr;
		strq.pop();
		nodeq.push(root);
		while (!nodeq.empty()) {
			TreeNode* cur = nodeq.front();
			nodeq.pop();
			TreeNode* next = bulidTree(strq.front());
			strq.pop();
			if (next) {
				nodeq.push(next);
				cur->left = next;
			}
			next = bulidTree(strq.front());
			strq.pop();
			if (next) {
				nodeq.push(next);
				cur->right = next;
			}
		}
		return root;
	}

  private:
	vector<string> split(string& data) {
		data = data.substr(1, data.length() - 2);
		vector<string> rtn;
		string str;
		for (int i = 0; i < data.length(); i++)	{
			if (data[i] == ',') {
				rtn.push_back(str);
				str.clear();
			} else str += data[i];
		}
		rtn.push_back(str);
		for (auto i : rtn) {
			cout << i << ' ';
		}
		cout << endl;
		return rtn;
	}

	TreeNode* bulidTree(string val) {
		if (val.compare("null")) {
			TreeNode* root = new TreeNode(stoi(val));
			return root;
		} else return nullptr;
	}
};

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}

void Treedebug() {
	string line;
	while (getline(cin, line)) {
		TreeNode* root = stringToTreeNode(line);
		cout << Codec().serialize(root) << endl;
	}
}

void debug() {
	Treedebug();
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