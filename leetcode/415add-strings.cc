/*
 * @Author: your name
 * @Date: 2021-04-21 23:07:02
 * @LastEditTime: 2021-04-21 23:28:28
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode\415add-strings.cc
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
Runtime: 4 ms, faster than 78.72% of C++ online submissions for Add Strings.
Memory Usage: 6.7 MB, less than 49.01% of C++ online submissions for Add Strings.
*/
class Solution {
  private:
  public:
	string addStrings(string num1, string num2){
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<char> convertDict = {
            '0','1','2','3','4','5','6','7','8','9'
        };
        string rtn = "";
        if (num1.size() > num2.size()) swap(num1, num2);
        int digit = 0;
        int i = 0;
        for(int i = 0; i < num2.size(); ++i) {
            int a = 0;
            if (i < num1.size())  a = num1[i] - '0';            
            int b = num2[i] - '0';
            int c;
            if (a + b + digit >= 10) {
                c = a + b + digit - 10;
                digit = 1;
            } else {
                c = a + b + digit;
                digit = 0;
            }
            rtn += convertDict[c];
        }
        if (digit) rtn += '1';
        reverse(rtn.begin(), rtn.end());
        return rtn;
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