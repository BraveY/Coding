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
Runtime: 184 ms, faster than 5.32% of C++ online submissions for Longest
Increasing Subsequence. Memory Usage: 110.9 MB, less than 6.25% of C++ online
submissions for Longest Increasing O(n^2) 时间和空间
 */
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    nums.push_back(INT_MAX);
    int n = nums.size();
    vector<vector<int> > opt(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n - 1; i++) {
      for (int j = 1; j <= n; j++) {
        if (nums[i - 1] < nums[j - 1])
          opt[i][j] = max(opt[i - 1][i] + 1, opt[i - 1][j]);
        else
          opt[i][j] = opt[i - 1][j];
      }
    }
    return opt[n - 1][n];
  }

 private:
};

// huahua
class Solution2 {
 public:
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    memo = vector<int>(n, 0);
    int ans = 0;
    for (int i = 0; i < n; ++i) ans = max(ans, LIS(nums, i));
    return ans;
  }

 private:
  vector<int> memo;
  // length of LIS ends with nums[r]
  int LIS(const vector<int>& nums, int r) {
    if (r == 0) return 1;
    if (memo[r] > 0)
      return memo[r];  // 记忆化递归
                       // 退出的条件还有个查表，如果已经计算过则直接返回
    int ans = 1;
    for (int i = 0; i < r; ++i)
      if (nums[r] > nums[i]) ans = max(ans, LIS(nums, i) + 1);
    memo[r] = ans;
    return memo[r];
  }
};

class Solution3 {
 public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    int n = nums.size();
    auto opt = vector<int>(n, 1);
    for (int i = 1; i < n; ++i)
      for (int j = 0; j < i; ++j)
        if (nums[i] > nums[j]) opt[i] = max(opt[i], opt[j] + 1);
    return *max_element(opt.begin(), opt.end());
  }
};
/*
https://www.cnblogs.com/grandyang/p/4938187.html
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest
Increasing Subsequence. Memory Usage: 8.7 MB, less than 62.50% of C++ online
submissions for Longest Increasing Subsequence.
 */
class Solution4 {
 public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> opt;
    for (int i = 0; i < n; i++) {
      int lo = 0, hi = opt.size();
      while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (opt[mid] < nums[i])
          lo = mid + 1;
        else
          hi = mid;
      }
      if (hi >= opt.size())
        opt.push_back(nums[i]);
      else
        opt[hi] = nums[i];
    }
    return opt.size();
  }
};
int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution4 sol;
  std::vector<int> vec({10, 9, 2, 5, 3, 7, 101, 18});
  cout << sol.lengthOfLIS(vec) << endl;
  system("pause");
  return 0;
}