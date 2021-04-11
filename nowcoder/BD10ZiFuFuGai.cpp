/*
 * @Author: your name
 * @Date: 2021-04-11 11:01:32
 * @LastEditTime: 2021-04-11 12:00:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\nowcoder\BD10ZiFuFuGai.cpp
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
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>

using namespace std;

/*
运行时间：6ms
超过9.41%用C++提交的代码
占用内存：504KB
超过21.78%用C++提交的代码
*/
class Solution {
  private:
  public:
	string solution(string s, string t) {
        sort(t.rbegin(), t.rend());
        int j = 0;  
        for (int i = 0; i < s.size(); ++i){
            if (j < t.size() && s[i] < t[j]) {
                s[i] = t[j++];
            }
        }
        return s; 
    }
};



int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	Solution sol;
    string s, t;
    cin >> s >> t;
    cout << sol.solution(s, t) << endl;
	return 0;
}