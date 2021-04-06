/*
 * @Author: your name
 * @Date: 2021-04-05 19:54:19
 * @LastEditTime: 2021-04-05 20:38:12
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode\109convert-sorted-list-to-binary-search-tree.cc
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
#include "../lclist.h"

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
/*
Runtime: 16 ms, faster than 99.55% of C++ online submissions for Convert Sorted List to Binary Search Tree.
Memory Usage: 30.9 MB, less than 67.64% of C++ online submissions for Convert Sorted List to Binary Search Tree.
特殊情况的处理:mid == head 只有一个的时候直接返回
*/
class Solution {
  public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        TreeNode *root = new TreeNode(0);
        ListNode* mid = getMidListNode(head);
        if (mid == head) { //只有一个节点
            root->val = mid->val;
            return root;
        }
        ListNode* rightHead = mid->next;
        ListNode* leftTail = head;
        while (leftTail->next != mid)
        {
            leftTail = leftTail->next;
        }
        leftTail->next = nullptr; // cut the list

        root->val = mid->val;
        root->left = sortedListToBST(head);        
        root->right = sortedListToBST(rightHead);

        return root;

    }

  private:
    ListNode* getMidListNode(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* mid = head;
        ListNode* cur = head;
        while(cur != nullptr && cur->next != nullptr){
            cur = cur->next->next;
            mid = mid->next;
        }
        return mid;
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