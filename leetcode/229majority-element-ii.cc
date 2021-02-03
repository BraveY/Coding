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
Runtime: 20 ms, faster than 68.71% of C++ online submissions for Majority Element II.
Memory Usage: 15.8 MB, less than 92.16% of C++ online submissions for Majority Element II.
*/
class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    int n1 = 0;
    int c1 = 0;
    int n2 = 1; // 必须将n1 与n2 设置为不同的值
    int c2 = 0;
    for (int num : nums) {
      if (num == n1) {
        ++c1;
      } else if (num == n2) {
        ++c2;
      } else if (c1 == 0) {
        n1 = num;
        c1 = 1;
      } else if (c2 == 0) {
        n2 = num;
        c2 = 1;
      } else {
        --c1;
        --c2;
      }
    }
    
    c1 = c2 = 0;
    for (int num : nums) {
      if (num == n1) ++c1;
      else if (num == n2) ++c2;
    }
    
    const int c = nums.size() / 3;
    vector<int> ans;
    if (c1 > c) ans.push_back(n1);
    if (c2 > c) ans.push_back(n2);
    return ans;
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
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}