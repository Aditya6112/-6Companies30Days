// Link: https://leetcode.com/problems/rotate-function/description/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long sum = 0, F = 0;

        // Compute initial F(0) and the sum of elements in nums
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            F += i * nums[i];
        }

        long maxi = F;

        // Calculate F(k) for k = 1 to n-1
        for (int k = 1; k < n; k++) {
            F = F + sum - n * nums[n - k];
            maxi = max(maxi, F);
        }

        return maxi;
    }
};