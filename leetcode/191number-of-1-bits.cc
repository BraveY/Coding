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
  int hammingWeight(uint32_t n) {
    int i = 32;
    int count = 0;
    while (i) {
      if (n % 2 == 1) count++;
      n = n >> 1;
      i--;
    }
    return count;
  }

 private:
};

int main(int argc, char const *argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  cout << sol.hammingWeight(3) << endl;
  system("pause");
  return 0;
}