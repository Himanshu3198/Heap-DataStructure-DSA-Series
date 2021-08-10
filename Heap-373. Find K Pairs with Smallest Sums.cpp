// 373. Find K Pairs with Smallest Sums

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<vector<int>>res;
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>
            ,greater<pair<int,pair<int,int>>>>pq;
        
        
        int n=nums1.size(),m=nums2.size();
        for(int i=0;i<min(n,k);i++){
            
            for(int j=0;j<min(m,k);j++){
                
                
              
                    pq.push(make_pair(nums1[i]+nums2[j],make_pair(nums1[i],nums2[j])));
                
            }
        }
        
        

         int cnt=0;
        while(!pq.empty() and  res.size()<k){
            
            vector<int>v;
            v.push_back(pq.top().second.first);
            v.push_back(pq.top().second.second);
            res.push_back(v);
            pq.pop();
            cnt++;
        }
        
        return res;
    }
};
