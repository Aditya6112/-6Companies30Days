// Link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/

//Time Limit Exceed Solution
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n-k+1;i++){
            set<int>subarr;
            long long curr_sum=0;
            for(int j=i;j<i+k;j++){
                curr_sum+=nums[j];
                subarr.insert(nums[j]);
            }
            if(subarr.size()<k){
                continue;
            }else{
                sum=max(sum,curr_sum);
            }
        }
        return sum;
    }
};

//Accepted Solution
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        long long window_sum=0;
        set<int>st;
        int i=0;
        int j=0;
        while(j<n){
            while(st.count(nums[j])){
                window_sum-=nums[i];
                st.erase(nums[i]);
                i++;
            }
            window_sum+=nums[j];
            st.insert(nums[j]);
            if(j-i+1==k){//max window length case we have shrink now
                sum=max(sum,window_sum);
                window_sum-=nums[i];
                st.erase(nums[i]);
                i++;
            }
            j++;
        }
        return sum;
    }
};
