#include "../lclist.h"
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
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Linked List II.
Memory Usage: 7.6 MB, less than 7.62% of C++ online submissions for Reverse Linked List II.
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head) return nullptr;
        if (left == right) return head; // 特殊情况，不用翻转
        ListNode* cur = head;
        ListNode* prevLeft = nullptr;
        ListNode* leftNode = nullptr;
        ListNode* rightNode = nullptr;
        ListNode* prev = nullptr;
        int cnt = 1;
        while(cnt != left){
            if (cnt == left - 1) prevLeft = cur;
            cur = cur->next;
            ++cnt;
        }
        leftNode = cur;        
        while(cnt != right + 1) {
            if (cnt == right) rightNode = cur;
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
            ++cnt;
        }
        leftNode->next = cur;
        if (!prevLeft) return rightNode; //特殊情况，翻转所有的
        prevLeft->next = rightNode;
        return head;
    }
};