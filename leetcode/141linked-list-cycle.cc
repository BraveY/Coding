/*
 * @Author: your name
 * @Date: 2020-04-05 21:33:25
 * @LastEditTime: 2021-04-26 09:15:39
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode\141linked-list-cycle.cc
 */
#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>

using namespace std;



// * Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
  public:
	bool hasCycle(ListNode *head) {
		unordered_set<ListNode*> visited;
		while (head) {
			if (visited.count(head)) return true;
			visited.insert(head);
			head = head->next;
		}
		return false;
	}

  private:
};

class Solution2 {
  public:
	bool hasCycle(ListNode *head) {
        if (!head) return false;
		ListNode* slow = head;
		ListNode* fast = head->next;    
		while (fast) {
			//必须先判断next是否为空，否则出现空指针的引用
			if (!fast->next) return false;
			fast = fast->next->next;
			slow = slow->next;
			if (slow == fast) return true;
		}
		return false;
	}

  private:
};

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	Solution sol;
	// cout << sol.solution() << endl;
	system("pause");
	return 0;
}