/*https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking*/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *merge_head = nullptr;
        if(pHead1==nullptr) return pHead2;
        if(pHead2==nullptr) return pHead1;
        if(pHead1->val < pHead2->val){
            merge_head = pHead1;
            merge_head->next = Merge(pHead1->next, pHead2);
        }
        else{
            merge_head = pHead2;
            merge_head->next = Merge(pHead1, pHead2->next);
        }
        return merge_head;
    }
};