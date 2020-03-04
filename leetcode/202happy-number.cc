#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isHappy(int n) {
    unordered_set<int> hash;
    hash.insert(n);
    while (1) {
      int next = get_next(n);
      if (next == 1) return true;
      if (hash.count(next))
        return false;
      else {
        hash.insert(next);
        n = next;
      }
    }
  }

 private:
  int get_next(int n) {
    int next = 0;
    while (n > 0) {
      int t = n % 10;
      next += t * t;
      n /= 10;
    }
    return next;
  }
};

int main(int argc, char const *argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  cout << sol.isHappy(19) << endl;
  system("pause");
  return 0;
}