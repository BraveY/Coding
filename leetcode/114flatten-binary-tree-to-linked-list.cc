#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include "../binarytree.h"

using namespace std;

/*
Runtime: 8 ms, faster than 74.20% of C++ online submissions for Flatten Binary Tree to Linked List.
Memory Usage: 13.5 MB, less than 8.69% of C++ online submissions for Flatten Binary Tree to Linked List.
*/
class Solution {
  public:
    void flatten(TreeNode* root) {
        if(!root) return;
        DFS(root);
        int n = list.size();
        TreeNode* cur = root;
        cur->left = nullptr;
        for(int i = 1; i < n; ++i){
            cur->left = nullptr;
            cur->right = list[i];
            cur = cur->right;
        }
    }

  private:
    vector<TreeNode*> list;
    void DFS(TreeNode* root){
        if (!root) return;
        list.push_back(root);
        DFS(root->left);
        DFS(root->right);
    }
};

/*
Share my simple NON-recursive solution, O(1) space complexity!
https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/37010/Share-my-simple-NON-recursive-solution-O(1)-space-complexity!
把当前节点的右子树接到左子树的最右边的子节点下，保存了原始的位置信息。
*/
class Solution2 {
public:
    void flatten(TreeNode *root) {
		TreeNode*now = root;
		while (now)
		{
			if(now->left)
			{
                //Find current node's prenode that links to current node's right subtree
				TreeNode* pre = now->left;
				while(pre->right)
				{
					pre = pre->right;
				}
				pre->right = now->right;
                //Use current node's left subtree to replace its right subtree(original right 
                //subtree is already linked by current node's prenode
				now->right = now->left;
				now->left = NULL;
			}
			now = now->right;
		}
    }
};

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}

void debug() {
	Solution sol;
	string line = "[1,2,5,3,4,null,6]";
	TreeNode* root = stringToTreeNode(line);
    sol.flatten(root);
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}