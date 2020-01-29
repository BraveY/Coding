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
  int climbStairs(int n) {
    if (n <= 2) return n;
    int a = 1;
    int b = 2;
    int ans = 3;
    for (int i = 3; i <= n; i++) {
      ans = a + b;
      a = b;
      b = ans;
    }
    return ans;
  }

 private:
};

int main(int argc, char const *argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  cout << sol.climbStairs(5) << endl;
  system("pause");
  return 0;
}