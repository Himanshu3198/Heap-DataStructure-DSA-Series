
// 347. Top K Frequent Elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
           unordered_map<int,int>mp;
        
        
        for(auto it:nums){
            
                  mp[it]++;
            }

        
        vector<int>ans;
    
    
        for(auto it:mp){
            
            
            pq.push(make_pair(it.second,it.first));
            
            while(pq.size()>k){
                pq.pop();
            }
        }
        
        while(!pq.empty()){
            
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
