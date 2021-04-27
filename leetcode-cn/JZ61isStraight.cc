/*
 * @Author: your name
 * @Date: 2021-04-16 21:28:06
 * @LastEditTime: 2021-04-16 22:12:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode-cn\JZ61isStraight.cc
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
/*执行用时：
4 ms
, 在所有 C++ 提交中击败了
56.21%
的用户
内存消耗：
9.9 MB
, 在所有 C++ 提交中击败了
36.77%
的用户
*/
class Solution {
  private:
  public:
	bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int gap = 0;
        int zeroCnt = 0;
        int i = 0;
        while (i < nums.size() && nums[i] == 0)
        {
            ++zeroCnt;
            ++i;
        }
        ++i;
        while (i < nums.size())
        {
            if (nums[i] == nums[i - 1] && nums[i] != 0) return false;           
            gap = nums[i] - nums[i - 1] - 1;
            if (gap <= zeroCnt) {               
                zeroCnt -= gap;
                ++i;
            }else return false;            
        }
        return true;
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