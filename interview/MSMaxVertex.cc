/*
 * @Author: your name
 * @Date: 2021-03-27 10:30:31
 * @LastEditTime: 2021-03-27 16:57:51
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\interview\MSMaxVertex.cc
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
无向图中，共有N个节点，M条边AB两个数组存放节点，对应形成边(A[i], B[i])。每条边的权重为两个节点值之和。
为N个节点分配值1至N,求分配后最大的节点和。
贪心法：
统计出度+入度，因为每个出入度的值都会参与一次计算，所以根据连通度排序后进行值得分配。
*/
class Solution {
  public:
	int solution(int N, vector<int>& A, vector<int>& B) {
		vector<int> connectivity(N, 0);
		for (auto ele : A)
			connectivity[ele - 1]++;
		for (auto ele : B)
			connectivity[ele - 1]++;
		int res = 0;
		sort(connectivity.rbegin(), connectivity.rend());// 使用拟迭代器将排序从增序变为降序。
		for (auto ele : connectivity) {
			if (ele == 0)
				continue;
			else
				res += N-- * ele;
		}
		return res;
	}

  private:
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