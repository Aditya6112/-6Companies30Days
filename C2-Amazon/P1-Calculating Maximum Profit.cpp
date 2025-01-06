// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
class Solution {
public:
    int solve(vector<int>& prices,int idx,int buy,int limit,vector<vector<vector<int>>>& dp){
        if(idx>=prices.size())return 0;
        if(limit==0)return 0;
        if(dp[idx][limit][buy]!=-1)return dp[idx][limit][buy]; 
        int profit=0;
        if(buy==1){//we can buy or skip
            int buykaro=((-1*prices[idx]))+solve(prices,idx+1,0,limit,dp);
            int skipkaro=solve(prices,idx+1,1,limit,dp);
            profit+=max(buykaro,skipkaro);
        }else{//we can sell or skip
            int sellkaro=prices[idx]+solve(prices,idx+1,1,limit-1,dp);
            int skipkaro=solve(prices,idx+1,0,limit,dp);
            profit+=max(sellkaro,skipkaro);
        }
        return dp[idx][limit][buy]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        //buy is 1 that we can buy or skip if buy is 0 then we can sell or skip
        //we have to buy before sell
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return solve(prices,0,1,k,dp);
    }
};