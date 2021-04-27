#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <sstream>
#include "../binarytree.h"

using namespace std;



/*
BFS  iteratively.
Runtime: 8 ms, faster than 37.39% of C++ online submissions for Symmetric Tree.
Memory Usage: 16.9 MB, less than 8.48% of C++ online submissions for Symmetric Tree.
 */
class Solution1 {
 public:
	bool mmetric(TreeNode* root) {
		if (!root) return true;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			vector<TreeNode*> level;
			int size = q.size();
			for (int i = size; i > 0; i--) {
				TreeNode* cur = q.front();
				q.pop();
				level.push_back(cur);
				if (cur) {
					q.push(cur->left);
					q.push(cur->right);
				}
			}
			for (int i = 0; i <= (size - 1) / 2; i++) {
				if (level[i] && level[size - 1 - i]) {
					if (level[i]->val != level[size - 1 - i]->val) return false;
				} else {
					if (level[i] != level[size - 1 - i]) return false;
				}

			}
		}
		return true;
	}

 private:
};

/*
递归，比较两颗数是否对称 ，树1左节点与树2右节点相等，树1右节点与树2左节点对称
Runtime: 16 ms, faster than 8.75% of C++ online submissions for Symmetric Tree.
Memory Usage: 16.3 MB, less than 8.48% of C++ online submissions for Symmetric Tree.
 */
class Solution {
 public:
	bool mmetric(TreeNode* root) {
		if (!root) return true;
		return isSame(root, root);
	}

 private:
	bool isSame(TreeNode* node1, TreeNode* node2) {
		if (node1 && node2) {
			return (node2->val == node1->val && isSame(node1->left, node2->right) &&
			        isSame(node1->right, node2->left));
		} else {
			if (node1 != node2) return false;
			else return true;
		}
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

		bool ret = Solution().mmetric(root);

		string out = boolToString(ret);
		cout << out << endl;
	}
}

void debug() {
	Treedebug();
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}