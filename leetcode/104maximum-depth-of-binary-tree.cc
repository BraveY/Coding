#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

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
/*
RRuntime: 12 ms, faster than 61.17% of C++ online submissions for Maximum Depth
of Binary Tree. Memory Usage: 19.6 MB, less than 52.75% of C++ online
submissions for Maximum Depth of Binary Tree.
 */
class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (!root) return 0;
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    return max(left_depth, right_depth) + 1;
  }
};

class Solution2 {
 public:
  int maxDepth(TreeNode* root) {
    if (!root) return 0;
    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);
    return max(left_depth, right_depth) + 1;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  // cout << sol.maxDepth() << endl;
  system("pause");
  return 0;
}