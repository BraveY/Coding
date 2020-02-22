#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class WrongSolution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    vector<vector<int>> ans;
    if (n) ans = merge_helper(0, n - 1, intervals);
    return ans;
  }

 private:
  vector<vector<int>> merge_helper(int lo, int hi,
                                   vector<vector<int>>& intervals) {
    vector<vector<int>> rtn;
    if (lo >= hi) {
      rtn.push_back(intervals[lo]);
      return rtn;
    }
    int mid = lo + (hi - lo) / 2;
    vector<vector<int>> left = merge_helper(lo, mid, intervals);
    vector<vector<int>> right = merge_helper(mid + 1, hi, intervals);
    int left_size = left.size();
    int right_size = right.size();
    for (int i = 0; i < left_size + right_size; i++) {
      if (i < left_size - 1) {
        rtn.push_back(left[i]);
      } else if (i == left_size - 1) {
        if (left[i][1] >= right[0][0] && left[i][0] <= right[0][1]) {
          std::vector<int> gap;
          gap.push_back(min(left[i][0], right[0][0]));
          gap.push_back(max(left[i][1], right[0][1]));
          rtn.push_back(gap);
          i++;
        } else {
          rtn.push_back(left[i]);
        }
      } else {
        rtn.push_back(right[i - left_size]);
      }
    }
    return rtn;
  }
};

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
    vector<vector<int>> ans;
    for (const auto& interval : intervals) {
      if (ans.empty() || interval[0] > ans.back()[1]) {
        ans.push_back(interval);
      } else {
        ans.back()[1] = max(ans.back()[1], interval[1]);
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  // cout << sol.solution() << endl;
  system("pause");
  return 0;
}