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
  int getSum(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    return getSum(a ^ b, (unsigned int)(a & b) << 1);
  }

 private:
};

int main(int argc, char const *argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  int a = -2;
  unsigned int b = 2;
  cout << b << endl;
  Solution sol;
  cout << sol.getSum(3, -1) << endl;
  system("pause");
  return 0;
}