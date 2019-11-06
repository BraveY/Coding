//https://leetcode.com/problems/unique-binary-search-trees/
class Solution {
public:
    int numTrees(int n) {
        if (n==0) return 0;
        if (n==1) return 1;
        vector<int> nums(n+1);
        nums[0]=1;
        nums[1]=1;
        if(n>1){
            for(int i=2;i<=n;i++){
                int S=0;
                for(int j=0;j<i;j++){
                    S +=nums[j]*nums[i-1-j];
                }
                nums[i]=S;
            }
        }
        return nums[n];
    }
};