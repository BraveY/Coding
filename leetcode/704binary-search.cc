/*
 * @Author: your name
 * @Date: 2021-04-25 20:31:05
 * @LastEditTime: 2021-04-25 20:43:13
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode\704binary-search.cc
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

class Solution {
  private:
  public:
    int search(vector<int>& nums, int target) {        
        // return  bsRecursion(nums, target, 0 , nums.size() - 1);
        return bsIter(nums, target);
    }
/*
Runtime: 36 ms, faster than 56.64% of C++ online submissions for Binary Search.
Memory Usage: 27.5 MB, less than 89.50% of C++ online submissions for Binary Search.
*/    
    int bsRecursion(vector<int>& nums, int target, int l, int r){
        if (l > r) return -1;
        int rtn = 0;
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) {
            rtn = bsRecursion(nums, target, mid + 1, r);
        }else {
            rtn = bsRecursion(nums, target, l, mid - 1);
        }
        return rtn;
    }
/*
Runtime: 24 ms, faster than 98.49% of C++ online submissions for Binary Search.
Memory Usage: 27.5 MB, less than 52.43% of C++ online submissions for Binary Search.
*/    
    int bsIter(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            else if ( nums[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
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