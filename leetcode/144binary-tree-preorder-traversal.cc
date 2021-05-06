#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> path;
        preDFS(root, path);
        return path;
    }
    void preDFS(TreeNode* root, vector<int>& path) {
        if (!root) return ;
        path.push_back(root->val);
        preDFS(root->left, path);
        preDFS(root->right, path);
    }
};


void debug() {
	Solution sol;



	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}

