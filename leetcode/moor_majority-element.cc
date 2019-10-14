#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums.front();
        int count = 0;
        
        for (const int num : nums) {
            if (num == majority) ++count;
            else if (--count == 0) {
                count = 1;
                majority = num;
            }
        }
        
        return majority;
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
    // cin>>len;
    // vector<int> vec(len);
    // for(int i = 0; i < len; i++) {
    //     cin>>vec[i];
    // }
    // ans = Sol.majorityElement(vec);
    // cout<<ans<<endl;
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