#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) return false;
    vector<int> opt(sum / 2 + 1, 0);
    opt[0] = 1;  // 不管数字是什么一定可以选出和为0的。
    for (int i = 1; i <= n; i++) {
      // for (int& itor : opt) cout << itor << " ";
      // cout << endl;
      for (int j = sum / 2; j >= 0; j--) {
        if (nums[i - 1] <= j) opt[j] = max(opt[j], opt[j - nums[i - 1]]);
      }
    }
    if (opt[sum / 2]) return true;
    return false;
  }

 private:
};

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  std::vector<int> vec({1, 5, 11, 5});
  Solution sol;
  cout << sol.canPartition(vec) << endl;
  system("pause");
  return 0;
}