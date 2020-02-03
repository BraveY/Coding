#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;
/*
Runtime: 4 ms, faster than 67.90% of C++ online submissions for Decode Ways.
Memory Usage: 8.6 MB, less than 50.98% of C++ online submissions for Decode
Ways. O(n) 空间 O(n) 时间
 */
class Solution {
 public:
  int numDecodings(string s) {
    int n = s.size();
    if (int(s.at(0) - '0') == 0) return 0;
    std::vector<int> opt(n + 1);
    opt[0] = 1;
    opt[1] = 1;
    for (int i = 2; i <= n; i++) {
      int num_now = int(s.at(i - 1) - '0');
      int num_last = int(s.at(i - 2) - '0');
      if (num_now == 0 && (num_last == 0 || num_last > 2)) return 0;
      if (num_now != 0) {
        if (num_last * 10 + num_now <= 26 && num_last != 0)
          opt[i] = opt[i - 2] + opt[i - 1];
        else
          opt[i] = opt[i - 1];
      } else
        opt[i] = opt[i - 2];
    }
    return opt[n];
  }

 private:
};

/*
Runtime: 4 ms, faster than 67.90% of C++ online submissions for Decode Ways.
Memory Usage: 8.5 MB, less than 70.59% of C++ online submissions for Decode
Ways. O(1)空间
 */
class Solution2 {
 public:
  int numDecodings(string s) {
    int n = s.size();
    if (int(s.at(0) - '0') == 0) return 0;
    int opt_1 = 1;
    int opt_2 = 1;
    for (int i = 2; i <= n; i++) {
      int num_now = int(s.at(i - 1) - '0');
      int num_last = int(s.at(i - 2) - '0');
      int opt;
      if (num_now == 0 && (num_last == 0 || num_last > 2)) return 0;
      if (num_now != 0) {
        if (num_last * 10 + num_now <= 26 && num_last != 0)
          opt = opt_2 + opt_1;
        else
          opt = opt_1;
      } else
        opt = opt_2;
      opt_2 = opt_1;
      opt_1 = opt;
    }
    return opt_1;
  }

 private:
};

int main(int argc, char const *argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution2 sol;
  cout << sol.numDecodings("12") << endl;
  system("pause");
  return 0;
}