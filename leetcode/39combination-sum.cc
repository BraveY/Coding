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
Runtime: 4 ms, faster than 98.97% of C++ online submissions for Combination Sum.
Memory Usage: 11.1 MB, less than 53.21% of C++ online submissions for Combination Sum.
 */
class Solution {
  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target, 0, 0);
        return ans;
    }

  private:
    vector<vector<int>> ans;
    vector<int> path;
    void backtrack(vector<int>& candidates, int target, int sum, int index) {
        for (int i = index; i < candidates.size(); i++) {
            if (sum + candidates[i] > target) continue;
            path.push_back(candidates[i]);
            sum += candidates[i];
            if (sum == target) {
                ans.push_back(path);
            } else {
                backtrack(candidates, target, sum, i);
            }
            path.pop_back();
            sum -= candidates[i];
        }
    }
};

void cout_vector(vector<int>& nums) {
    for (auto i : nums) {
        cout << i << ' ';
    }
    cout << endl;
}

void debug() {
    Solution sol;

    //一维数组的输入
    vector<int> nums1 = {2, 3, 6, 7};
    // vector<int> nums2;
    // int i;
    // while (cin >> i) {
    //  nums2.push_back(i);
    // }
    vector < vector<int >> ans;
    ans = sol.combinationSum(nums1, 7);

    //二维数组的输入
    //int m, n;
    // while (cin >> m >> n) {
    //  vector<vector<int>> grid(m, vector<int>(n));
    //  for (int i = 0; i < m; i++) {
    //      for (int j = 0; j < n; j++ ) {
    //          cin >> grid[i][j];
    //      }
    //  }
    //  int ans = sol.solution(grid);
    //  cout << ans << endl;
    // }
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

int main(int argc, char const *argv[]) {
    /* code */
    ios::sync_with_stdio(false);
    debug();
    system("pause");
    return 0;
}