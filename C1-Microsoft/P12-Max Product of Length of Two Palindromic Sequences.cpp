// Link: https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/
class Solution {
public:
    // Helper function to check if a subsequence (represented by bitmask) is a palindrome
    bool isPalindrome(const string& s, int mask) {
        string sub = "";
        for (int i = 0; i < s.size(); i++) {
            if (mask & (1 << i)) {
                sub += s[i];
            }
        }
        int l = 0, r = sub.size() - 1;
        while (l < r) {
            if (sub[l++] != sub[r--]) {
                return false;
            }
        }
        return true;
    }

    int maxProduct(string s) {
        int n = s.size();
        unordered_map<int, int> maxLen; // Map to store the maximum length of palindromes for each bitmask

        // Precompute all palindromic subsequences and their lengths
        for (int mask = 1; mask < (1 << n); mask++) {
            if (isPalindrome(s, mask)) {
                maxLen[mask] = __builtin_popcount(mask); // Store the length of the palindrome
            }
        }

        int maxProduct = 0;

        // Iterate through all pairs of bitmasks
        for (int mask1 = 1; mask1 < (1 << n); mask1++) {
            for (int mask2 = mask1 + 1; mask2 < (1 << n); mask2++) {
                // Ensure the two subsequences are disjoint
                if ((mask1 & mask2) == 0) {
                    maxProduct = max(maxProduct, maxLen[mask1] * maxLen[mask2]);
                }
            }
        }

        return maxProduct;
    }
};
