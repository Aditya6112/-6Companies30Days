// Link: https://leetcode.com/problems/count-number-of-nice-subarrays/description/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        //convert the array in 0,1 0 for even and 1 for odd
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                nums[i]=1;
            }else{
                nums[i]=0;
            }
        }

        unordered_map<int,int>mpp;
        mpp[0]=1;
        int len=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum-k;
            if(mpp.find(rem)!=mpp.end()){
                len+=mpp[rem];
            }        
            mpp[sum]++;
        }
        return len;
    }
};