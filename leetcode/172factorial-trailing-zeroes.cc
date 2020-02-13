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
因子中5的的个数。
 */
/*
Runtime: 4 ms, faster than 58.42% of C++ online submissions for Factorial
Trailing Zeroes. Memory Usage: 8.2 MB, less than 100.00% of C++ online
submissions for Factorial Trailing Zeroes.
 */
class Solution1 {
 public:
  int trailingZeroes(int n) {
    if (n == 0) return 0;
    int ans = 0;
    ans += n / 5 + trailingZeroes(n / 5);
    return ans;
  }

 private:
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Factorial
Trailing Zeroes. Memory Usage: 8.2 MB, less than 92.86% of C++ online
submissions for Factorial Trailing Zeroes.
 */
class Solution2 {
 public:
  int trailingZeroes(int n) {
    int ans = 0;
    while (n != 0) {
      ans += n / 5;
      n /= 5;
    }
    return ans;
  }

 private:
};

int main(int argc, char const *argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution2 sol;
  cout << sol.trailingZeroes(100) << endl;
  system("pause");
  return 0;
}