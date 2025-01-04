// Link: https://leetcode.com/problems/wiggle-sort-ii/description/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dummy(n);
        int i=1;
        int j=n-1;
        while(j>=0){
            while(i<n){
                dummy[i]=nums[j];
                j--;
                i+=2;
            }
            if(j>=0){
                i=0;
            }
        }
        nums=dummy;
    }
};