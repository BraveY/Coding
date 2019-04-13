/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    /* 递归实现
    vector<int> reverse_list;
    vector<int> printListFromTailToHead(ListNode* head) {
        if (head != NULL){
            (/*if (head->next == NULL) reverse_list.push_back(head->val);
            else reverse_list = printListFromTailToHead(head->next);
            使用这种逻辑，不能ac，大量样例不能通过，还需要分析下
            )


            if(head->next != NULL){
                reverse_list = printListFromTailToHead(head->next);
            }
            reverse_list.push_back(head->val);
        }
        return reverse_list;
    }
    */
   // 栈的实现
    vector<int> printListFromTailToHead(ListNode* head) {
        std::stack<int> val_stack;
        vector<int> reverse_list;
        while(head != NULL){
            val_stack.push(head->val);
            head = head->next;
        }
        
        while(!val_stack.empty()){
            reverse_list.push_back(val_stack.top());
            val_stack.pop();
        }
        return reverse_list;
    }
};
