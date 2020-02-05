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
  uint32_t reverseBits(uint32_t n) {
    int bit[32];
    for (int i = 31; i >= 0; i--) {
      if (n % 2 == 1)  // 余数为1，则最低位为1
        bit[i] = 1;    //最低位变为最高为，完成逆序
      else
        bit[i] = 0;
      n = n >> 1;
    }
    int64_t ans = 0, d = 1;
    for (int i = 0; i < 32; i++) {
      ans += bit[i] * d;
      d *= 2;
    }
    return ans;
  }

 private:
};

int main(int argc, char const *argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  cout << sol.reverseBits(43261596) << endl;
  system("pause");
  return 0;
}