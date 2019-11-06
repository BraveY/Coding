/*https://leetcode.com/problems/house-robber/*/
#include<iostream>
#include<vector>
#include<map>
#include <stdio.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
    	int len = nums.size();
        if(len<1) return 0; //leetcode 上面必须要有空指针的返回，否则报RuntimeERROR
        if(len==1) return nums[0]; //必须有这一句
        vector<int> opt(len);
        opt[0] = nums[0];
        opt[1] = max(nums[0],nums[1]); //必须要有上面对n=1的直接返回，否则当n=1的时候数组越界
        if(len>2){
        	for(int i=2; i<len; i++){
        		opt[i]=max(opt[i-2]+nums[i],opt[i-1]);
        	}
        }
        return opt[len-1];
    }
};

int main(int argc, char const *argv[])
{
	/* code */
    Solution Sol;
    int len;
    int ans;
    while(cin>>len){
        vector<int> vec(len);
        for(int i = 0; i < len; i++) {
            cin>>vec[i];
        }
        ans = Sol.rob(vec);
        cout<<ans<<endl;
    }
	return 0;
}