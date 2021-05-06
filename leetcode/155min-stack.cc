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
每次的最小元素压入另一个辅助栈,空间换时间
 */
class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> data;
    vector<int> minVec;
    MinStack() {

    }
    
    void push(int val) {
        if (data.empty()) {
            data.push_back(val);
            minVec.push_back(val);
        }else{
            int minLast = getMin();
            int minNow = min(minLast, val);
            data.push_back(val);
            minVec.push_back(minNow);
        }
    }
    
    void pop() {
        data.pop_back();
        minVec.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return minVec.back();
    }
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