#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  //只用一维opt[i]来表示不可行，因为与前一个字符形成的回文的可能是所有状态的。比如回文是1到i-1
  //则与i形成回文的范围是从0到i。都是有可能的
  string longestPalindrome(string s) {
    int n = s.length();
    if (n == 0 || n == 1) return s;
    string ans = s.substr(0, 1);
    vector<vector<bool>> opt(n, vector<bool>(n));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i; j < n; j++) {
        if (j - i == 0)
          opt[i][j] = true;                         //单个字符构成回文
        else if (j - i == 1 && s.at(i) == s.at(j))  //两个相邻 相等字符构成回文
          opt[i][j] = true;
        else if (s.at(i) == s.at(j) && opt[i + 1][j - 1])
          opt[i][j] = true;
        if (opt[i][j] && j - i + 1 > ans.length())
          ans = s.substr(i, j - i + 1);  //长度比现有答案的长度大就更新。
      }
    }
    return ans;
  }

 private:
};

int main(int argc, char const *argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  cout << sol.longestPalindrome("babad") << endl;
  system("pause");
  return 0;
}