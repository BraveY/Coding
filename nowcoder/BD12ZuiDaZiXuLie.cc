/*
 * @Author: your name
 * @Date: 2021-04-11 12:01:13
 * @LastEditTime: 2021-04-11 12:01:13
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\nowcoder\BD12ZuiDaZiXuLie.cc
 */
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string solution(string s){
        string rtn;    
        for(int i = 0; i < s.size(); ++i){
            string sorted = s.substr(i);
            sort(sorted.rbegin(), sorted.rend());            
            if (s[i] == sorted[0]) {
                rtn += s[i];
            }
        }
        return rtn;
    }    
};

int main(int argc, char const *argv[]){
    string s;
    cin >> s;
    Solution sol;
    cout << sol.solution(s) << endl;
    return 0;
}