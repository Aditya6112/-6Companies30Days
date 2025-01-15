// Link: https://leetcode.com/problems/sort-characters-by-frequency/
class Solution {
public:
    string frequencySort(string s) {
        string res="";
        unordered_map<char,int>mpp;
        for(auto ch:s){
            mpp[ch]++;
        }
        priority_queue<pair<int,char>>maxH;
        for(auto it:mpp){
            maxH.push({it.second,it.first});
        }
        while(!maxH.empty()){
            auto top=maxH.top();
            maxH.pop();
            while(top.first--){
                res+=top.second;
            }
        }
        return res;
    }
};