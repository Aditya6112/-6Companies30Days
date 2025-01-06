// Link: https://leetcode.com/problems/longest-mountain-in-array/description/
class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int len=0;
        if(n<3)return len;
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                int cnt=0;
                int j=i;
                while(j>0 && arr[j]>arr[j-1]){
                    j--;
                    cnt++;
                }
                j=i;
                while(j<n-1 && arr[j]>arr[j+1]){
                    j++;
                    cnt++;
                }
                cnt+=1;
                len=max(len,cnt);
            }
        }
        return len;
    }
};