#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include <pair>
#include "../lclist.h"

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
/*
Runtime: 12 ms, faster than 88.56% of C++ online submissions for Reverse Nodes in k-Group.
Memory Usage: 11.6 MB, less than 21.63% of C++ online submissions for Reverse Nodes in k-Group.
*/
class Solution {
  private:
    void reverse(ListNode* head, ListNode* tail) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* tmp = nullptr;
        while(cur) {
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }        
    }
  public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* lastTail = &dummy;
        ListNode* curNode = lastTail->next;
        ListNode* curHead = curNode;
        ListNode* nextHead;
        int cnt = 1;
        while(curNode && cnt <= k) {
            if (cnt == k) {
                nextHead = curNode->next;
                curNode->next = nullptr;
                curHead = lastTail->next;
                reverse(curHead, curNode);
                lastTail->next = curNode;
                lastTail = curHead;
                lastTail->next = nextHead;                
                curNode = nextHead;
                cnt = 1;
            }else{
                curNode = curNode->next;
                ++cnt;    
            }        
        }
        return dummy.next;
    }
};


void debug() {
	Solution sol;

	//一维数组的输入
	// vector<int> nums1 = {1, 2, 3, 0, 0, 0};
	// vector<int> nums2;
	// int i;
	// while (cin >> i) {
	// 	nums2.push_back(i);
	// }
	// cout << sol.solution(nums2) << endl;

	//二维数组的输入
	//int m, n;
	// while (cin >> m >> n) {
	// 	vector<vector<int>> grid(m, vector<int>(n));
	// 	for (int i = 0; i < m; i++) {
	// 		for (int j = 0; j < n; j++ ) {
	// 			cin >> grid[i][j];
	// 		}
	// 	}
	// 	int ans = sol.solution(grid);
	// 	cout << ans << endl;
	// }
	// vector<vector<int>> grid{{1,3,1},{1,5,1},{4,2,1}};
	//二叉树输入
	//TreeNode* root = stringToTreeNode("[3,9,20,null,null,15,7]")
	//链表输入使用lclist.h
    //ListNode* head = stringToListNode("[1,3,2]");
	// prettyPrintLinkedList(head);
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}