// Link: https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/
class Solution {
public:
    bool isIncreasing(vector<int>& nums){
        if(nums.size()==0)return true;
        if(nums.size()==1)return true;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>=nums[i+1]){
                return false;
            }
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                vector<int>temp;
                for(int k=0;k<n;k++){
                    if(k>=i && k<=j){
                        continue;
                    }else{
                        temp.push_back(nums[k]);
                    }
                }
                if(isIncreasing(temp)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};