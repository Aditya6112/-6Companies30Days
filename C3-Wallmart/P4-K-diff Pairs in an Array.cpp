// Link: https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int cnt=0;
        set<pair<int,int>>mpp;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(abs(nums[i]-nums[j])==k && !mpp.count({nums[i],nums[j]}) && !mpp.count({nums[j],nums[i]})){
                    mpp.insert({nums[i],nums[j]});
                    mpp.insert({nums[j],nums[i]});
                    cnt++;
                }
            }
        }
        return cnt;
    }
};