/*
 * @Author: your name
 * @Date: 2020-02-14 11:54:43
 * @LastEditTime: 2021-03-10 10:56:47
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode\155min-stack.cc
 */
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
Runtime: 24 ms, faster than 98.56% of C++ online submissions for Min Stack.
Memory Usage: 17 MB, less than 61.82% of C++ online submissions for Min Stack.
每次的最小元素压入另一个辅助栈
 */
class MinStack {
 public:
  /** initialize your data structure here. */
  std::vector<int> stack;
  std::vector<int> min_vec;
  MinStack() {}

  void push(int x) {
    int min_last = 0;
    if (min_vec.size())
      min_last = getMin();
    else
      min_last = x;
    int min_now = min(min_last, x);
    min_vec.push_back(min_now);
    stack.push_back(x);
  }

  void pop() {
    min_vec.pop_back();
    stack.pop_back();
  }

  int top() { return stack[stack.size() - 1]; }

  int getMin() { return min_vec[min_vec.size() - 1]; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char const* argv[]) {
  /* code */
  ios::sync_with_stdio(false);
  // Solution sol;
  // cout << sol.solution() << endl;
  MinStack* obj = new MinStack();
  obj->push(1);
  obj->push(-1);
  obj->push(5);
  obj->push(4);
  obj->pop();
  int param_3 = obj->top();
  int param_4 = obj->getMin();
  cout << "top" << param_3 << "min:" << param_4 << endl;
  system("pause");
  return 0;
}