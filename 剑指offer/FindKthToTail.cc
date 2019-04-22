/*https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&tqId=11167&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking*/
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==nullptr || k==0) return nullptr;
        ListNode *p_front = pListHead;
        ListNode *p_behind = pListHead;
        // 让两个指针的长度固定为k-1，像一把尺子一样 复杂度为O(N)
        for(int i=0; i<k-1; i++){
            if(p_front != NULL) p_front = p_front->next;
        }
        if(p_front == nullptr) return nullptr;
        while(p_front->next != nullptr){ // 遍历链表的条件是next指针不为空，不是自己不为空
            p_front = p_front->next;
            p_behind = p_behind->next;
        }
        return p_behind;
    }
};