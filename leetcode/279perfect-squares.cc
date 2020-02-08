#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;
/*
Runtime: 300 ms, faster than 12.04% of C++ online submissions for Perfect
Squares. Memory Usage: 155.9 MB, less than 5.77% of C++ online submissions for
Perfect Squares.
 */
class Solution1 {
 public:
  int numSquares(int n) {
    int m = sqrt(n);
    vector<vector<int> > opt(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) opt[1][i] = i;
    for (int i = 2; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (j < i * i)
          opt[i][j] = opt[i - 1][j];
        else {
          opt[i][j] = min(opt[i][j - i * i] + 1, opt[i - 1][j]);
        }
      }
    }
    return opt[m][n];
  }
};

/*
364 ms	156 MB
 */
class Solution2 {
 public:
  int numSquares(int n) {
    int m = sqrt(n);
    vector<vector<int> > opt(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) opt[1][i] = i;
    for (int i = 2; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (j < i * i)
          opt[i][j] = opt[i - 1][j];
        else {
          int k = j / (i * i);
          // 有个小的贪心把最大平方数给去掉直接转移到前i-1个
          opt[i][j] = min(opt[i - 1][j - k * i * i] + k, opt[i - 1][j]);
        }
      }
    }
    return opt[m][n];
  }

 private:
};
/*
优化空间
Runtime: 224 ms, faster than 16.91% of C++ online submissions for Perfect
Squares. Memory Usage: 11.5 MB, less than 50.00% of C++ online submissions for
Perfect Squares.
 */
class Solution3 {
 public:
  int numSquares(int n) {
    // int m = sqrt(n);  sqrt 计算耗时
    vector<int> opt(n + 1, 0);
    for (int i = 1; i <= n; i++) opt[i] = i;
    for (int i = 2; i * i <= n; i++) {
      for (int j = n; j >= 1; j--) {
        if (j >= i * i) {
          int k = j / (i * i);
          // 有个小的贪心把最大平方数给去掉直接转移到前i-1个
          opt[j] = min(opt[j - k * i * i] + k, opt[j]);
        }
      }
    }
    return opt[n];
  }

 private:
};

/*
Runtime: 100 ms, faster than 71.95% of C++ online submissions for Perfect
Squares. Memory Usage: 11.5 MB, less than 36.54% of C++ online submissions for
Perfect Squares.
 */
class Solution4 {
 public:
  int numSquares(int n) {
    int m = sqrt(n);
    vector<int> opt(n + 1, INT_MAX);
    opt[0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j * j <= i; j++) {
        opt[i] = min(opt[i], opt[i - j * j] + 1);  //不选opt[i],选了opt[i-j*j]
      }
    }
    return opt[n];
  }

 private:
};

int main(int argc, char const *argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution3 sol;
  cout << sol.numSquares(12) << endl;
  system("pause");
  return 0;
}