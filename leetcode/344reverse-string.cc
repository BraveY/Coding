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
Runtime: 48 ms, faster than 77.71% of C++ online submissions for Reverse String.
Memory Usage: 15.2 MB, less than 75.61% of C++ online submissions for Reverse
String.
 */
class Solution {
 public:
  void reverseString(vector<char>& s) {
    int n = s.size();
    int lo = 0, hi = n - 1;
    while (lo < hi) {
      swap(s[lo], s[hi]);
      lo++;
      hi--;
    }
  }

 private:
};

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  std::vector<char> vec({'h', 'e', 'l', 'l', 'o'});
  sol.reverseString(vec);
  for (auto iter = vec.begin(); iter != vec.end(); iter++) {
    cout << *iter;
  }
  system("pause");
  return 0;
}