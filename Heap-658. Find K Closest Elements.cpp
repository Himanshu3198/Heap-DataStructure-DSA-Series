// 658. Find K Closest Elements

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        
        vector<int>res;
        int n=arr.size();
        
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<n;i++){
            
              pq.push({abs(arr[i]-x),arr[i]});
            
              if(pq.size()>k){
                  pq.pop();
              }
        }
        
      while(!pq.empty()){
          
       
          int x=pq.top().second;
             cout<<pq.top().first<<" "<<pq.top().second<<"\n";
          res.push_back(x);
          pq.pop();
      }
        sort(res.begin(),res.end());
        return res ;
    }
};
