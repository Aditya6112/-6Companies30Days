// Link: https://leetcode.com/problems/maximum-product-after-k-increments/
#define MOD 1000000007
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>minH;
        for(auto num:nums){
            minH.push(num);
        }
        while(k--){
            int top=minH.top();
            minH.pop();
            minH.push(top+1);
        }
        long long product=1;
        while(!minH.empty()){
            int top=minH.top();
            minH.pop();
            product=(product*top)%MOD;
        }
        return product;
    }
};