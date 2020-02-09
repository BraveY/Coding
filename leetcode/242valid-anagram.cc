#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    std::vector<int> hash(26, 0);
    for (int i = 0; i < s.length(); i++) {
      hash[s.at(i) - 'a']++;
      hash[t.at(i) - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
      if (hash[i]) return false;
    }
    return true;
  }

 private:
};

int main(int argc, char const *argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  cout << sol.isAnagram("asdf", "fdsa") << endl;
  system("pause");
  return 0;
}