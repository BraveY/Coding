#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(
      ListNode* l1,
      ListNode*
          l2) {  //返回的是指针，因此要么用原来存在的节点地址，要么用new来创建节点。
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        tail->next = l1;
        l1 = l1->next;
      } else {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }

    if (l1) tail->next = l1;
    if (l2) tail->next = l2;

    return dummy.next;
  }
};
class Solution2 {
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* rtn;
    ListNode* ind = rtn;
    while (l1 || l2) {
      if (l1 && l2) {
        if (l1->val >= l2->val) {
          ind->val = l2->val;
          l2 = l2->next;
        } else {
          ind->val = l1->val;
          l1 = l1->next;
        }
      } else if (l1 && !l2) {
        ind = l1;
        return rtn;
      } else {
        ind = l2;
        return rtn;
      }
      ind = ind->next;
    }
    return rtn;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  // cout << sol.solution() << endl;
  system("pause");
  return 0;
}