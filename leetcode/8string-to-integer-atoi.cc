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
class Solution {
  public:
    int myAtoi(string s) {
        long long result = 0;
        int sign = 1;
        int i = 0;
        while( s[i] == ' ') {
            ++i;
        }
        if (s[i] == '+' || s[i] == '-' ) {
            sign = s[i++] == '+' ? 1 : -1;
        }else if (!isdigit(s[i])) return 0;
        while(i < s.size() && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (result*sign <= INT_MIN) return INT_MIN;
            if (result*sign >= INT_MAX) return INT_MAX;
            ++i;
        }
        return result*sign;
    }  
	int myAtoiFunc(string str) {
        long long result = 0;
        int sign = 1;
        int i = str.find_first_not_of(' '); // 用循环替代
        if (i < 0) {
            return 0;
        }
        if (str[i] == '+' || str[i] == '-') {
            sign = str[i++] == '+' ? 1 : -1;
        }
        while(isdigit(str[i]) && i < str.size()) {
            result = result * 10 + str[i++] - '0';
            if (result * sign >= INT_MAX) return INT_MAX;
            if (result * sign <= INT_MIN) return INT_MIN;
        }
        return result * sign;
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
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}