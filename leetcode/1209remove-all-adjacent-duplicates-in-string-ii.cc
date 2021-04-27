/*
 * @Author: your name
 * @Date: 2021-04-27 20:25:32
 * @LastEditTime: 2021-04-27 21:29:13
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode\1209remove-all-adjacent-duplicates-in-string-ii.cc
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
#include <stack>
#include <utility>

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
/*
Runtime: 32 ms, faster than 18.27% of C++ online submissions for Remove All Adjacent Duplicates in String II.
Memory Usage: 14 MB, less than 14.71% of C++ online submissions for Remove All Adjacent Duplicates in String II.
stack and pair 
#include <utility>
make_pair(char c, int i);
*/
class Solution {
  private:
  public:
    string removeDuplicates(string s, int k) {
        int len = s.size();
        if (!len) return "";
        string ans = "";
        stack<pair<char, int> > stk;
        int idx = 0;
        int cnt = 1;                
        while(idx < len) {
            if (stk.empty()) {
                stk.push(make_pair(s[idx++], 1));                
            }else {
                cnt = stk.top().second;
                if (s[idx] == stk.top().first) {
                    cnt++;              
                }else{
                    cnt = 1;
                }
                stk.push(make_pair(s[idx++], cnt));
                if (cnt == k) {
                    while (cnt--) stk.pop();                
                }                
            }            
        }
        while(!stk.empty()) {
            ans += stk.top().first;
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


void debug() {
	Solution sol;

    string s = "deeedbbcccbdaa";
    cout << sol.removeDuplicates(s, 3) << endl;
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}