// Link: https://leetcode.com/problems/word-break/
class Solution {
public:
    unordered_set<string> wordDict;
    bool solve(int idx, string s,string str,vector<int>& dp) {
        if (idx >= s.size())
            return true;
        if (wordDict.find(s) != wordDict.end())
            return true;
        if(dp[idx]!=-1)return dp[idx];
        for (int i = 1; i <= s.size(); i++) {
            str = s.substr(idx, i);
            if (wordDict.find(str) != wordDict.end() && solve(idx + i, s,str,dp))
                return dp[idx]=true;
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& Dict) {
        string str = "";
        for (auto d : Dict) {
            wordDict.insert(d);
        }
        vector<int>dp(s.size()+1,-1);
        return solve(0, s,str,dp);
    }
};