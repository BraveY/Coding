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
Runtime: 76 ms, faster than 50.77% of C++ online submissions for Search a 2D
Matrix II. Memory Usage: 12 MB, less than 100.00% of C++ online submissions for
Search a 2D Matrix II.
 */
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (!m) return false;
    int n = matrix[0].size();
    if (!n) return false;
    return helper(matrix, target, 0, n - 1);
  }

 private:
  bool helper(vector<vector<int>>& matrix, int target, int row, int col) {
    if (row >= matrix.size() || col < 0) return false;
    if (matrix[row][col] == target) return true;
    if (row == matrix.size() - 1 && col == 0) {
      if (matrix[0][0] == target)
        return true;
      else
        return false;
    }
    if (matrix[row][col] > target)
      col--;
    else
      row++;
    return helper(matrix, target, row, col);
  }
};

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  std::vector<vector<int>> matrix(5, vector<int>(5));
  int data[5][5] = {{1, 4, 7, 11, 15},
                    {2, 5, 8, 12, 19},
                    {3, 6, 9, 16, 22},
                    {10, 13, 14, 17, 24},
                    {18, 21, 23, 26, 30}};
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      matrix[i][j] = data[i][j];
    }
  }
  cout << sol.searchMatrix(matrix, 20) << endl;
  system("pause");
  return 0;
}