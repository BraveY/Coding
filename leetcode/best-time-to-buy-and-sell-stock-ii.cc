/*
leetcode#122 https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/
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
    int maxProfit(vector<int>& prices) {
    	int len = prices.size();
    	if(len<=0) return 0 ;
        int buy = prices[0];
        int profit = 0;
        for(int i=0; i<len; i++){
        	if(buy < prices[i]){
        		profit += prices[i] - buy;
        	}
        	buy = prices[i];
        }
        return profit;
    }
private:
};

int main(int argc, char const *argv[])
{
	/* code */
	ios::sync_with_stdio(false);
	Solution sol;
	vector<int> prices;
	int i;
	while(cin>>i){
		prices.push_back(i);
	}
	cout<<sol.maxProfit(prices)<<endl;
	system("pause");	
	return 0;
}