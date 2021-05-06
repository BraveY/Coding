#include <limits.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
#include <numeric>
/*
https://leetcode.com/problems/two-sum/
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 使用unordered_map 来作为哈希表 用来存储每一个值的索引，使用哈希表可以将查找的复杂度降到O(1)
        unordered_map<int, int> indies; 
        for(int i=0; i<nums.size(); i++){
            indies[nums[i]] = i;
        }
        for(int i=0; i<nums.size(); i++){ // 注意重复值的情况，即6-3=3，而实际上只有一个3，因此需要判断是否相等
            int left = target - nums[i];
            //使用count()方法来查询哈希表中是否有某一个元素。
            //可以直接return{i, j}来返回一个vector。
            if(indies.count(left) && indies[left] != i) return{i, indies[left]}; //在第一个寻找答案的时候就返回，避免后面3，3这样子被覆盖掉，因为只记录了最后出现的值。
        }
        return {};
    }
};