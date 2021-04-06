/*
 * @Author: your name
 * @Date: 2021-04-05 14:51:34
 * @LastEditTime: 2021-04-05 19:53:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\剑指offer\JZ36-convert-binary-search-tree-to-sorted-doubly-linked-list.cc
 */
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
  public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        TreeNode* lastNodeInList = nullptr;
        ConvertNode(pRootOfTree, &lastNodeInList);
        TreeNode* headNode = lastNodeInList;
        while (headNode != nullptr && headNode->left != nullptr)
        {
            headNode = headNode->left;
        }
        return headNode;
    }

  private:
    void ConvertNode(TreeNode* curNode, TreeNode** lastNodeInList) {
        if (curNode == nullptr) return;
        if (curNode->left != nullptr) {
            ConvertNode(curNode->left, lastNodeInList);
        }

        curNode->left = *lastNodeInList;
        if (*lastNodeInList != nullptr) {
            (*lastNodeInList)->right = curNode;
        }        
        *lastNodeInList = curNode;
        
        if (curNode->right) {
            ConvertNode(curNode->right, lastNodeInList);
        }
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