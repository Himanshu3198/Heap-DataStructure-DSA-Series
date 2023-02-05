class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>>nums(nums1.size(),vector<int>(2));
        for(int i=0;i<nums1.size();i++){
            nums[i][0]=nums2[i];
            nums[i][1]=nums1[i];
        }
        sort(nums.rbegin(),nums.rend());
        priority_queue<int,vector<int>,greater<int>>minHeap;
        long long ans=0,sum=0;
        for(auto it:nums){
            sum+=it[1];
            minHeap.push(it[1]);
            if(minHeap.size()>k){
                int top=minHeap.top();
                minHeap.pop();
                sum-=top;
            }
            if(minHeap.size()==k)
            ans=max(ans,sum*it[0]);
        }
    
        return ans;
    }
};
