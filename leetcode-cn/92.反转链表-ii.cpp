    /*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include "lclist.h"
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) return nullptr;
        ListNode dummyNode = ListNode();
        ListNode* dummy = &dummyNode;
        dummy->next = head;
        int idx = 1;
        ListNode* prev = dummy;
        ListNode* cur = head;

        while (cur && idx < left)
        {
            prev = cur;
            cur = cur->next;
            ++idx;
        }
        
        ListNode* leftLastNode = prev;
        leftLastNode->next = nullptr;
        ListNode* reverseTail = cur;

        while(cur && idx <= right) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
            ++idx;
        }

        ListNode* reverseHead = prev;
        ListNode* rightHead = cur;

        leftLastNode->next = reverseHead;
        reverseTail->next = rightHead;

        return dummy->next;
    }
};
// @lc code=end
