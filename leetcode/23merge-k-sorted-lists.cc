#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*
Runtime: 28 ms, faster than 92.37% of C++ online submissions for Merge k Sorted Lists.
Memory Usage: 10.1 MB, less than 100.00% of C++ online submissions for Merge k Sorted Lists.
 */
class Solution {
  public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int n = lists.size();
		if (!n) return NULL;
		int lo = 0;
		int hi = n - 1;
		return helper(lo, hi, lists);
	}

  private:
	ListNode* helper(int lo, int hi, vector<ListNode*>& lists) {
		if (lo >= hi) return lists[lo];
		int mid = lo + (hi - lo) / 2;
		ListNode* right = helper(lo, mid, lists);
		ListNode* left = helper(mid + 1, hi, lists);
		return merge(right, left);
	}
	ListNode* merge(ListNode* right, ListNode* left) {
		ListNode dummy(0);
		ListNode* tail = &dummy;
		while (right && left) {
			if (right->val > left->val) {
				tail->next = left;
				left = left->next;
			} else {
				tail->next = right;
				right = right->next;
			}
			tail = tail->next;
		}
		if (right) tail->next = right;
		if (left) tail->next = left;
		return dummy.next;
	}
};


int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	Solution sol;
	// cout << sol.solution() << endl;
	system("pause");
	return 0;
}