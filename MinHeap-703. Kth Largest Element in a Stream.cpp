//  time complexity O(n) +log(k)
//  space complexity O(k)
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>kthLargest;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(auto it:nums){
            kthLargest.push(it);
            if(kthLargest.size()>k) kthLargest.pop();
        }
    }
    
    int add(int val) {
        kthLargest.push(val);
        if(kthLargest.size()>K) kthLargest.pop();
        return kthLargest.top();  
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
