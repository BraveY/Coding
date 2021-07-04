/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}

/*
O(N^2)
TLE
*/
class Solution1 {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int nums_size = nums.size();
        // vector<int> repeated_nums(2*nums_size);
        // for(int i = 0; i < 2*nums_size; ++i) {
        //     repeated_nums[i] = nums[i % nums_size];
        // }

        vector<int> tmp;
        int max_sum = INT_MIN;
        for(int i = 0; i < nums_size; ++i) {
            tmp.clear();
            for(int j = i; j < i + nums_size; ++j) {
                tmp.push_back(nums[j % nums_size]);
            }
            max_sum = max(max_sum, maxSubarray(tmp));
        }
        return max_sum;
    }
private:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int max_sum = nums[0];
        for(int i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            max_sum = max(max_sum, dp[i]);
        }
        return max_sum;
    }
};

/*
 max_dp & min_dp
 注意全为0的情况
 执行用时: 84 ms
内存消耗: 41.9 MB
*/
class Solution2 {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int max_sum = nums[0];
        int min_sum = nums[0];
        int sum = nums[0];
        vector<int> max_dp(n);
        vector<int> min_dp(n);
        max_dp[0] = nums[0];
        min_dp[0] = nums[0];
        bool has_pos = nums[0] >= 0;

        for (int i = 1; i < n; ++i) {
            sum += nums[i];
            if (nums[i] >= 0) has_pos = true;
            max_dp[i] = max(max_dp[i - 1] + nums[i], nums[i]);
            max_sum = max(max_sum, max_dp[i]);
            min_dp[i] = min(min_dp[i - 1] + nums[i], nums[i]);
            min_sum = min(min_sum, min_dp[i]);
        }

        if (!has_pos) return max_sum;
        return max(max_sum, sum - min_sum);
    }
};

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        vector<int> prefix_sum(2 * n + 1);
        deque<int> dq;
        dq.push_back(0);

        for (int i = 1; i <= 2 * n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[(i - 1) % n];
        }

        for (int i = 1; i <= 2 * n; ++i) {
            //将超过距离的值排除
            while (!dq.empty() && dq.front() < i - n) { //因为是前缀值，所以可以包含i-n的索引，相减之后就是 i-n+1到i,长度刚好为n
                dq.pop_front();
            }
            ans = max(ans, prefix_sum[i] - prefix_sum[dq.front()]); // 计算前缀和的时候不能包括当前值的前缀和，否则就是没有选择元素。
            while (!dq.empty() && prefix_sum[i] <= prefix_sum[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {9, 8, -8, 1};
    cout << sol.maxSubarraySumCircular(nums) << endl;
}
// @lc code=end
