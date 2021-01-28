#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include <stack>

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
/*
Runtime: 12 ms, faster than 82.85% of C++ online submissions for Validate Stack Sequences.
Memory Usage: 15.4 MB, less than 79.43% of C++ online submissions for Validate Stack Sequences.
*/
class Solution {
  public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int m = pushed.size();
        int n = popped.size();
        if(m != n) return false;
        if(!m && !n) return true;
        int p1 = 0, p2 = 0;
        stack<int> s;
        while(p1 < m ) {
            s.push(pushed[p1++]);
            while (!s.empty() && s.top() == popped[p2])
            {
                s.pop();
                ++p2;
            }
            
        }        
        return s.empty();
    }

  private:
};


void debug() {
	Solution sol;

	//一维数组的输入
	vector<int> nums1 = {1, 2, 3, 4, 5};
	vector<int> nums2 = {4, 5, 3, 2, 1};
    sol.validateStackSequences(nums1, nums2);
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