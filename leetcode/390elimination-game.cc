/*
 * @Author: your name
 * @Date: 2021-03-27 17:09:35
 * @LastEditTime: 2021-03-28 16:40:26
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode\390elimination-game.cc
 */
#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
#include <stack>
#include <queue>

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
/*
TLE 
O(N)
*/
class Solution1 {
  public:
    int lastRemaining(int n) {
        stack<int> s1;
        stack<int> s2;
        for (int i = n; i >= 1; --i) {
            s1.push(i);
        }
        while(s1.size() != 1) {
            int record = 0;
            while (s1.size() != 0)
            {
                if (record) {
                    s2.push(s1.top());
                }
                s1.pop();
                record = !record;
            }
            swap(s1, s2);
        }
        return s1.top();
    }

  private:
};

/*
https://leetcode.com/problems/elimination-game/discuss/355060/C%2B%2B-simple-explanation-with-pictures
从左移动：头一定移动
从右移动：当剩余得个数是奇数得时候才会移动。
Runtime: 8 ms, faster than 25.51% of C++ online submissions for Elimination Game.
Memory Usage: 5.9 MB, less than 17.89% of C++ online submissions for Elimination Game.
*/
class Solution {
  public:
    int lastRemaining(int n) {
        int head = 1;
        int step = 1;
        int startLeft = 1;
        while (n > 1)
        {
            if (startLeft) {
                head += step;
            }else {
                head += n % 2== 0 ? 0 : step;//剩余为偶数不移动
            }
            step *= 2;
            n /= 2;
            startLeft = !startLeft;
        }
        return head;        
    }

  private:
};


void debug() {
	Solution sol;

    int n = 9;
    cout << sol.lastRemaining(n) << endl;
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}