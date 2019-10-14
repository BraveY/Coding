#include<iostream>
#include<vector>
#include<map>
#include <stdio.h>

using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        int major = 0;
        int max = 0;
        for(map<int, int>::iterator it= m.begin(); it!=m.end(); it++){
            if(it->second>=max){
                max = it->second;
                major = it->first;
            }
        }
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