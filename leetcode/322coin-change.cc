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
  int coinChange(vector<int>& coins, int amount) {
    int ans = 0;
    int len = coins.size();
    vector<vector<int> > opt(len + 1, vector<int>(amount + 1, 0));
    // for (int i = 0; i <= len; i++) {
    //   opt[i][0] = 0;  // amount 为0 的时候，不需要兑换 兑换次数为0
    // }
    for (int i = 0; i <= amount; i++) {
      opt[0][i] = -1;  //不存在硬币可以兑换 返回-1
      int value = coins[0];
      if (i % value != 0) {  //对只有一个硬币的时候进行初始化
        opt[1][i] = -1;      //不能被整除的时候-1
      } else {
        opt[1][i] = i / value;  // 可以被整除的时候返回商作为交换的次数。
      }
    }
    for (int i = 2; i <= len; i++) {
      for (int j = 1; j <= amount; j++) {
        int value = coins[i - 1];
        // if (j == 3)
        // cout << "opt i-1 j :" << opt[i - 1][j]
        //      << "opt i j-3 :" << opt[i][j - 3] << endl;
        if (j >= value) {
          if ((opt[i - 1][j] > 0) && (opt[i][j - value] >= 0)) {
            opt[i][j] =
                min(opt[i - 1][j], 1 + opt[i][j - value]);  //有个-1的解决
            // if (j == 3) cout << "opt 2 3 first :" << opt[i][j] << endl;
          } else if ((opt[i - 1][j] < 0) && (opt[i][j - value] >= 0)) {
            opt[i][j] = 1 + opt[i][j - value];
            // if (j == 3) cout << "opt 2 3 :" << opt[i][j] << endl;
          }
          // else if ((opt[i - 1][j] < 0) && (opt[i][j - value] < 0))
          //   opt[i][j] = -1;
          else
            opt[i][j] = opt[i - 1][j];
        } else {
          opt[i][j] = opt[i - 1][j];
          // if (j == 3) cout << "opt 2 3 third:" << opt[i][j] << endl;
        }
        // cout << "i,j: " << i << "," << j << ":" << opt[i][j] << endl;
      }
    }
    // cout << "opt2,0" << opt[2][0] << endl;
    ans = opt[len][amount];
    return ans;
  }

 private:
};

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  Solution sol;
  std::vector<int> v = {5, 3, 2};
  int amount = 11;
  cout << sol.coinChange(v, amount) << endl;
  system("pause");
  return 0;
}