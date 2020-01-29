/*
https://leetcode.com/problems/invert-binary-tree/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
Runtime: 4 ms, faster than 62.29% of C++ online submissions for Invert Binary
Tree. Memory Usage: 10 MB, less than 5.45% of C++ online submissions for Invert
Binary Tree.
 */
class Solution1 {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (!root) return NULL;
    TreeNode* tmp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(tmp);
    return root;
  }

 private:
};

class Solution2 {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (!root) return NULL;
    invertTree(root->right);
    invertTree(root->left);
    swap(root->left, root->right);
    return root;
  }

 private:
};

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution1 sol;
  system("pause");
  return 0;
}