// Link: https://leetcode.com/problems/stone-game-vi/
class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n=a.size();
        vector<vector<int>>v(n);
        for(int i=0;i<n;i++){
            v[i]={a[i]+b[i],i};
        }
        sort(v.rbegin(),v.rend());
        int f=1;
        int av=0,bv=0;
        for(auto x:v){
            if(f==1)av+=a[x[1]];
            else bv+=b[x[1]];
            f=1-f;
        }
        if(av>bv)return 1;
        if(av==bv)return 0;
        return -1;
    }
};