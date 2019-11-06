//https://leetcode.com/problems/house-robber-ii/
class Solution {
public:
    int rob(vector<int>& nums) {
    	int len = nums.size();
        if(len<1) return 0; //leetcode 上面必须要有空指针的返回，否则报RuntimeERROR
        if(len==1) return nums[0]; //必须有这一句
        if(len==2) return max(nums[0],nums[1]);//必须有这一句，不然下面的blen可能为复数
        int alen = len - 1 ;
        int blen = len - 3; 
        vector<int> A(alen);
        for(int i =0; i<alen;i++){
            A[i]=nums[i];
        }
        vector<int> B(blen);
        for(int i =0; i<blen;i++){
            B[i]=nums[i+1];
        }
        int max1=original_rob(A);
        int max2=original_rob(B)+nums[len-1];//别忘记了加上选择最后一个抢劫得到的钱。
        return max(max1,max2);
    }
    int original_rob(vector<int>& nums) {
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