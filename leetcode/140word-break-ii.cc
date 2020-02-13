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

/*
https://zxi.mytechroad.com/blog/leetcode/leetcode-140-word-break-ii/
Runtime: 16 ms, faster than 69.32% of C++ online submissions for Word Break II.
Memory Usage: 15.1 MB, less than 54.55% of C++ online submissions for Word Break
II.
 */
class Solution {
 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
    return wordBreak(s, dict);
  }

 private:
  // >> append({"cats and", "cat sand"}, "dog");
  // {"cats and dog", "cat sand dog"}
  vector<string> append(const vector<string>& left, const string& right) {
    vector<string> rtn;
    //左边为空的时候，不会加上右边，返回的也是空
    for (const auto& iter : left) rtn.push_back(iter + " " + right);
    return rtn;
  }

  const vector<string> wordBreak(string s, unordered_set<string>& dict) {
    if (memo.count(s)) return memo[s];
    int n = s.length();
    // 空字符串的处理？空字符串默认为vector也为空，所以不用处理

    //记录答案
    vector<string> ans;
    //如果完整字符串在字典里则直接加入到答案，
    //之所以提出来写是因为wordBreak("")为空，因此直接加上right，
    //不加上“ ”,不使用append函数
    if (dict.count(s)) ans.push_back(s);
    //不从0开始分割，为0的情况在上面if语句中已经判断过了
    for (int i = 1; i < n; i++) {
      const string& right = s.substr(i);
      //先判断右边是否在字典中，这也是记忆化递归能比动态规划快的原因，
      //不会先去求解，从而造成TLE，而是先判断是否需要求解
      if (dict.count(right)) {
        const string& left = s.substr(0, i);
        const vector<string> left_ans =
            append(wordBreak(left, dict), right);  //左边的结果加上新的末尾
        //不能使用
        // memo[s]来填充,因为还没算完,只是其中一种解。所以后续的递归如果访问了memo[s]，结果是不一致的
        // memo[s].swap(
        //     append(left_ans, right));
        ans.insert(ans.end(), left_ans.begin(),
                   left_ans.end());  //将left_ans的答案添加到ans
      }
    }
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