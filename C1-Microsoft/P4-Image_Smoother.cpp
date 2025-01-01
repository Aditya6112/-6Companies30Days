// Link: https://leetcode.com/problems/image-smoother/description/
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int dir_r[]={0,1,1,1,0,-1,-1,-1};
        int dir_c[]={1,1,0,-1,-1,-1,0,1};

        int m=img.size();
        int n=img[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum=img[i][j];
                int total_observation=1;
                for(int k=0;k<8;k++){
                    if(i+dir_r[k]>=0 && i+dir_r[k]<m && j+dir_c[k]>=0 && j+dir_c[k]<n){
                        sum+=img[i+dir_r[k]][j+dir_c[k]];
                        total_observation++;
                    }
                }
                ans[i][j]=floor(sum/total_observation);
            }
        }
        return ans;
    }
};
