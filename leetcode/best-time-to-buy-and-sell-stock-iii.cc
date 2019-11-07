// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/

/*O(n²)的时间复杂度最后一个样例会TLE
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int len = prices.size();
        if(len<1) return 0;
        if(len<4) return oneProfit(prices,0,len-1);
        int max_profit =oneProfit(prices,0,len-1);
        for(int k=1;k<=len-2;k++){
            max_profit=max(oneProfit(prices,0,k)+oneProfit(prices,k+1,len-1),max_profit);
        }
        return max_profit;
    }
    int oneProfit(vector<int>& prices,int p, int q){
        const int n =prices.size();
        if(n<1) return 0;
        const int len = q-p+1;
        vector<int> min_price(len);
        vector<int> max_profit(len);
        min_price[0]=prices[p];
        max_profit[0]=0;
        for(int i=1; i<len; i++){
            min_price[i]=min(min_price[i-1],prices[i+p]);
            max_profit[i]=max(max_profit[i-1],prices[i+p]-min_price[i]);
        }
        return max_profit[len-1];
    }
};
*/
//O(n)的解决方法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int len = prices.size();
        if(len<1) return 0;
        int min_price=prices[0];
        int max_price=prices[len-1];
        vector<int> left_profit(len);
        vector<int> right_profit(len);
        left_profit[0]=0;
        right_profit[len-1]=0;
        for(int i=1;i<len;i++){
        	min_price = min(min_price, prices[i]);
        	left_profit[i] = max(left_profit[i-1],prices[i]-min_price);
        }
        for(int i=len-2;i>=0;i--){
        	max_price = max(max_price,prices[i]);
        	right_profit[i] = max(right_profit[i+1], max_price-prices[i]);
        }
        int final_max_profit=0;
        for(int i=1;i<len;i++){
        	final_max_profit = max(final_max_profit,left_profit[i]+right_profit[i]);
        }
        return final_max_profit;
    }
};