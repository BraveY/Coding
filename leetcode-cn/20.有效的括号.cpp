/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <stack>
#include <string>
class Solution {
  public:
	bool isValid(string s) {
		int len = s.length();
		stack<int> left;
		unordered_map<char, char> dict = { //使用map来简化代码，更优雅
			{'}', '{'}, {']', '['}, {')', '('}
		};
		for (int i = 0; i < len; ++i) {
			if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
				left.push(s[i]);
			} else {
				if (!left.size()) return false;
				if (left.top() != dict[s[i]]) return false;
				else left.pop();
			}
		}
		if (left.size()) return false;
		return true;
	}

  private:
};
// @lc code=end

