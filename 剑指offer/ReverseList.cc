/*https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking*/
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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==nullptr) return nullptr;
        ListNode *p_ind = pHead;
        ListNode *p_front = pHead;
        ListNode *p_next;
        // 利用两个指针分别存储前一个值和后一个值
        while(p_ind != nullptr){
            p_next = p_ind->next;
            if(p_ind == pHead){
                p_ind->next = nullptr;
            }else{
                p_ind->next = p_front;
                p_front = p_ind;
            }
            if (p_next ==nullptr) break;
            p_ind = p_next;
        }
        return p_ind;
    }
};