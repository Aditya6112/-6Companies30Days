// Link: https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> res;
        
        for (auto& q : queries) {
            int k = q[0], trim = q[1];
            vector<pair<string, int>> trimmedNums;
            
            for (int i = 0; i < n; ++i) {
                string trimmed = nums[i].substr(nums[i].size() - trim); // Extract last 'trim' characters
                trimmedNums.emplace_back(trimmed, i);
            }
            
            // Use stable_sort to maintain original indices order
            nth_element(trimmedNums.begin(), trimmedNums.begin() + k - 1, trimmedNums.end());
            
            res.push_back(trimmedNums[k - 1].second);
        }
        return res;
    }
};
