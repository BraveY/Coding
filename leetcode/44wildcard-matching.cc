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
Runtime: 96 ms, faster than 33.78% of C++ online submissions for Wildcard
Matching. Memory Usage: 13 MB, less than 46.15% of C++ online submissions for
Wildcard Matching.
 */
class Solution {
 public:
  bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();
    std::vector<vector<bool> > opt(m + 1, vector<bool>(n + 1, false));
    opt[m][n] = true;               //代表两个空字符串,匹配。
    for (int i = m; i >= 0; i--) {  // s为空的时候还存在 ‘’ 和*的匹配
      for (int j = n - 1; j >= 0; j--) {  // p是空字符串的时候都为false，跳过
        bool first_match = ((s[i] == p[j]) || p[j] == '?');
        if (first_match &&
            i + 1 <= m) {  // i+1 <= m 是为了 ''和?的匹配，不加的话超界限
          opt[i][j] = opt[i + 1][j + 1];
        }
        if (p[j] == '*') {  //为*的时候选择 匹配或不匹配都可以
          if (i + 1 <= m)
            opt[i][j] = opt[i + 1][j] || opt[i][j + 1];
          else if (i == m)
            opt[i][j] = opt[i][j + 1];  //''和*的匹配 将*号移除
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
  Solution sol;
  cout << sol.isMatch("", "*") << endl;
  system("pause");
  return 0;
  }