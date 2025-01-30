// Link: https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int i=0,j=0,ans=0;
        while(j<nums.size()){
            mp[nums[j]]++;
            if(mp[nums[j]]<=k){
                ans=max(ans,j-i+1);
                j++;
            }else if(mp[nums[j]]>k){
                while(mp[nums[j]]>k){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0){
                        mp.erase(mp[nums[i]]);
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};