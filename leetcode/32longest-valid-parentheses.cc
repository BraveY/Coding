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
O(n^3)
Time Limit Exceeded
*/
class Solution1 {
  public:
    int longestValidParentheses(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); ++i){
            for(int j = 0; j <= i; ++j){
                if(isvalid(j, i, s)){
                    ans = max(ans, i - j + 1);
                }
            }
        }
        return ans;
    }

  private:
    bool isvalid(int l, int r, string str ){
        if (l >= r) return false;
        stack<int> s;
        for(int i = l; i <= r; ++i ) {
            if(str[i] == '(') s.push(i);
            else if(str[i] == ')') {
                if(s.empty()) return false;
                else s.pop();
            }
        }
        return s.empty() ? true : false;
    }
};


/*
Runtime: 8 ms, faster than 39.53% of C++ online submissions for Longest Valid Parentheses.
Memory Usage: 7.7 MB, less than 64.32% of C++ online submissions for Longest Valid Parentheses.
*/
class Solution2 {
public:
    int longestValidParentheses(string s) {
        stack<int> iStack;
        int l = 0;
        int ans = 0;
        int n = s.size();
        for(int i = 0; i < n; ++i){
            if(s[i] == '(') {
                 iStack.push(i);
            }else{
                if(iStack.empty()) l = i + 1;
                else{
                iStack.pop();
                ans = max(ans, iStack.empty() ? i - l + 1 : i - iStack.top());
                }
            }
        }        
        return ans;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Valid Parentheses.
Memory Usage: 7.7 MB, less than 64.32% of C++ online submissions for Longest Valid Parentheses.
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        int ans = 0;
        for(int i = 1; i < n; ++i){
            if(s[i] == '(') continue;
            //后面为s[i] == ')
            if(s[i - 1] == '(') { // 与前一个匹配 （）  
                dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;
            }else{// 与更早之前的匹配(...)
                int j = i - dp[i - 1] - 1; //去除中间的匹配段之后的前面的左括号(
                if( j >= 0 && s[j] == '(' ) { // 最前面的(之前也有匹配的。
                    dp[i] = j - 1 >= 0 ? dp [i - 1] + 2 + dp[j - 1] : dp[i - 1] + 2;
                }
            }
            ans = max(ans, dp[i]);
        }
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