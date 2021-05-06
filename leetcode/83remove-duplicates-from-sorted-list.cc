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
class Solution {
  private:
  public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* prev = head;
        ListNode* cur = head->next;
        while(cur) {            
            if (cur->val != prev->val) {                
                prev = cur;
                cur = cur->next;
            }else{
                ListNode* toDelte = cur;
                cur = toDelte->next;
                delete toDelte;
            }
            prev->next = cur;
        }
        return head;
    }
};


void debug() {
	Solution sol;
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}