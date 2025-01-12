// Link: https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>maxH;
        for(int i=0;i<nums.size();i++){
            maxH.push({nums[i],i});
        }
        int cnt=0;
        vector<pair<int,int>>top_k;
        while(cnt!=k){
            top_k.push_back({maxH.top().second,maxH.top().first});
            cnt++;
            maxH.pop();
        }
        sort(top_k.begin(),top_k.end());
        vector<int>res;
        for(int i=0;i<k;i++){
            res.push_back(top_k[i].second);
        }
        return res;
    }
};