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
/*
Runtime: 16 ms, faster than 86.12% of C++ online submissions for Longest
Palindromic Substring. Memory Usage: 8.8 MB, less than 78.62% of C++ online
submissions for Longest Palindromic Substring.
 */
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
/*
马拉车
Runtime: 24 ms, faster than 70.00% of C++ online submissions for Longest
Palindromic Substring. Memory Usage: 141.8 MB, less than 8.96% of C++ online
submissions for Longest Palindromic Substring.
 */
class Solution3 {
 public:
  string longestPalindrome(string s) {
    string T = padding(s);
    int n = T.length();
    std::vector<int> P(n);
    int C = 0, R = 0;
    for (int i = 1; i < n - 1; i++) {  //原字符串的开始长度1和n-2
      int i_mirror = 2 * C - i;
      if (R > i) {
        P[i] = min(R - i, P[i_mirror]);  //防止超出R
      } else {
        P[i] = 0;
      }
      //中心扩展法都要使用
      while (T.at(i + 1 + P[i]) == T.at(i - 1 - P[i])) {
        P[i]++;
      }
      if (i + P[i] > R) {
        C = i;
        R = i + P[i];
      }
    }
    int max_len = 0;
    int center = 0;
    for (int i = 1; i < n - 1; i++) {
      if (P[i] > max_len) {
        max_len = P[i];
        center = i;
      }
    }
    int start = (center - max_len) / 2;  //原始字符串下标
    return s.substr(start, max_len);
  }

 private:
  string padding(string& s) {
    int n = s.length();
    if (n == 0) return "^$";
    string rtn = "^";
    for (int i = 0; i < n; i++) {
      rtn = rtn+"#" + s.at(i); //不能使用+= 
    }
    rtn += "#$";
    return rtn;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution3 sol;
  cout << sol.longestPalindrome("babad") << endl;
  system("pause");
  return 0;
}