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
Runtime: 12 ms, faster than 60.68% of C++ online submissions for Find the Duplicate Number.
Memory Usage: 7.6 MB, less than 100.00% of C++ online submissions for Find the Duplicate Number.
 */
class Solution1 {
  public:
    int findDuplicate(vector<int>& nums) {
        int l = 1;
        int r = nums.size();
        while (l < r) {
            int m = (r - l) / 2 + l;
            int count = 0; // len(nums <= m)
            for (int num : nums)
                if (num <= m) ++count;
            if (count <= m)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};

class Solution3 {
  public:
    int findDuplicate(vector<int>& nums) {
        //最开始的index是从0开始的
        int slow = nums[0];
        int fast = nums[0];
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        int find = 0;
        while (find != slow) {
            find = nums[find];
            slow = nums[slow];
        }
        return find;
    }
};

/*
TLE
 */
class Solution2 {
  public:
    int findDuplicate(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

  private:
    int helper(std::vector<int>& nums, int lo, int hi) {
        if (lo >= hi) return 0;
        int mid = lo + (hi - lo) / 2 ;
        int left = helper(nums, lo, mid);
        if (left > 0 ) return left;
        int right = helper(nums, mid + 1, hi);
        if (left == 0 && right == 0 ) {
            for (int i = lo; i <= mid; i++)
                for (int j = mid + 1; j <= hi; j++) {
                    if (nums[i] == nums[j]) return nums[i];
                }
        }
        return right;
    }
};



int main(int argc, char const *argv[]) {
    /* code */
    ios::sync_with_stdio(false);
    Solution sol;
    std::vector<int> nums({1, 3, 4, 2, 2});
    cout << sol.findDuplicate(nums) << endl;
    system("pause");
    return 0;
}