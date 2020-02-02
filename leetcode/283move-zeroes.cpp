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
  void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int not_zero = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] != 0) {
        not_zero++;
        nums[not_zero - 1] = nums[i];
      }
    }
    for (int i = not_zero; i < n; i++) {
      nums[i] = 0;
    }
  }

 private:
};
/*
Optimal O(n)
 */
// 记录上一个非零元素的位置（上一个的是已经被零填充了的）
class Solution2 {
 public:
  void moveZeroes(vector<int>& nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
      if (nums[cur] != 0) {
        swap(nums[lastNonZeroFoundAt++], nums[cur]);
      }
    }
  }

 private:
};

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  vector<int> vec({0, 1, 0, 3, 12});
  Solution sol;
  sol.moveZeroes(vec);
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  system("pause");
  return 0;
}