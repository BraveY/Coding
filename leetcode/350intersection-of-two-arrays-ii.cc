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
Runtime: 8 ms, faster than 76.21% of C++ online submissions for Intersection of
Two Arrays II. Memory Usage: 9.4 MB, less than 53.57% of C++ online submissions
for Intersection of Two Arrays II.
 */
class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    std::vector<int> ans;
    std::map<int, int> map;
    for (int i = 0; i < m; i++) {
      if (map.count(nums1[i]))
        map[nums1[i]]++;
      else
        map[nums1[i]] = 1;
    }
    for (int i = 0; i < n; i++) {
      if (map.count(nums2[i]) && map[nums2[i]] > 0) {
        ans.push_back(nums2[i]);
        map[nums2[i]]--;
      }
    }
    return ans;
  }

 private:
};

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  std::vector<int> v1({1, 2, 3});
  std::vector<int> v2({2, 3});
  cout << sol.intersect(v1, v2).size() << endl;
  system("pause");
  return 0;
}