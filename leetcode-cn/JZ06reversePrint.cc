/*
 * @Author: your name
 * @Date: 2021-03-10 20:47:54
 * @LastEditTime: 2021-03-10 21:45:46
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode-cn\JZ06reversePrint.cc
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
#include "../lclist.h"

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
/*
执行用时：
4 ms
, 在所有 C++ 提交中击败了
90.32%
的用户
内存消耗：
8.3 MB
, 在所有 C++ 提交中击败了
97.47%
的用户
*/
class Solution {
  public:
    vector<int> reversePrint(ListNode* head) {
        if (!head) {
            return {};
        }
        vector<int> ret;
        ListNode *cur = head;
        while (cur) { // !cur 为cur是空指针进入循环 !表示符合条件为无效，不加！表示符号条件的为有效
            ret.push_back(cur->val);
            cur = cur->next;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

  private:
};


void debug() {
	Solution sol;
    ListNode* head = stringToListNode("[1,3,2]");
    prettyPrintLinkedList(head);
    vector<int> vec = sol.reversePrint(head);
    cout_vector(vec);
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}