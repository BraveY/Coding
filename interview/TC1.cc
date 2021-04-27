/*
 * @Author: your name
 * @Date: 2021-04-18 20:35:22
 * @LastEditTime: 2021-04-18 20:44:20
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\interview\TC1.cc
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
 struct ListNode {
 int val;
 struct ListNode *next;
 };


class Solution1 {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param S ListNode类 val表示权值，next指向下一个元素
     * @return ListNode类
     */
    ListNode* head;
    ListNode* tail;
    ListNode* reverse(ListNode* S, ListNode* tail, int least) {
        if (!S || S->val == least) return nullptr;
        ListNode* cur = S;
        tail->next = cur; // become a  cycle
        ListNode* prevLeast;
        while(cur != nullptr && cur->val != least) {
            if (cur->next->val == least) {
                prevLeast = cur;                
            }
            cur = cur->next;            
        }
        prevLeast->next = nullptr;//break cycle
        tail = prevLeast;
        return cur;        
    }
    ListNode* solve(ListNode* S) {
        // write code here
        if (!S) return nullptr;
        vector<int> nums;
        head = S;
        ListNode* cur = S;
        while(cur != nullptr) {
            nums.push_back(cur->val);
            cur = cur->next;
            if (cur->next == nullptr) tail = cur;
        }
        cur = S;
        sort(nums.begin(), nums.end());
        int p = 0; // point to the least
        int least = nums[p];
        // while(1) {
        //     if (cur->val == least) {
        //         cur = cur->next;
        //     }
        //     cur = reverseList(cur, tail, least);
        // }
        head = reverse(cur, tail, least);
        return head;
    }
    
};
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param S ListNode类 val表示权值，next指向下一个元素
     * @return ListNode类
     */
    ListNode* solve(ListNode* head) {
        // write code here
        if (head == nullptr) return nullptr;
        int len = 1;
        ListNode* cur = head;
        while (cur->next)
        {
            cur=cur->next;
            len++;
        }
        auto tail = cur;
        tail->next =head;
        unsigned long long ans = ULLONG_MAX;
        int cnt = 0, i;
        for(i=0; i<=len-1; i++){
            cur=head;
            unsigned long long val = 0;
            for(int j = 0; j < i; j++){
                cur = cur->next;
            }
            for(int k =0; k < len; k++){
                val *= 10;
                val += cur->val;
                cur = cur->next;
            }
            if (val < ans){
                ans = val;
                cnt = i;
            }
        }
        tail->next = nullptr;
        tail = head;
        for(i = 0; i < cnt-1; i++){
            tail = tail->next;
        }
        cur =head;
        ListNode* prev = nullptr;
        while (tail->next != nullptr)
        {
            /* code */
            prev = cur;
            cur = cur->next;
            tail = tail->next;
        }
        prev->next = nullptr;
        tail->next = head;
        return cur;        
    }
};