#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
  public:
	ListNode *detectCycle(ListNode *head) {
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast) {
			//必须先判断next是否为空，否则出现空指针的引用
			if (!fast->next) return NULL;
			fast = fast->next->next;
			slow = slow->next;
			if (slow == fast) break;
		}
		// 从while 循环中出来还有可能是fast为NULL的情况
		if (!fast) return NULL;
		ListNode* find = head;
		while (find != slow) {
			slow = slow->next;
			find = find->next;
		}
		return find;
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