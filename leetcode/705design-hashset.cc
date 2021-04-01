/*
 * @Author: your name
 * @Date: 2021-04-01 21:36:49
 * @LastEditTime: 2021-04-01 21:46:06
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode\705design-hashset.cc
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

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
/*
Bruet Force
Runtime: 92 ms, faster than 46.39% of C++ online submissions for Design HashSet.
Memory Usage: 180 MB, less than 9.68% of C++ online submissions for Design HashSet.
*/
class MyHashSet {
private:
    vector<int> dict;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        dict = vector<int> (1000001, 0);
    }
    
    void add(int key) {
        dict[key] = 1;
    }
    
    void remove(int key) {
        dict[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return dict[key] == 1 ? true : false;
    }
};


void debug() {

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