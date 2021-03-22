/*
 * @Author: your name
 * @Date: 2021-03-16 23:05:14
 * @LastEditTime: 2021-03-18 13:32:24
 * @LastEditors: Please set LastEditors
 * @Description: C专家编程中关于int 和uint 比较的bug 实验， 书P24
 * @FilePath: \Coding\exps\CExperts_bugtest.cc
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

using namespace std;



// #define TOTAL_ELEMENTS (sizeof(array) / sizeof(array[0]))



void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';                            
	}
	cout << endl;
}
class Solution {
  public:
	int compareSingnedAndUnsigned() {
        int array[] = { 23, 34,12,17,204,99,16};
        int d = -1, x;
        if (d <= (int) (sizeof(array) / sizeof(array[0])) - 2){ // 不加int 不会进入if语句
            cout << d << endl;
            x = array[d+1];            
            cout << x << endl;cout << d << endl;
        }
        cout << d << endl;
        return 0;
    }

	void stringMerge() {
		char *resource[] = {
			"monitor",
			"disk",
			"mouse"
			"keybord",
			"pen",
		};
		cout << resource[2] << endl;
	}
  private:
};


void debug() {
	Solution sol;

    sol.stringMerge();
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