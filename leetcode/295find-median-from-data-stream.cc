/*
 * @Author: your name
 * @Date: 2021-03-28 20:33:00
 * @LastEditTime: 2021-03-28 21:08:09
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode\295find-median-from-data-stream.cc
 */
#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

void cout_vector(vector<int>& nums) {
	for (auto i : nums) {
		cout << i << ' ';
	}
	cout << endl;
}

/*
Runtime: 92 ms, faster than 95.16% of C++ online submissions for Find Median from Data Stream.
Memory Usage: 46.8 MB, less than 33.04% of C++ online submissions for Find Median from Data Stream.
*/
class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> leftHeap;//左边用最大堆
    priority_queue<int, vector<int>, greater<int>> rightHeap;//右边用最小堆
    int TotalNums; //record the total nums of left and right heap
public:
    /** initialize your data structure here. */
    MedianFinder() {
        leftHeap = {};
        rightHeap = {};
        TotalNums = 0;
    }
    
    void addNum(int num) {
        if (TotalNums % 2 == 0) {
            if (!rightHeap.empty() && rightHeap.top() < num) { // 左边插入一个比右边大得处理
                rightHeap.push(num);
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
            }else {
                leftHeap.push(num);
            }            
        } else {
            if (leftHeap.top() > num) { // 右边插入一个比左边小得处理
                leftHeap.push(num);
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
            }else{
                rightHeap.push(num);
            }
        }
        TotalNums++;
    }
    
    double findMedian() {
        double median;
        if (TotalNums % 2 == 0) {
            median = ((double) leftHeap.top() + rightHeap.top()) / 2;
        } else {
            median = leftHeap.top();
        }
        return median;
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