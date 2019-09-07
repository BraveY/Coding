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
        for(int i=0; i<nums.size(); i++){
            int left = target - nums[i];
            //使用count()方法来查询哈希表中是否有某一个元素。
            //可以直接return{i, j}来返回一个vector。
            if(indies.count(left) && indies[left] != i) return{i, indies[left]};
        }
        return {};
    }
};