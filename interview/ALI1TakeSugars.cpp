/*
 * @Author: your name
 * @Date: 2021-04-19 19:05:35
 * @LastEditTime: 2021-04-19 19:48:55
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\interview\ALI1TakeSugars.cpp
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

int soulution(vector<int>& nums, int k) {
    int len = nums.size();
    if (!len) return -1;
    if (k >= len) return 1;
    int l = 0;
    int r = 0;
    int ans = 0;
    int sum = 0;
    int rtn = 0;
    while(r - l < k - 1) {        
        sum += nums[r];
        ++r;
    }    
    while (l < len)
    {
        /* code */
        if (l <= len - k) {
            sum += nums[r];
        }else {
            sum += nums[r - len];
            // cout << " r " << r << " r-len " << r - len << endl;
        }
        if (sum >= ans) {
            if (sum > ans) {
                rtn = l;
                ans = sum;
            }else rtn = min(rtn, l);
        }        
        sum -= nums[l];
        l++;
        r++;        

    }
    return rtn + 1;
}


int main(int argc, char const *argv[]) {
	/* code */
	ios::sync_with_stdio(false);
    int n , k;
    cin >> n >> k;
    vector<int> nums;
    int tmp;
    while(n--){
        cin >> tmp;
        nums.push_back(tmp);
    }
    cout << soulution(nums, k) << endl;
	return 0;
}