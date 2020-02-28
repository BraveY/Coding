#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;
//有分支的递归
/*
Runtime: 224 ms, faster than 10.31% of C++ online submissions for Regular
Expression Matching. Memory Usage: 15.5 MB, less than 8.48% of C++ online
submissions for Regular Expression Matching.
 */
class Solution {
 public:
  bool isMatch(string s, string p) {
    if (p.empty()) return s.empty();
    bool first_match = (!s.empty() && (s[0] == p[0] || p[0] == '.'));
    if (p.length() >= 2 &&
        p[1] == '*') {  //*从头往后递归的，所以*只有在第二个位置才有意义
      return (isMatch(s, p.substr(2)) ||
              (first_match && isMatch(s.substr(1), p)));
      //*匹配0个，所以向后移动2个字符||*匹配的个数为正数，且第一个字符匹配，所以t-1，而pattern的格式仍然不变，因为*没有取0所以还存在
    } else {  //没有*的情况看后面的是否匹配
      return (first_match && isMatch(s.substr(1), p.substr(1)));
    }
    return false;
  }

 private:
};

/*
Runtime: 4 ms, faster than 93.47% of C++ online submissions for Regular
Expression Matching. Memory Usage: 8.9 MB, less than 69.49% of C++ online
submissions for Regular Expression Matching.
 */
class Solution2 {
 public:
  bool isMatch(string s, string p) {
    if (p.empty() || s.empty()) return false;
    // int m = s.length(), n = p.length();  为空仍然有匹配的 "" 和 "*"
    std::vector<vector<bool> > opt(m + 1, vector<bool>(n + 1, false));
    opt[m][n] = true;  //代表两个空字符串是否匹配
    for (int i = m; i >= 0; i--) {
      for (int j = n; j >= 0; j--) {
        if (i == m && j == n) continue;  // opt[m][n] 已经初始了
        bool first_match = (i < m && j < n && (s[i] == p[j] || p[j] == '.'));
        if (j + 1 < n && p[j + 1] == '*') {
          opt[i][j] = opt[i][j + 2] || (first_match && opt[i + 1][j]);
        } else {
          opt[i][j] = first_match && opt[i + 1][j + 1];
        }
      }
    }
    return opt[0][0];
  }

 private:
};

int main(int argc, char const *argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution2 sol;
  cout << sol.isMatch("aab","c*a*b*") << endl;
  system("pause");
  return 0;
}