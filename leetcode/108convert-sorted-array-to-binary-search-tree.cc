#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
Runtime: 20 ms, faster than 86.80% of C++ online submissions for Convert Sorted
Array to Binary Search Tree. Memory Usage: 26.8 MB, less than 16.22% of C++
online submissions for Convert Sorted Array to Binary Search Tree.
 */
class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n = nums.size();
    if (!n) return NULL;
    return helper(nums, 0, n - 1);
  }

 private:
  TreeNode* helper(std::vector<int>& nums, int lo, int hi) {
    TreeNode* root = new TreeNode(0);  //必须使用new 来把内存创建在堆里
    if (lo > hi) {
      return NULL;  //不能用等号来表示，因为mid+1，与mid-1会造成这种情况
    }
    int mid = lo + (hi - lo) / 2;
    root->val = nums[mid];
    root->left = helper(nums, lo, mid - 1);
    root->right = helper(nums, mid + 1, hi);
    return root;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  // cout << sol.solution() << endl;
  system("pause");
  return 0;
}