/*
 * @Author: your name
 * @Date: 2021-04-10 15:43:20
 * @LastEditTime: 2021-04-10 16:12:36
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\nowcoder\BD8KuoHaoPiPei.cpp
 */
/*
 * @Author: your name
 * @Date: 2019-11-22 15:00:25
 * @LastEditTime: 2021-04-10 14:22:45
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \Coding\solution_template.cc
 */
#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <numeric>

using namespace std;

/*
https://www.nowcoder.com/practice/fe8d6a1b88af4ba6b4dbb10972059040?tpId=143&tqId=33932&rp=1&ru=%2Fta%2Fexam-baidu&qru=%2Fta%2Fexam-baidu%2Fquestion-ranking&tab=answerKey
运行时间：6ms
超过7.35%用C++提交的代码
占用内存：528KB
超过15.22%用C++提交的代码
*/
class Solution {
  private:
  public:
	string solution(string inputStr) {
        stack<int> stk;
        int len = inputStr.length();
        int i = 0;
        int l = 0, r = 0;
        string rtnStr;
        string leftStr = "";
        string rightStr = "";
        while (i < len)
        {
            char c = inputStr[i];
            if (c == '[') {
                stk.push(i);
            }else {
                if (!stk.empty()) stk.pop();
                else {
                    ++l;
                }
            }
            ++i;
        }
        while (!stk.empty())
        {
            stk.pop();
            ++r;
        }        
        for(int j = 0; j < l; ++j) {
            leftStr += "[";
        }
        for(int j = 0; j < r; ++j) {
            rightStr += "]";
        }
        rtnStr += leftStr;
        rtnStr += inputStr;
        rtnStr += rightStr;
        return rtnStr;
    }
};


int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
    Solution sol;
    string inputStr;
    cin >> inputStr;
    cout << sol.solution(inputStr) << endl;
	return 0;
}