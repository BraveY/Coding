#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*
Runtime: 336 ms, faster than 12.50% of C++ online submissions for Longest
Palindromic Substring. Memory Usage: 26.5 MB, less than 20.69% of C++ online
submissions for Longest Palindromic Substring.
 */
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

// Author: Huahua, 16 ms, 8.7 MB
class Solution2 {
 public:
  string longestPalindrome(string s) {
    const int n = s.length();
    auto getLen = [&](int l, int r) {  // 计算每个字符可扩展到的长度
      while (l >= 0 && r < n && s[l] == s[r]) {
        --l;
        ++r;
      }
      return r - l - 1;
    };
    int len = 0;
    int start = 0;
    for (int i = 0; i < n; ++i) {
      //(i,i)以自身为起点 （i，i+1）以中间为起点
      int cur = max(getLen(i, i), getLen(i, i + 1));
      if (cur > len) {
        len = cur;
        start = i - (len - 1) / 2;
      }
    }
    return s.substr(start, len);
  }

 private:
};

int main(int argc, char const *argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution2 sol;
  cout << sol.longestPalindrome("babad") << endl;
  system("pause");
  return 0;
}