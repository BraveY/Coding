//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int len = prices.size();
        if(len<1) return 0;
        vector<int> min_price(len);
        vector<int> max_profit(len);
        min_price[0]=prices[0];
        max_profit[0]=0;
        for(int i=1; i<len; i++){
            min_price[i]=min(min_price[i-1],prices[i]);
            max_profit[i]=max(max_profit[i-1],prices[i]-min_price[i]);
        }
        return max_profit[len-1];
    }
};