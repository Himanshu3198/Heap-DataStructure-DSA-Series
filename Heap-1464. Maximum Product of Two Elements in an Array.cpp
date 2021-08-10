// 1464. Maximum Product of Two Elements in an Array

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        priority_queue<int>pq;
        
        for(auto it:nums){
            pq.push(it-1);
        }
        
        int x=pq.top();
        pq.pop();
        int y=pq.top();
        
        pq.pop();
        
        return x*y;
    }
};
