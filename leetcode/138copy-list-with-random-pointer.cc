#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
  public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

/*
Runtime: 24 ms, faster than 19.58% of C++ online submissions for Copy List with Random Pointer.
Memory Usage: 11.5 MB, less than 10.52% of C++ online submissions for Copy List with Random Pointer.
 */
class Solution {
  public:
	Node* copyRandomList(Node* head) {
		Node* copyNodeHead = new Node(head->val);
		Node* cur = head->next;
		Node* curLast = copyNodeHead;
		unordered_map<Node*, int> Node2Index;//origin
		unordered_map<int, Node*> Index2Node;//new
		Node2Index[head] = 0;
		Index2Node[0] = curLast;
		int index = 1;
		while (cur) {
			Node* curCopy = new Node(cur->val);
			Index2Node[index] = curCopy;
			Node2Index[cur] = index;
			curLast->next = curCopy;
			curLast = curCopy;
			cur = cur->next;
			index++;
		}
		Node* oriCur = head;
		Node* newCur = copyNodeHead;
		while (oriCur) {
			if (oriCur->random) {
				int randindex = Node2Index[oriCur->random];
				newCur->random = Index2Node[randindex];
			}
			oriCur = oriCur->next;
			newCur = newCur->next;
		}

		return copyNodeHead;
	}

  private:
};

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}

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
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}