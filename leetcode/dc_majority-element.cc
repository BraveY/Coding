#include<iostream>
#include<vector>
#include<map>
#include <stdio.h>

using namespace std;
class Solution {
private:
    int dc_majority(std::vector<int>&vec, int lo, int hi){
        if(lo>=hi) return vec[lo];
        int mid = lo + (hi-lo)/2;
        int l_ans = dc_majority(vec, lo, mid);
        int r_ans = dc_majority(vec, mid+1, hi);
        if(l_ans==r_ans) return l_ans;
        int l_ans_nums=0, r_ans_nums = 0;
        for(int i=lo; i<=hi; i++){
            if(vec[i]==l_ans) l_ans_nums++;
            if(vec[i]==r_ans) r_ans_nums++;
        }
        return l_ans_nums>r_ans_nums ? l_ans : r_ans;
    }
public:
    int majorityElement(vector<int>& nums) {
        int major=dc_majority(nums, 0, nums.size()-1);
        return major;
    }
};

int main(int argc, char const *argv[])
{
    // Solution sol;
    // std::vector<int> vec={3,2,3};
    // int ans = sol.majorityElement(vec);
    // cout<<ans<<endl;
    // cin>>ans;
    ios::sync_with_stdio(false);
    int len;
    Solution Sol;
    int ans;
    while(cin>>len){
        vector<int> vec(len);
        for(int i = 0; i < len; i++) {
            cin>>vec[i];
        }
        ans = Sol.majorityElement(vec);
        cout<<ans<<endl;
    }
    return 0;
}