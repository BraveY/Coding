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
Runtime: 4 ms, faster than 63.37% of C++ online submissions for Pascal's
Triangle. Memory Usage: 7.8 MB, less than 100.00% of C++ online submissions for
Pascal's Triangle.
 */
class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows);
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j <= i; j++) {
        if (j == 0 || j == i)
          ans[i].push_back(1);
        else
          ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
      }
    }
    return ans;
  }

 private:
};

int main(int argc, char const *argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  cout << sol.generate(5).size() << endl;
  system("pause");
  return 0;
}