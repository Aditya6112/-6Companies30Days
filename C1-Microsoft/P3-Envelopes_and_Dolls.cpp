// Link: https://leetcode.com/problems/russian-doll-envelopes/description/
class Solution {
public:
    static bool cmp(vector<int>& A,vector<int>& B){
        if(A[0]==B[0])return A[1]>B[1];
        return A[0]<B[0];
    }
    //Gives MLE from this
    int solveLIS(vector<int>heights,int n,int curr,int prev,vector<vector<int>>& dp){
        if(curr==n)return 0;
        if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
        int include=0;
        if(prev==-1 || heights[curr]>heights[prev]){
            include=1+solveLIS(heights,n,curr+1,curr,dp);
        }
        int exclude=solveLIS(heights,n,curr+1,prev,dp);
        return dp[curr][prev+1]=max(include,exclude);
    }
    
    //Binary search Accepted
    int solveOptimal(vector<int>& nums,int n){
        if(n==0){
            return 0;
        }
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }else{
                //just greater idx than nums[i]
                int idx=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[idx]=nums[i];
            }
        }
        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int>heights;
        for(auto env:envelopes){
            heights.push_back(env[1]);
        }
        return solveOptimal(heights,heights.size());
    }
};