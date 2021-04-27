/*
 * @Author: your name
 * @Date: 2019-11-22 15:17:00
 * @LastEditTime: 2021-04-27 23:28:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Coding\leetcode\153find-minimum-in-rotated-sorted-array.cc
 */
/*leetcode#153
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<utility>
#include <string>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if(len==1 || nums[0]<nums[len-1]) return nums[0];
        // return dc_find(nums, 0, len-1);
        return loop_find(nums, 0, len-1);
    }
private:
	int dc_find(vector<int>& nums, int lo, int hi){
		if((hi -lo)==1) return nums[hi];
		int ans = 0;
		int mid = lo + (hi -lo)/2;
		if(nums[mid]>nums[lo]) ans = dc_find(nums, mid, hi);
		else ans = dc_find(nums, lo, mid);
		return ans;
	}
	int loop_find(vector<int>& nums, int lo, int hi){
		int mid = 0;
		while(lo<hi){
			mid = lo + (hi -lo)/2;
			if(nums[mid]>nums[hi]) lo = mid + 1;
			else hi = mid ;
		}
		return nums[lo];
};


int main(int argc, char const *argv[])
{
	/* code */
	ios::sync_with_stdio(false);
	std::vector<int> vec = {1,3,5,7};
	Solution Sol;
	cout<<Sol.findMin(vec)<<endl;
	system("pause");
	return 0;
}