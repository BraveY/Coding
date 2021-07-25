/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */

// @lc code=start
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
#include <vector>
#include <queue>
#include "binarytree.h"
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> rtn;
        queue<TreeNode*> cur;
        queue<TreeNode*> next;
        cur.push(root);
        int flag = 0;        
        while (!cur.empty()) {
            vector<int> tmp;
            while (!cur.empty()) {
                TreeNode* node = cur.front();
                tmp.push_back(node->val);
                cur.pop();
                if (node->left) {
                    next.push(node->left);
                }
                if (node->right) {
                    next.push(node->right);
                }
            }
            if (flag) {
                reverse(tmp.begin(), tmp.end());
            }
            flag = ~flag;
            rtn.push_back(tmp);
            swap(cur, next);
        }
        return rtn;
    }
};
// @lc code=end

