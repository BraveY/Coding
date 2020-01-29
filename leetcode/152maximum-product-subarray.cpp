#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*
Runtime: 4 ms, faster than 89.21% of C++ online submissions for Maximum Product
Subarray. Memory Usage: 9.3 MB, less than 32.50% of C++ online submissions for
Maximum Product Subarray.
DC
 */
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    return helper(nums, 0, n - 1);
  }

 private:
  int helper(vector<int>& nums, int lo, int hi) {
    if (lo >= hi) return nums[hi];
    int mid = lo + (hi - lo) / 2;
    int left = helper(nums, lo, mid);
    int right = helper(nums, mid + 1, hi);
    int cross = 0;
    if (nums[mid] != 0) {  //中间元素等于0 就不存在交叉的情况
      int max_pos_left = 0;
      int min_neg_left = 0;
      int left_product = 1;
      int neg_left_nums = 0;
      int pos_left_nums = 0;
      for (int i = mid; i >= lo; i--) {
        if (nums[i] == 0) break;
        left_product *= nums[i];
        if (left_product > 0) {
          pos_left_nums++;
          max_pos_left = max(left_product, max_pos_left);
        } else if (left_product < 0) {
          neg_left_nums++;
          min_neg_left = min(left_product, min_neg_left);
        }
      }
      int max_pos_right = 0;
      int min_neg_right = 0;
      int right_product = 1;
      int neg_right_nums = 0;
      int pos_right_nums = 0;
      for (int i = mid + 1; i <= hi; i++) {
        if (nums[i] == 0) break;
        right_product *= nums[i];
        if (right_product > 0) {
          pos_right_nums++;
          max_pos_right = max(right_product, max_pos_right);
        } else if (right_product < 0) {
          neg_right_nums++;
          min_neg_right = min(right_product, min_neg_right);
        }
      }
      if (pos_right_nums > 0 && pos_left_nums > 0)
        cross = max(cross, max_pos_left * max_pos_right);
      if (neg_right_nums > 0 && neg_left_nums > 0)
        cross = max(cross, min_neg_right * min_neg_left);
    }
    return max(max(left, right), cross);
  }
};

/*
Runtime: 4 ms, faster than 89.21% of C++ online submissions for Maximum Product
Subarray. Memory Usage: 9.2 MB, less than 65.00% of C++ online submissions for
Maximum Product Subarray.
DP
 */
class Solution2 {
 public:
  int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    int max_now = nums[0];
    int min_now = nums[0];
    int ans = nums[0];
    for (int i = 1; i < n; i++) {
      int a = max_now * nums[i];
      int b = min_now * nums[i];
      max_now = max(max(nums[i], a), b);
      min_now = min(min(nums[i], a), b);
      ans = max(max_now, ans);
    }
    return ans;
  }

 private:
};

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution2 sol;
  std::vector<int> v({2, 3, -2, 4});
  cout << sol.maxProduct(v) << endl;
  system("pause");
  return 0;
}