class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
          
          vector<pair<int,int>>nums;
          for(int i=0;i<n;i++)
              nums.push_back({efficiency[i],speed[i]});  // to get mini. effi. at current
        
          sort(nums.begin(),nums.end(),greater<pair<int,int>>());
          priority_queue<int,vector<int>,greater<int>>minHeap;  // to store minSpeed
        
          long long sum=0,res=0,mod=1e9+7;
        
          for(auto [e,s]:nums){
              sum+=s;
              minHeap.push(s);
              if(minHeap.size()>k){
                  int minSpeed=minHeap.top();
                  minHeap.pop();
                  sum-=minSpeed;
              }
              long long ans=(sum*e);
              res=max(res,ans);
          }
          return res%mod;
        
          
          
    }
};
