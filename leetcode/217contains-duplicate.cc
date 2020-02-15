#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

/*
O(N^2)TLE
 */
class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (nums[j] == nums[i]) return true;
      }
    }
    return false;
  }

 private:
};

class Solution2 {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> hash;
    int n = nums.size();
    if (n == 0 || n == 1) return false;
    for (int i = 0; i < n; i++) {
      if (hash.count(nums[i])) return true;
      hash[nums[i]] = i;
    }
    return false;
  }

 private:
};

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution2 sol;
  vector<int> vec = {1, 2, 3, 1};
  cout << sol.containsDuplicate(vec) << endl;
  system("pause");
  return 0;
}