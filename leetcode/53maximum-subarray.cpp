/*
https://leetcode.com/problems/maximum-subarray/
 */
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
DP解法
Runtime: 8 ms, faster than 72.96% of C++ online submissions for Maximum
Subarray. Memory Usage: 9.4 MB, less than 18.63% of C++ online submissions for
Maximum Subarray.
时间复杂度O(n),空间复杂度O(n)
 */
class Solution1 {
 public:
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int ans = nums[0];
    std::vector<int> opt(n, INT_MIN);
    for (int i = 1; i < n; i++) {
      opt[i] = opt[i - 1] > 0 ? nums[i] + opt[i - 1] : nums[i];
      ans = max(opt[i], ans);
    }
    return ans;
  }

 private:
};

/*
DP解法
Runtime: 4 ms, faster than 98.48% of C++ online submissions for Maximum
Subarray. Memory Usage: 9.3 MB, less than 74.51% of C++ online submissions for
Maximum Subarray. 时间复杂度O(n),空间复杂度O(1)
 */
class Solution2 {
 public:
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int ans = nums[0];
    int opt = nums[0];
    for (int i = 1; i < n; i++) {
      opt = opt > 0 ? nums[i] + opt : nums[i];
      ans = max(opt, ans);
    }
    return ans;
  }

 private:
};

/*
DC解法
Runtime: 948 ms, faster than 5.13% of C++ online submissions for Maximum
Subarray. Memory Usage: 9.6 MB, less than 5.88% of C++ online submissions for
Maximum Subarray. Maximum Subarray. 时间复杂度O(nlogn),空间复杂度O(1)/O(logn)
 */
class Solution3 {
 public:
  int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    if (0 == n) return INT_MIN;
    if (1 == n) return nums[0];
    return helper(nums, 0, n - 1);
  }

 private:
  int helper(vector<int>& nums, int lo, int hi) {
    if (lo >= hi) return nums[lo];
    int mid = lo + (hi - lo) / 2;
    int left = helper(nums, lo, mid);
    int left_max = nums[mid];
    int left_sum = 0;
    for (int i = mid; i >= lo; i--) {
      left_sum += nums[i];
      left_max = max(left_sum, left_max);
    }
    int right = helper(nums, mid + 1, hi);
    int right_max = nums[mid + 1];
    int right_sum = 0;
    for (int i = mid + 1; i <= hi; i++) {
      right_sum += nums[i];
      right_max = max(right_sum, right_max);
    }
    int cross = right_max + left_max;
    int max_all = max(max(left, right), cross);
    return max_all;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution3 sol;
  std::vector<int> vec({-2, 1, -3, 4, -1, 2, 1, -5, 4});
  cout << sol.maxSubArray(vec) << endl;
  system("pause");
  return 0;
}