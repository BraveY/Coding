


#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool compare(vector<int>& a, vector<int>& b) { // 必须为全局函数或者静态函数
      return a[0] < b[0]; //左边有排序就好，右边会进行比较
    }

class Solution {
public:    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), compare);
        vector<int> tmp = intervals[0];
        ans.push_back(tmp);
        for(int i = 1; i < intervals.size(); ++i) {
            tmp = ans.back();
            if (intervals[i][0] <= tmp[1]) {
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);//右边需要比较一下
                
                          
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};

class Solution1 {
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