/*
 * @Author: your name
 * @Date: 2021-03-27 10:30:57
 * @LastEditTime: 2021-03-27 16:42:03
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\interview\MSTransformString.cc
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

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
/*
字符串只有ABCD 4个字母，其中AB相邻就可以删除，CD相邻也可以删除，求经过删除后最终的字符串。
ABACDADA: 最后变为：AADA
CCDBAAC:   变为：CAC
*/
class Solution {
  public:
	string solution(string str) {
        string rtn;
        if (str.empty()) return "";
        stack<char> stk;
        stk.push(str[0]);
        int n = str.size();
        for (int i = 1; i < n; ++i) {
            while (!stk.empty() && stk.top() == 'A' && i < n && str[i] == 'B') //使用top的时候确保栈不为空。
            {
                stk.pop();
                ++i;
            }
            while (!stk.empty() && stk.top() == 'B' && i < n && str[i] == 'A')
            {
                stk.pop();
                ++i;
            }         
            while (!stk.empty() && stk.top() == 'C' && i < n &&  str[i] == 'D')
            {
                stk.pop();                
                ++i;
            }
            while (!stk.empty() && stk.top() == 'D' &&  i < n && str[i] == 'C')
            {
                stk.pop();
                ++i;
            }
            if(i < n ) stk.push(str[i]);                        
        }
        while(!stk.empty()) {
            rtn += stk.top();
            stk.pop();
        }
        reverse(rtn.begin(), rtn.end());
        return rtn;
    }

  private:
};


void debug() {
	Solution sol;
    string str = "CBACD";
    cout << sol.solution(str) << endl;
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
    Solution sol;
    int N;
    cin >> N;
    while(N--){
        string str;
        cin >> str;
        cout << sol.solution(str) << endl;
    }
	return 0;
}