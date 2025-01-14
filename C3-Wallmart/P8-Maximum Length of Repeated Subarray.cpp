// Link: https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/
class Solution {
public:
    int helper(vector<int>& nums1, vector<int>& nums2, int i, int j, vector<vector<int>>& memo) {
        if (i >= nums1.size() || j >= nums2.size()) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        if (nums1[i] == nums2[j]) {
            memo[i][j] = 1 + helper(nums1, nums2, i + 1, j + 1, memo);
        } else {
            memo[i][j] = 0;
        }
        return memo[i][j];
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        int maxLength = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                maxLength = max(maxLength, helper(nums1, nums2, i, j, memo));
            }
        }

        return maxLength;
    }
};
