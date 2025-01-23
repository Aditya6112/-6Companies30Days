// Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/
class KthLargest {
public:
    int kth;
    priority_queue<int, vector<int>, greater<int>> minH;    
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(auto num:nums){
            add(num);
        }
    }
    
    int add(int val) {
        if(minH.size()<k || minH.top()<val){
            minH.push(val);
            if(minH.size()>k){
                minH.pop();
            }
        }
        return minH.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */