#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*
简单递归超时
 */
class Solution1 {
 public:
  int uniquePaths(int m, int n) {
    if (m == 1) return 1;
    if (n == 1) return 1;
    int ans = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    return ans;
  }

 private:
};
/*
使用二维空间表来存储状态
 */
class Solution2 {
 public:
  int uniquePaths(int m, int n) {
    if (m == 1) return 1;
    if (n == 1) return 1;
    vector<vector<int> > opt(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
      opt[i][1] = 1;
    }
    for (int j = 1; j <= n; j++) {
      opt[1][j] = 1;
    }
    for (int i = 2; i <= m; i++) {
      for (int j = 2; j <= n; j++) {
        opt[i][j] = opt[i - 1][j] + opt[i][j - 1];
      }
    }
    return opt[m][n];
  }

 private:
};
/*
只和左边与下边的状态相关，因此可以简化成一维数组，下边的状态就是旧的状态
循环的顺序要和列的状态表一致，从行到列。
 */
class Solution3 {
 public:
  int uniquePaths(int m, int n) {
    if (m == 1) return 1;
    if (n == 1) return 1;
    vector<int> opt(m + 1, 1);
    for (int i = 2; i <= n; i++) {
      for (int j = 2; j <= m; j++) {
        opt[j] = opt[j - 1] + opt[j];
      }
    }
    return opt[m];
  }

 private:
};

int main(int argc, char const *argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution3 sol;
  cout << sol.uniquePaths(7, 3) << endl;
  system("pause");
  return 0;
}