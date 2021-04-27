#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// * Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

/*
Runtime: 12 ms, faster than 37.34% of C++ online submissions for Reverse Linked
List. Memory Usage: 9.9 MB, less than 5.34% of C++ online submissions for
Reverse Linked List.
 */
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (!head) return NULL;
    ListNode* iter = head;
    ListNode* last = NULL; //一定要考虑将头部的next指向null元素，不能直接将last置为head,会变成循环链表。
    while (iter) {  //最后一个末尾元素也要改变指针指向。
      ListNode* tmp = iter->next;
      iter->next = last;
      last = iter;
      if (!tmp) break;  // 为空说明到了最后一个元素
      iter = tmp;
    }
    return iter;
  }

 private:
};

/*
Runtime: 8 ms, faster than 87.44% of C++ online submissions for Reverse Linked
List. Memory Usage: 10 MB, less than 5.34% of C++ online submissions for Reverse
Linked List. 递归的方法是返回最末尾的元素，然后当前节点的指针反向
 */
class Solution2 {
 public:
  ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* rtn = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;  //第一个节点的反向
    return rtn;
  }

 private:
};

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  cout << sol.reverseList(NULL) << endl;
  system("pause");
  return 0;
}