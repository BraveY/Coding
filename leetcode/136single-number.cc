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
  int singleNumber(vector<int>& nums) {
    int n = nums.size();
    int single = 0;
    for (int i = 0; i < n; i++) {
      single ^= nums[i];
    }
    return single;
  }

 private:
};

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  cout << sol.singleNumber() << endl;
  system("pause");
  return 0;
}