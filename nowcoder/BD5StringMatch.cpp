/*
 * @Author: your name
 * @Date: 2021-04-10 14:11:30
 * @LastEditTime: 2021-04-10 15:30:17
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\nowcoder\BD5StringMatch.cpp
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
https://www.nowcoder.com/practice/6e6ad6338289498da79b7afb60e823b3?tpId=143&tqId=33929&rp=1&ru=%2Fta%2Fexam-baidu&qru=%2Fta%2Fexam-baidu%2Fquestion-ranking&tab=answerKey
运行时间：4ms
超过36.85%用C++提交的代码
占用内存：608KB
超过7.04%用C++提交的代码
*/
class Solution {
  private:
    int ans = 0;
    int match(string path, string A) { // string::find得实现
        int rtn = 0;
        int len = path.length();
        for (int i = 0; i + len <= A.length(); ++i) {
            string tmpStr = A.substr(i, len);
            if (tmpStr == path) {
                rtn = 1;
                return rtn;
            }
        }
        return rtn;
    }
    void backtrack(int cur, string& path, string& A, string& B) {
        if (cur == B.size()) {
            // if (match(path, A)) {
            if (A.find(path) != string::npos) { //返回npos表示未找到
                // cout << path << "   path.size: " << path.size() << endl;
                ans++;
            }
            return;
        }
        // if (match(path, A) == 0) return; 
        if (A.find(path) == string::npos) return; 
        char c = B[cur];
        if (c != '?') {
            path += c;
            backtrack(cur + 1, path, A, B);
            path.pop_back(); // 遇到正常得，返回之后也需要退回。
        }else {
            path += '0';
            backtrack(cur + 1, path, A, B);
            path.pop_back();
            path += '1';
            backtrack(cur + 1, path, A, B);
            path.pop_back();
        }
        return ;
    }
  public:
	int StringMatch(string A, string B) {
        int aLen = A.length();
        int bLen = B.length();
        // cout << "A.size: " << aLen << " B.size: " << bLen << endl;
        string path = "";
        if (bLen > aLen) return 0;  
        backtrack(0, path, A, B);
        return ans;
    }
};

class Solution2
{
private:
    /* data */
public:    
    void dfs(string a, string b, int i, int& count) {
        if(i == b.size()){
            // 已经搜索了b字符串的长度，如果当前的字符串在a中，结果就进行自增
            if(a.find(b) != string::npos)
                count ++;
                // cout << b << endl;
            return;
        }
        if(a.find(b.substr(0, i)) != string::npos){    // 剪枝，保证i之前的字符能够匹配成功
            // 位置i的字符未定就进行尝试，否则直接到下一个位置
            if(b[i] == '?'){
                b[i] = '0';
                dfs(a, b, i + 1, count);
                b[i] = '1';
                dfs(a, b, i + 1, count);
                b[i] = '?';
            }else
                dfs(a, b, i + 1, count);
        }
    }
};

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
    string A, B;
    // cin >> A >> B;
    A = "000000000100001000000001000011000000000010000";
    B = "??????0?????????????????????";
    Solution sol;
    cout <<sol.StringMatch(A, B) << endl;
    Solution2 sol2;
    int count = 0;
    sol2.dfs(A, B ,0, count);
    cout << count << endl;
	return 0;
}