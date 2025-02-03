// Link: https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int max_hCount=1;
        int hCount=1;
        for(int i=0;i<hBars.size()-1;i++){
            if(hBars[i+1]+1==hBars[i]){
                hCount++;
            }else{
                max_hCount=max(max_hCount,hCount);
                hCount=1;
            }
        }

        int max_vCount=1;
        int vCount=1;
        for(int i=0;i<vBars.size()-1;i++){
            if(vBars[i+1]+1==vBars[i]){
                vCount++;
            }else{
                max_vCount=max(max_vCount,vCount);
                vCount=1;
            }
        }

        int ans=min(hCount,vCount)+1;
        return ans*ans;

    }
};