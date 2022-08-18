class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
         int n=arr.size(),ans=0,tot=0;
         map<int,int>mp;
         for(int i=0;i<n;i++) mp[arr[i]]++;
         priority_queue<int,vector<int>>pq;
         for(auto it:mp) pq.push(it.second);
         while(!pq.empty()){
             tot+=pq.top();
             pq.pop();
             if(tot>=n/2) return ++ans;
             else ans++;
         }
         return ans;
    }
};
