#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>

using namespace std;

/*
TLE
 */
class Solution {
 public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		return helper(nums, n - 1);
	}

 private:
	bool helper(vector<int>& nums, int end) {
		if (end == 0) {
			return true;
		}
		bool ans = false;
		vector<bool> able;
		for (int i = 0; i <= end - 1; i++) {
			if (nums[i] >= end - i) able.push_back(helper(nums, i));
		}
		for (int j = 0; j < able.size(); j++) {
			if (ans == true) return true;
			ans = ans | able[j];
		}
		return ans;
	}
};

/*
Runtime: 1204 ms, faster than 5.42% of C++ online submissions for Jump Game.
Memory Usage: 18 MB, less than 5.26% of C++ online submissions for Jump Game.
 */
class Solution2 {
 public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		memo[0] = true;
		return helper(nums, n - 1);
	}

 private:
	bool helper(vector<int>& nums, int end) {
		if (memo.count(end)) return memo[end];
		bool ans = false;
		vector<bool> able;
		for (int i = 0; i <= end - 1; i++) {
			if (nums[i] >= end - i) {
				if (ans == true) break;
				ans = ans | helper(nums, i);
			}
		}
		memo[end] = ans;
		return memo[end];
	}
	unordered_map<int, bool> memo;
};

/*
Runtime: 8 ms, faster than 93.89% of C++ online submissions for Jump Game.
Memory Usage: 7.8 MB, less than 100.00% of C++ online submissions for Jump Game.
 */
class Solution3 {
 public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		int far = nums[0];
		for (int i = 0; i < n; i++) {
			if (i > far) //最远路径无法到达当前位置
				break;
			far = max(far, i + nums[i]);
		}
		return far >= n - 1;
	}

 private:
};

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	Solution sol;
	vector<int> nums = {2, 3, 1, 1, 4};
	cout << sol.canJump(nums) << endl;
	system("pause");
	return 0;
}