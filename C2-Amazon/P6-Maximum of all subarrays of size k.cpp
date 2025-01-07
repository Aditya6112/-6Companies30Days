// Link: https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1

//Brute Force gives TLE TC Passed: (1110 / 1111) 
class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int> res;
        int i=0,j=k-1,n=arr.size();
        while(j<n){
            int maxi=INT_MIN;
            for(int i=j-k+1;i<=j;i++){
                maxi=max(maxi,arr[i]);
            }
            res.push_back(maxi);
            j++;
        }
        return res;
    }
};

//Optimal Approach
class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        priority_queue<pair<int, int>> pq; 
        vector<int> result;
        int n = arr.size(); 

        for (int i = 0; i < k; i++) {
            pq.push({arr[i], i});
        }
        result.push_back(pq.top().first);
        
        for (int i = k; i < n; i++) {
            pq.push({arr[i], i});
            while (pq.top().second <= i - k) {
                pq.pop();
            }
            result.push_back(pq.top().first);
        }
        return result;
    }
};