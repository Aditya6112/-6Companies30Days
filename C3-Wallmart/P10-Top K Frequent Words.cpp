// Link: https://leetcode.com/problems/top-k-frequent-words/

class Solution {
public:
    struct cmp{
        bool operator()(pair<int,string>& A,pair<int,string>& B){
            if(A.first==B.first){
                return A.second>B.second;
            }else{
                return A.first<B.first;
            }
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>res;
        unordered_map<string,int>mpp;
        for(auto str:words){
            mpp[str]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>maxH;
        for(auto it:mpp){
            maxH.push({it.second,it.first});
        }
        while(k--){
            auto top=maxH.top();
            maxH.pop();
            res.push_back(top.second);
        }
        return res;
    }
};