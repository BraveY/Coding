#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <string>
#include <sstream>


using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
Runtime: 16 ms, faster than 96.05% of C++ online submissions for Kth Smallest Element in a BST.
Memory Usage: 19.3 MB, less than 100.00% of C++ online submissions for Kth Smallest Element in a BST.
 */
class Solution {
  public:
	int count = 0;
	int ans = INT_MIN;
	int kthSmallest(TreeNode* root, int k) {
		DFS(root, k);
		return ans;
	}

  private:
	//DFS中只用进行一次count 计数，也就是当前节点的计数
	//其他的子节点的计数在递归中完成。
	void DFS(TreeNode* root, int k) {
		if (!root) return;
		DFS(root->left, k);
		count ++;
		if (count == k) ans = root->val;
		DFS(root->right, k);
	}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	if (!input.size()) {
		return nullptr;
	}

	string item;
	stringstream ss;
	ss.str(input);

	getline(ss, item, ',');
	TreeNode* root = new TreeNode(stoi(item));
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);

	while (true) {
		TreeNode* node = nodeQueue.front();
		nodeQueue.pop();

		if (!getline(ss, item, ',')) {
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int leftNumber = stoi(item);
			node->left = new TreeNode(leftNumber);
			nodeQueue.push(node->left);
		}

		if (!getline(ss, item, ',')) {
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int rightNumber = stoi(item);
			node->right = new TreeNode(rightNumber);
			nodeQueue.push(node->right);
		}
	}
	return root;
}

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		TreeNode* root = stringToTreeNode(line);
		getline(cin, line);
		int k = stringToInteger(line);

		int ret = Solution().kthSmallest(root, k);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}