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
  vector<string> fizzBuzz(int n) {
    std::vector<string> ans;
    for (int i = 1; i <= n; i++) {
      if (i % 3 == 0 && i % 5 != 0)
        ans.push_back("Fizz");
      else if (i % 3 != 0 && i % 5 == 0)
        ans.push_back("Buzz");
      else if (i % 3 == 0 && i % 5 == 0)
        ans.push_back("FizzBuzz");
      else
        ans.push_back(to_string(i));
    }
    return ans;
  }

 private:
};

int main(int argc, char const *argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  cout << sol.fizzBuzz(15)[2] << endl;
  system("pause");
  return 0;
}