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
  int titleToNumber(string s) {
    int n = s.length();
    if (n == 0) return 0;
    int64_t d = 1;
    int64_t ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      ans += d * (s.at(i) - 'A' + 1);
      d *= 26;
    }
    return ans;
  }

 private:
};

int main(int argc, char const *argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  cout << sol.titleToNumber("CFDGSXM") << endl;
  system("pause");
  return 0;
}