#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
//动态规划从小到大求解状态会造成花过多时间和内存在计算前面状态，如果为0的状态在很后面则不能快速求解，从而TLE
class TLESolution {
 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    int n = s.length();
    int m = wordDict.size();
    // std::vector<vector<string>> memo(n + 1);
    unordered_map<int, vector<string>> memo;
    unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
    set<int> lens;
    for (int i = 0; i < m; i++) {
      lens.insert(wordDict[i].length());
    }
    std::vector<bool> opt(n + 1);
    opt[0] = true;
    for (int i = 1; i <= n; i++) {
      for (auto j = lens.begin(); j != lens.end(); j++) {
        // int len = wordDict[j].length();
        int len = *j;
        if (len <= i) {
          const string word = s.substr(i - 1 - len + 1, len);
          if (opt[i - len] && dict.count(word)) {
            opt[i] = true;
            int l = memo[i - len].size();
            if (!l)
              memo[i].push_back(word);
            else {
              for (int k = 0; k < l; k++) {
                memo[i].push_back(memo[i - len][k] + " " + word);
              }
            }
          }
        }
      }
    }
    return memo[n];
  }

 private:
};

/*https://zxi.mytechroad.com/blog/leetcode/leetcode-140-word-break-ii/*/
//记忆化递归可以快速的判断无解的情况
class Solution {
 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
    return wordBreak(s, dict);
  }

 private:
  // >> append({"cats and", "cat sand"}, "dog");
  // {"cats and dog", "cat sand dog"}
  vector<string> append(const vector<string>& prefixes, const string& word) {
    vector<string> results;
    for (const auto& prefix : prefixes) results.push_back(prefix + " " + word);
    return results;
  }

  const vector<string>& wordBreak(string s, unordered_set<string>& dict) {
    // Already in memory, return directly
    if (memo.count(s)) return memo[s];

    // Answer for s
    vector<string> ans;

    // s in dict, add it to the answer array
    if (dict.count(s)) ans.push_back(s);

    for (int j = 1; j < s.length(); ++j) {
      // Check whether right part is a word
      const string& right = s.substr(j);
      if (!dict.count(right)) continue;

      // Get the ans for left part
      const string& left = s.substr(0, j);
      const vector<string> left_ans = append(wordBreak(left, dict), right);

      // Notice, can not use memo here,
      // since we haven't got the ans for s yet.
      ans.insert(ans.end(), left_ans.begin(), left_ans.end());
    }

    // memorize and return
    memo[s].swap(ans);
    return memo[s];
  }

 private:
  unordered_map<string, vector<string>> memo;
};

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  const string s =
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaaa";
  vector<string> wordDict({"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa",
                           "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"});
  std::vector<string> ans = sol.wordBreak(s, wordDict);
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
  cout << ans.size() << endl;
  system("pause");
  return 0;
}