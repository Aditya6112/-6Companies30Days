// Link: https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/description/
class Solution {
public:
    vector<int> solve(string s,string a){
        vector<int>arr;
        if (s.size() < a.size()) return arr;
        for(int i=0;i<=s.size()-a.size();i++){
            if(s.substr(i,a.size())==a){
                arr.push_back(i);
            }
        }
        return arr;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>pos_of_a=solve(s,a);
        vector<int>pos_of_b=solve(s,b);
        
        vector<int>ans;
        for(int i=0;i<pos_of_a.size();i++){
            for(int j=0;j<pos_of_b.size();j++){
                if(abs(pos_of_a[i]-pos_of_b[j])<=k){
                    ans.push_back(pos_of_a[i]);
                    break;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};