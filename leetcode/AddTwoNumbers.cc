/*
https://leetcode.com/problems/add-two-numbers/submissions/
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1Ind = l1;
        ListNode* l2Ind = l2;
        ListNode* AnsListHead = new ListNode(0);
        ListNode* AnsListInd = AnsListHead;
        ListNode* AnsListNext;
        while(l1Ind != NULL || l2Ind != NULL){
            int sum = 0; 
            int carry = 0;
            if(l1Ind!=NULL && l2Ind == NULL) sum = l1Ind->val;
            else if (l1Ind==NULL && l2Ind != NULL) sum = l2Ind->val;
            else sum = l1Ind->val + l2Ind->val;
            sum += AnsListInd->val; //需要首先在此就计算sum+carry不然的话可能出现sum<10 而加上carry之后大于10了却没有进位。
            if(sum >= 10){
                sum = sum %10;
                carry = 1 ;
            }
            AnsListNext = new ListNode(carry);
            AnsListInd->val = sum;
            if(l1Ind!=NULL) l1Ind=l1Ind->next;
            if(l2Ind!=NULL) l2Ind=l2Ind->next;
            if(l1Ind == NULL && l2Ind == NULL && carry==0) { //此处增加一个结束的判断，增加carry==0,不然的话后面始终会出现一个0节点。
                AnsListInd->next = NULL;
                break;
            }
            AnsListInd->next = AnsListNext;
            AnsListInd = AnsListNext;
        }
        return AnsListHead;
    }
};