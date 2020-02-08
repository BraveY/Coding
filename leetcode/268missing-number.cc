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
  int missingNumber(vector<int>& nums) {
    int64_t n = nums.size();
    int64_t ans = n * (n + 1) / 2;
    for (int i = 0; i < n; i++) {
      ans -= nums[i];
    }
    return ans;
  }

 private:
};

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  std::vector<int> v({0, 2, 3});
  Solution sol;
  cout << sol.missingNumber(v) << endl;
  system("pause");
  return 0;
}