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
将数组统统异或，所有相同的数字异或后抵消，只剩下单个没有异或的，返回就可以了
异或运算时位操作 0^0=0 0^1=1，操作后二进制对应的有值，不是只返回true/false
*/
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int n = nums.size();
    int single = 0;
    for (int i = 0; i < n; i++) {
      single ^= nums[i];
    }
    return single;
  }

 private:
};

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  cout << sol.singleNumber() << endl;
  system("pause");
  return 0;
}