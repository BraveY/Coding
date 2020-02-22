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
用hash map来存储的第一次出现的位置，然后又申请了一个新数组来存放是否是唯一的
Runtime: 80 ms, faster than 19.11% of C++ online submissions for First Unique
Character in a String. Memory Usage: 17 MB, less than 6.25% of C++ online
submissions for First Unique Character in a String.
 */
class Solution1 {
 public:
  int firstUniqChar(string s) {
    int n = s.length();
    if (!n) return -1;
    map<char, int> hash;
    std::vector<int> uniq(n);
    for (int i = 0; i < n; i++) {
      if (hash.count(s.at(i))) {
        uniq[hash[s.at(i)]] = 0;
        uniq[i] = 0;
      } else {
        hash[s.at(i)] = i;
        uniq[i] = 1;
      }
    }
    for (int i = 0; i < n; i++) {
      if (uniq[i] == 1) return i;
    }
    return -1;
  }

 private:
};
/*
上一个解法忘记了可以本身通过hash数组来存储次数，然后再次遍历一遍来获得第一个唯一的索引
Runtime: 96 ms, faster than 10.25% of C++ online submissions for First Unique
Character in a String. Memory Usage: 13.1 MB, less than 34.38% of C++ online
submissions for First Unique Character in a String.
 */
class Solution2 {
 public:
  int firstUniqChar(string s) {
    int n = s.length();
    if (!n) return -1;
    map<char, int> hash;
    for (int i = 0; i < n; i++) {
      if (hash.count(s.at(i))) {
        hash[s.at(i)]++;
      } else {
        hash[s.at(i)] = 1;
      }
    }
    for (int i = 0; i < n; i++) {
      if (hash[s.at(i)] == 1) return i;
    }
    return -1;
  }

 private:
};
/*
hash
可以直接用桶排序来存储，因为只有26个字母，之前卡壳的地方是，
建立了次数统计后，忘记了再次通过原来字符的遍历顺序去寻找唯一的，
以为要在建立的次数统计表上面去寻找
Runtime: 40 ms, faster than 79.50% of C++ online submissions for First Unique
Character in a String. Memory Usage: 12.9 MB, less than 81.25% of C++ online
submissions for First Unique Character in a String.
 */
class Solution3 {
 public:
  int firstUniqChar(string s) {
    int n = s.length();
    if (!n) return -1;
    std::vector<int> count(26, 0);
    for (char c : s) count[c - 'a']++;
    for (int i = 0; i < n; i++) {
      if (count[s[i]-'a'] == 1) return i;
    }
    return -1;
  }

 private:
};

int main(int argc, char const *argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution3 sol;
  cout << sol.firstUniqChar("leetcode") << endl;
  system("pause");
  return 0;
}