#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include "../binarytree.h"

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
class Solution {
  private:
    int DFS(TreeNode* root, int depth, bool& balanced){
        if (!root) return depth;
        int ldepth = DFS(root->left, depth + 1, balanced);
        int rdepth = DFS(root->right, depth + 1, balanced);
        if (balanced) {
            if (ldepth - 1 > rdepth || rdepth - 1 > ldepth)
            balanced = false;
        }
        return max(ldepth, rdepth);
    }
  public:
	bool isBalanced(TreeNode* root) {
        bool balanced = true;
        DFS(root, 0, balanced);
        return balanced;
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