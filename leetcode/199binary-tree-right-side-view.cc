#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include "../lclist.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> ans;
        vector<TreeNode*> cur;
        vector<TreeNode*> next;
        cur.push_back(root);
        while(!cur.empty()) {
            ans.push_back(cur[0]->val);
            for(auto node : cur) {
                if (node->right) next.push_back(node->right);
                if (node->left) next.push_back(node->left);
            }
            cur.clear();
            swap(cur, next);
        }
        return ans;
    }
};