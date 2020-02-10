#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

/*
Runtime: 16 ms, faster than 50.07% of C++ online submissions for Word Break.
Memory Usage: 15.9 MB, less than 24.53% of C++ online submissions for Word
Break.
 */
class Solution1 {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    //将wordDict中的的元素记录在hashset中，方便查找一个字符串是否在wordDict中
    unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
    return wordBreak(s, dict);  //重载
  }

  bool wordBreak(const string& s, const unordered_set<string>& dict) {
    if (memo.count(s)) return memo[s];  //已经求过s的答案 直接返回
    if (dict.count(s)) return memo[s] = true;  // s就在wordDict中
    for (int j = 1; j < s.length(); j++) {
      const string left = s.substr(0, j);
      const string right = s.substr(j);
      if (dict.count(right) && wordBreak(left, dict)) return memo[s] = true;
    }
    return memo[s] = false;
  }

 private:
  unordered_map<string, bool> memo;
};

/*
Runtime: 12 ms, faster than 61.68% of C++ online submissions for Word Break.
Memory Usage: 15.7 MB, less than 26.41% of C++ online submissions for Word
Break.
 */
class Solution2 {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    //将wordDict中的的元素记录在hashset中，方便查找一个字符串是否在wordDict中
    unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
    int n = s.length();
    std::vector<bool> opt(n + 1);
    opt[0] = true;
    for (int i = 1; i <= n; i++) {
      // const string sub = s.substr(0, i);
      for (int j = 0; j < i; j++) {
        // const string right = sub.substr(j);
        if (dict.count(s.substr(j, i - j)) && opt[j]) {
          opt[i] = true;
          break;
        }
      }
    }
    return opt[n];
  }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Word Break.
Memory Usage: 8.9 MB, less than 92.45% of C++ online submissions for Word Break.
 */
class Solution3 {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    //将wordDict中的的元素记录在hashset中，方便查找一个字符串是否在wordDict中
    unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
    int n = s.length();
    int m = wordDict.size();
    std::vector<bool> opt(n + 1);
    opt[0] = true;
    for (int i = 1; i <= n; i++) {
      // const string sub = s.substr(0, i);
      for (int j = 0; j < m; j++) {
        int len = wordDict[j].length();
        if (len <= i && opt[i - len] &&
            dict.count(s.substr(i - 1 - len + 1, len))) {
          opt[i] = true;
          break;
        }
      }
    }
    return opt[n];
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution3 sol;
  const string  s = "leetcode";
  vector<string> wordDict({"leet","code"});
  cout << sol.wordBreak(s,wordDict) << endl;
  system("pause");
  return 0;
}