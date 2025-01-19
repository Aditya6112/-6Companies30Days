// Link: https://leetcode.com/problems/repeated-dna-sequences/description/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        if(n<10)return {};
        unordered_map<string,int>mp;
        vector<string>result;
        int j=0;
        string str="";
        while(j<n){
            str+=s[j];
            if(str.size()==10){
                mp[str]++;
                if(mp[str]==2)result.push_back(str);
                str.erase(0,1);
            }
            j++;
        }
        return result;
    }
};