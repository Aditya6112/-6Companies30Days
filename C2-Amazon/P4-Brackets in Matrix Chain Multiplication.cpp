// Link: https://www.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1

class Solution {
  public:
    pair<string,int> solve(vector<int>& arr,int i,int j,vector<vector<pair<string,int>>>& dp){
        if(i==j){
            string st="";
            st+='A'+i-1;
            return {st,0};
        }
        if(dp[i][j].second!=-1)return dp[i][j];
        int mini=INT_MAX;
        string sr="";
        for(int k=i;k<j;k++){
            auto pr1=solve(arr,i,k,dp);
            auto pr2=solve(arr,k+1,j,dp);
            int x=pr1.second+pr2.second+arr[i-1]*arr[k]*arr[j];
            string s="";
            s="("+pr1.first+pr2.first+")";
            if(mini>x){
                mini=x;
                sr=s;
            }
        }
        dp[i][j]={sr,mini};
        return dp[i][j];
    }
    string matrixChainOrder(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<pair<string,int>>>dp(n,vector<pair<string,int>>(n,{"",-1}));
        auto ans=solve(arr,1,n-1,dp);
        return ans.first;
    }
};