/*
 * @Author: your name
 * @Date: 2021-04-25 21:07:53
 * @LastEditTime: 2021-04-25 21:33:51
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode\470implement-rand10-using-rand7.cc
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

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}
class Solution {
  private:
  public:
    int rand10() {
        int num = (rand7() - 1)*7 + rand7();
        while(num > 40) {
            num = (rand7() - 1)*7 + rand7();
        }
        return 1 + num % 10;
    }
};


void debug() {
	Solution sol;
	return;
}

int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
	debug();
	system("pause");
	return 0;
}