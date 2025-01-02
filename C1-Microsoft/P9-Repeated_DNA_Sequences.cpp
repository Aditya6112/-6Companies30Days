// Link: https://leetcode.com/problems/repeated-dna-sequences/description/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        if(n<10)return {};
        unordered_map<string,int>mpp;
        int i=0;
        while(i+9<n){
            string temp=s.substr(i,10);
            mpp[temp]++;
            i++;
        }
        vector<string>ans;
        for(auto it:mpp){
            if(it.second>=2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};